/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pharmund <pharmund@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:57:37 by pharmund          #+#    #+#             */
/*   Updated: 2022/02/14 12:57:30 by pharmund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	etrim_extra(int *begin, int *i)
{
	*begin = 0;
	*i = 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		begin;
	int		end;
	int		i;

	etrim_extra(&begin, &i);
	if (s1 == NULL)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && check_set(s1[begin], set) == 1)
		begin++;
	while (end > begin && check_set(s1[end - 1], set))
		end--;
	new = malloc (sizeof(char) * (end - begin + 1));
	if (new == NULL)
		return (NULL);
	while (begin < end)
	{
		new[i] = s1[begin];
		i++;
		begin++;
	}
	free((char *)s1);
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new || !(s2))
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
		free(s1);
	}
	if (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}
