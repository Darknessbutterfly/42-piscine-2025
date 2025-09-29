#include <stdio.h>
#include <unistd.h>

int str_in_base(char* str, char* base, int len_base);
int is_valid_base(char* base, int len_base);
int str_to_int(char* str, char* base, int len_base);
int digit_to_pos(char c, char* base);

int ft_atoi_base(char* str, char* base)
{
    int len_base;

    len_base = 0;
  
    while (base[len_base])
        len_base++;

  
    if (str_in_base(str, base, len_base) == 0 || 
        !is_valid_base(base, len_base))
        return (0);

   
    return (str_to_int(str, base, len_base));
}

int digit_to_pos(char c, char* base)
{
    int j;

    j = 0;
    while (base[j])
    {
        if (c == base[j])
            return (j);
        j++;
    }
    return (-1); 
}

int str_to_int(char* str, char* base, int len_base)
{
    int sign;
    int result;
    int pos;

    sign = 0;
    result = 0;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    while (*str)
    {
        pos = digit_to_pos(*str, base);
        if (pos == -1) 
            return 0;
        result = result * len_base + pos;
        str++;
    }
    return (result * sign);
}

int is_valid_base(char* base, int len_base)
{
    int i;
    int j;

    i = 0;
    if (len_base <= 1)
        return (0);
    while (base[i])
    {
        if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
            return (0);
        j = 0;
        while (base[j])
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int str_in_base(char* str, char* base, int len_base)
{
    if (*str == '-')
        str++;
    while (*str)
    {
        while (*base)
        {
            if (*str != *base)
                return (0);
            base++;
        }
        base -= len_base;
        str++;
    }
    return (1);
}

int main(void) {
    printf("11, \"01\": %d\n", ft_atoi_base("11", "01"));
    printf("11, \"01234567\": %d\n", ft_atoi_base("11", "01234567"));
    printf("11, \"poneyvif\": %d\n", ft_atoi_base("11", "poneyvif"));
    printf("11, \"0123456789\": %d\n", ft_atoi_base("11", "0123456789"));
    printf("11, \"0123456789abcdef\": %d\n\n", ft_atoi_base("11", "0123456789abcdef"));

    printf("-2147483648, \"01\": %d\n", ft_atoi_base("-2147483648", "01"));
    printf("-2147483648, \"01234567\": %d\n", ft_atoi_base("-2147483648", "01234567"));
    printf("-2147483648, \"poneyvif\": %d\n", ft_atoi_base("-2147483648", "poneyvif"));
    printf("-2147483648, \"0123456789\": %d\n", ft_atoi_base("-2147483648", "0123456789"));
    printf("-2147483648, \"0123456789abcdef\": %d\n\n", ft_atoi_base("-2147483648", "0123456789abcdef"));

    return (0);
}
