
#include <stdlib.h>

int     *ft_range(int start, int end)
{
    int i;
    int *array;
    if(start > end)
        i = start - end + 1;
    else if(end > start)
        i = end - start + 1;
    else 
        i = 0;
    array = (int *)malloc (sizeof(int) * i + 1);
    if(!array)
        return(NULL);
    array[i + 1] = '\0';
    i = 0;
    if(start > end)
    {
        while(start >= end)
        {
            array[i++] = start;
            start--;
        }
    }
    if(end > start)
    {
        while(end >= start)
        {
            array[i++] = start;
            start++;
        }
    }
    return(array);
}

// #include <stdio.h>
// #include <stdlib.h>

// int *ft_range(int start, int end);

// int main(void) {
//     int *result;

//     // Example 1: start < end
//     result = ft_range(-5, 1);
//     if (result) {
//         for (int i = 0; result[i] != '\0'; i++) {
//             printf("%d ", result[i]);
//         }
//         free(result);
//         printf("\n");
//     }

//     // Example 2: start > end
//     result = ft_range(5, 1);
//     if (result) {
//         for (int i = 0; result[i] != '\0'; i++) {
//             printf("%d ", result[i]);
//         }
//         free(result);
//         printf("\n");
//     }

//     // Example 3: start == end
//     result = ft_range(3, 3);
//     if (result) {
//         for (int i = 0; result[i] != '\0'; i++) {
//             printf("%d ", result[i]);
//         }
//         free(result);
//         printf("\n");
//     }

//     return 0;
// }
