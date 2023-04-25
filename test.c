#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libft.h"

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char       *d;
    const unsigned char *s;

    d = dest;
    s = src;
    while (n-- > 0)
        *d++ = *s++;
    return (dest);
}

int main(void)
{
    char dest1[20];
    char dest2[20];
    char src[] = "Hello World!";
    size_t n;

    // Test 1: n > strlen(src)
    n = 15;
    memcpy(dest1, src, n);
    ft_memcpy(dest2, src, n);
    printf("Test 1: n > strlen(src)\n");
    printf("memcpy   : %s\n", dest1);
    printf("ft_memcpy: %s\n", dest2);

    // Test 2: dest == NULL
    memcpy(NULL, src, n);
    ft_memcpy(NULL, src, n);
    printf("Test 2: dest == NULL\n");
    printf("memcpy   : %s\n", "Segmentation fault");
    printf("ft_memcpy: %s\n", "Segmentation fault");

    // Test 3: src == NULL
    memcpy(dest1, NULL, n);
    ft_memcpy(dest2, NULL, n);
    printf("Test 3: src == NULL\n");
    printf("memcpy   : %s\n", "Segmentation fault");
    printf("ft_memcpy: %s\n", "Segmentation fault");

    // Test 4: dest and src overlap
    memcpy(src + 2, src, 5);
    ft_memcpy(src + 2, src, 5);
    printf("Test 4: dest and src overlap\n");
    printf("memcpy   : %s\n", src);
    printf("ft_memcpy: %s\n", src);
    return (0);
}