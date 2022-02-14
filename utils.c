/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:30 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:34 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n != 0)
	{
		while (n > 0)
		{
			((char *)s)[i] = '\0';
			++i;
			--n;
		}
	}
	else
		return ;
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0')
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		++i;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*bytes;

	bytes = malloc(size * count);
	if (bytes == NULL)
		return (bytes);
	ft_bzero(bytes, size * count);
	return (bytes);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;

	i = 0;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n == 0)
		write (fd, "0", 1);
	if (n < 0 && n != -2147483648)
	{
		write(fd, "-", 1);
		n = n * -1;
	}
	while (n > 0)
	{
		s[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &s[i], 1);
		i--;
	}
}
