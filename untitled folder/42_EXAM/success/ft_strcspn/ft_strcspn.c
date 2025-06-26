#include <stdlib.h>

int    ft_search(const char *s, const char c)
{
    int i = 0;
    while(s[i])
    {
        if(s[i] == c)
            return (1);
        i++;
    }
    return (0);
}


size_t	ft_strcspn(const char *s, const char *reject)
{
    if (!s || !reject)
        return (0);
    int i = 0;
    while (s[i])
    {
        if(ft_search(reject, s[i]) == 1)
            return (i);
        i++;
    }
    return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
//     const char *str = "tttttest";
//     const char *reject = "es";

//     // Test ft_strcspn
//     size_t result = ft_strcspn(str, reject);
//     size_t result1 = strcspn(str, reject);
//     // Print the result
//     printf("Length of initial segment without characters in reject: %zu\n", result);
//     printf("Length of initial segment without characters in reject: %zu\n", result1);

//     return 0;
// }