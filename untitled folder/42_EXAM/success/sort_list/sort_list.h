#ifndef SORT_LIST_H
# define SORT_LIST_H

typedef struct  s_list
{
    int     data;
    struct s_list  *next;
}   t_list;

void	swap(t_list *a, t_list *b);


#endif