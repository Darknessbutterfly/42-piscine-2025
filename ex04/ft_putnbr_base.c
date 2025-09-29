
#include <unistd.h>
int legal_base_check(char* base)
{
    int i;
    int j;

    i = 0;
   
    if (base[0] == '\0' || base[1] == '\0')
        return (0);
    while (base[i]) 
    {
        j = 0;
        while (base[j])
        {
            if (i != j && base[i] == base[j])
                return (0);
            j++;
        }
        if (base[i] == '+' || base[i] == '-')
            return (0);
        if (base[i] < 32 || base[i] > 126)
            return (0);
        i++;
    }
    return (1);
}
void	ft_putchar(char c)
{
    write(1, &c, 1);
}
void	ft_putnbr_base(int nbr, char* base)
{
    int i;
    int	base_size;
    int	nbr_str[500];

    i = 0;
    base_size = 0;
    if (legal_base_check(base))
    {
        if (nbr < 0)
        {
            nbr = -nbr;
            ft_putchar('-');
        }
        while (base[base_size])
            base_size++;
        while (nbr)
        {
            nbr_str[i] = nbr % base_size;
            nbr = nbr / base_size;
            i++;
        }
        while (i-- > 0)
            ft_putchar(base[nbr_str[i]]);
    }
}

#include <stdio.h>

int main() {
    char my_base[] = "QUER(Y)O@";
    ft_putnbr_base(42, my_base);
    printf("\n");
    printf("my_base %s : %d\n", my_base, legal_base_check(my_base));
    printf("\n");
    return 0;
}