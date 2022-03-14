/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:22:09 by tverdood          #+#    #+#             */
/*   Updated: 2022/02/28 14:19:30 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_for_line_break(char *buffer)
{
	int	i;

	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = ft_strdup("");
		if (!s1)
			return (NULL);
	}
	if (!s2)
		return (ft_error(s1));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*trim_buffer(char *buffer)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	j = ft_strlen(buffer) - i;
	if (j <= 0)
		return (ft_error(buffer));
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (ft_error(buffer));
	i += 1;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	free(buffer);
	return (str);
}

char	*get_nl(int fd, char *buffer)
{
	char	*buff;
	int		i;

	i = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (check_for_line_break(buffer) == -1 && i != 0)
	{
		ft_bzero(buff, BUFFER_SIZE + 1);
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (ft_error(buff));
		if (i == 0)
		{
			ft_error(buff);
			return (buffer);
		}
		buff[i] = '\0';
		buffer = ft_strjoin(buffer, buff);
		if (!buffer)
			return (ft_error(buffer));
	}
	free(buff);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (ft_error(0));
	buffer = get_nl(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_strdup_line(buffer);
	buffer = trim_buffer(buffer);
	if (line && !*line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}