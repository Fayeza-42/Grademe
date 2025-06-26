#include "sort_list.h"
#include <stdlib.h>
#include <stdio.h>

void	swap(t_list *a, t_list *b)
{
	int swap = a->data;
	a->data = b->data;
	b->data = swap;
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    t_list *cur = lst;
    t_list *temp = lst;
    if(!lst)
        return (NULL);
        
    while(cur != 0 && cur->next != 0)
    {
        if(cmp(cur->data, cur->next->data) == 0)
        {
            swap(cur, cur->next);
            cur = temp;
        }
        else
            cur = cur->next;
    }
    return (lst);
}

// int ascending_order(int a, int b) {
//     return (a <= b);
// }

// int main(void) {
//     t_list *head = malloc(sizeof(t_list));
//     head->data = 3;
//     head->next = malloc(sizeof(t_list));
//     head->next->data = 1;
//     head->next->next = malloc(sizeof(t_list));
//     head->next->next->data = 2;
//     head->next->next->next = NULL;

//     printf("Before sorting: ");
//     t_list *current = head;
//     while (current) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");

//     head = sort_list(head, ascending_order);

//     printf("After sorting: ");
//     current = head;
//     while (current) {
//         printf("%d ", current->data);
//         current = current->next;
//     }
//     printf("\n");

//     // Free memory
//     current = head;
//     while (current) {
//         t_list *next = current->next;
//         free(current);
//         current = next;
//     }

//     return 0;
// }