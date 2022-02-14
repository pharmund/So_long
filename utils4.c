/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:52 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:20 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = malloc(ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	str[ft_strlen(s1)] = '\0';
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}

int	length_str(int n)
{
	int	nbr;
	int	len;
	int	f;

	nbr = n;
	len = 0;
	f = 0;
	if (n < 0)
	{
		nbr = nbr * -1;
		f = -1;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		len++;
	}
	if (n == 0)
		return (1);
	return (len - f);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		i;

	i = -1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = length_str(n);
	str = (char *)malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}	
	while (n > 0 && ++i >= 0)
	{
		str[len - i - 1] = (n % 10) + '0';
		n = n / 10;
	}
	str[len] = '\0';
	return (str);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
