#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char *ft_skip(char *s, char c);
int ft_strlen (char *s);
char *ft_read(int fd);
char *ft_strjoin(char *a, char *b);
char *ft_substr(char *s, char c);


char *get_next_line(int fd)
{
    char *line = NULL;
    static char *next;

    if (fd < 0 || BUFFER_SIZE < 1)
    {
        free (next);
        next = NULL;
        return (NULL);
    }
    if (!next)
        next = ft_read(fd);
    if (!next)
        return(NULL);
    line = ft_substr (next, '\n');
    if (!line)
        return (free (next), NULL);
    next = ft_skip(next, '\n');
    return (line);
}

int ft_strlen (char *s)
{
    int i = 0;
    while (s && s[i])
        i++;
    return (i);
}

char *ft_read(int fd)
{
    char *s  =NULL;
    char *buffer = NULL;
    int bytes;

    buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    while (1)
    {
        bytes = read(fd, buffer, BUFFER_SIZE);
        if (bytes < 1)
            break;
        buffer[bytes] = '\0';
        s = ft_strjoin(s, buffer);
        if (!s)
            return (free (buffer), NULL);
    }
    free (buffer);
    buffer = NULL;
    if (bytes < 0)
        return (free (s), NULL);
    return (s);
}

char *ft_strjoin(char *a, char *b)
{
    char *s = NULL;
    int i = 0;
    if (!b)
        return(a);
    s = malloc(sizeof(char) * (ft_strlen(a) + ft_strlen (b) + 1));
    if (!s)
        return (free (a), NULL);
    while (a && a[i])
    {
        s[i] = a[i];
        i++;
    }
    free (a);
    a = NULL;
    while (b && *b)
    {
        s[i] = *b;
        i++;
        b++;
    }
    s[i] = '\0';
    return (s);
    
}

char *ft_substr(char *s, char c)
{
    char *a = NULL;
    int i = 0;
    if (!s)
        return(NULL);
    while (s[i] && s[i] != c)
        i++;
    if (s[i] && s[i] == c)
        i++;
    a = malloc (sizeof(char) * (i + 1));
    if (!a)
        return (NULL);
    i = 0;
    while (s[i] && s[i] != c)
    {
        a[i] = s[i];
        i++;
    }
    if (s[i] && s[i] == c)
        a[i++] = c;
    a[i] = '\0';
    return(a);
    
}
char *ft_skip(char *s, char c)
{
    char *trash;
    char *a = NULL;
    int i = 0;
    if (!s)
        return(NULL);
    trash = s;
    while (*s && *s != c)
        s++;
    if (*s && *s == c)
        s++;
    a = malloc (sizeof(char) * (ft_strlen(s) + 1));
    if (!a)
        return (free (trash), NULL);
    while (s[i])
    {
        a[i] = s[i];
        i++;
    }
    a[i] = '\0';
    free(trash);
    trash = NULL;
    if (ft_strlen(a) == 0)
        return(free(a), NULL);
    return (a);
}



// #include <fcntl.h>
// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//  char *line = NULL;
//  int fd;

//  fd = open("test.txt", O_RDONLY);
//  while (1)
//  {
//      line = get_next_line(fd);
//      printf("%s", line);
//      if (!line)
//          break ;
//      free(line);
//      line = NULL;
//  }
//  close(fd);
//  return (0);
// }