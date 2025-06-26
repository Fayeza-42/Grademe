
int    ft_strcmp(char *s1, char *s2)
{
    if (!s1 || !s2)
        return (0);
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (s1[i] - s2[i]);
}

// #include <stdio.h>  // for printf
// #include <string.h>
// int ft_strcmp(char *s1, char *s2);

// int main() {
//     // Test cases
//     char *str1 = "Hello";
//     char *str2 = "";

//     // Compare strings using ft_strcmp
//     int result1 = ft_strcmp(str1, str2);
//     int result2 = strcmp(str1, str2);

//     printf("%d", result1);
//     printf("%d", result2);
//     return 0;
// }
