#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <stdio.h>
#include <stdlib.h>

int ids[65301];
char *msgs[65301];
int maxfd, client_count = 0;
fd_set read_set, write_set, curr_set;
char buf_read[1001], buf_write[42];

int extract_message(char **buf, char **msg)
{
	char *newbuf;
	int i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char *newbuf;
	int len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

void send_to_all(int except, char *msg)
{
	for (int fd = 0; fd <= maxfd; fd++)
	{
		if (FD_ISSET(fd, &curr_set) && fd != except)
			send(fd, msg, strlen(msg), 0);
	}
}
void accept_client(int fd)
{
	if (fd > maxfd)
		maxfd = fd;
	ids[fd] = client_count++;
	msgs[fd] = NULL;
	FD_SET(fd, &curr_set);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
	send_to_all(fd, buf_write);
}
void remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	send_to_all(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &curr_set);
	close(fd);
}
void send_msg(int fd)
{
	char *str;
	while (extract_message(&msgs[fd], &str))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		send_to_all(fd, buf_write);
		send_to_all(fd, str);
		free(str);
	}
}
void fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}
	FD_ZERO(&read_set);
	FD_ZERO(&write_set);
	FD_ZERO(&curr_set);
	int sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
	{
		printf("socket creation failed...\n");
		exit(0);
	}
	FD_SET(sockfd, &curr_set);
	maxfd = sockfd;
	struct sockaddr_in servaddr;


	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); // 127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	// Binding newly created socket to given IP and verification
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))))
	{
		printf("socket bind failed...\n");
		exit(0);
	}
	
	if (listen(sockfd, 100))
	{
		fatal_error();
	}
	while (1)
	{
		read_set = write_set = curr_set;
		if (select(maxfd + 1, &read_set, &write_set, 0, 0) < 0)
			fatal_error();
		for (int fd = 0; fd <= maxfd; fd++)
		{
			if (!FD_ISSET(fd, &read_set))
			{
				continue;
			}
			if (fd == sockfd)
			{
				socklen_t len;
				int clientfd = accept(sockfd, (struct sockaddr *)&servaddr, &len);
				if (clientfd >= 0)
				{
					accept_client(clientfd);
					break;
				}
			
				
			}
			else
			{
				int ret = recv(fd, buf_read, 1000, 0);
				if (ret <= 0)
				{
					remove_client(fd);
					break;
				}
				buf_read[ret] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
			}
		}
		
	}
	return (0);
}