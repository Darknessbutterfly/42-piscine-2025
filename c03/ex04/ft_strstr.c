#include <stdio.h>

char* ft_strstr(char* str, char* to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
		}
		if (to_find[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
		j = 0;
	}
	return (0);
}
int	main(void)
{
	char	str[] = "Hello World!";
	char	to_find[] = "Wo";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}