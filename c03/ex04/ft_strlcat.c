/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mganbat <mganbat@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:54:05 by mganbat           #+#    #+#             */
/*   Updated: 2023/06/14 14:47:05 by mganbat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlen(char* str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char* dest, char* src, unsigned int size)
{
	unsigned int	len_d;
	unsigned int	len_s;
	unsigned int	result;
	unsigned int	i;

	len_d = ft_strlen(dest);
	len_s = ft_strlen(src);
	result = 0;
	if (size > len_d)
		result = len_s + len_d;
	else
		result = len_s + size;
	i = 0;
	while (src[i] && len_d <= size)
	{
		dest[len_d] = src[i];
		len_d++;
		i++;
	}
	dest[len_d] = '\0';
	return (result);
}

int main() {
	char destin[20] = "Hello";
	char source[20] = ", world!";
	unsigned int result = ft_strlcat(destin, source, 1);
	printf("Result: %s\n", destin);
	printf("Length: %d\n", result);
	return (0);
}