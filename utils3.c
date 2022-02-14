/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:45 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:25 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	words(char const *s, char c)
{
	int	flag;
	int	i;
	int	words;

	flag = 1;
	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 1;
		if (s[i] != c && flag == 1)
		{
			words++;
			flag = 0;
		}	
		i++;
	}
	return (words);
}

int	mem(char **new, char const *s, char c, int flag)
{
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			len++;
			flag = 0;
		}	
		if (s[i] == c || s[i + 1] == '\0')
			flag = 1;
		if (len > 0 && flag == 1)
		{
			*new = (char *) ft_calloc (sizeof(char), (len + 1));
			if (!(*new))
				return (1);
			new++;
			len = 0;
		}
	}
	return (0);
}

void	full(char **new, char *s, char c)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 1;
	while (*s != '\0')
	{
		if (*s != c)
		{
			flag = 0;
			new[i][j] = *s;
			j++;
		}
		if (*s == c && flag == 0)
		{
			flag = 1;
			i++;
			j = 0;
		}
		s++;
	}
}

char	**cleaner(char	**new)
{
	while (*new)
	{
		free(*new);
		new++;
	}
	free(new);
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		word;
	int		flag;

	flag = 1;
	if (s == NULL)
		return (NULL);
	word = words(s, c);
	new = (char **)malloc (sizeof(char *) * (word + 1));
	if (!new)
		return (NULL);
	new[word] = NULL;
	if (word == 0)
		return (new);
	if (mem(new, s, c, flag) == 1)
	{
		return (cleaner(new));
	}	
	full(new, (char *) s, c);
	return (new);
}
