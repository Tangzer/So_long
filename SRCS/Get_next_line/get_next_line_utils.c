/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:25:23 by tverdood          #+#    #+#             */
/*   Updated: 2022/02/28 14:38:10 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_error(char *tmp)
{
	if (tmp)
		free(tmp);
	return (NULL);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup_line(char *src)
{
	char	*duplicate;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i] && src[i] != '\n')
		i++;
	if (src[i] == '\n')
		i++;
	duplicate = malloc(sizeof(char) * i + 1);
	if (!duplicate)
		return (NULL);
	while (j < i)
	{
		duplicate[j] = src[j];
		j++;
	}
	duplicate[j] = '\0';
	return (duplicate);
}

char	*ft_bzero(char *s, int n)
{
	int		i;

	if (n == 0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

char	*ft_strdup(char *src)
{
	char	*duplicate;
	int		i;

	duplicate = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!duplicate)
		return (NULL);
	i = 0;
	while (src[i])
	{
		duplicate[i] = src[i];
		i++;
	}
	duplicate[i] = '\0';
	return (duplicate);
}
