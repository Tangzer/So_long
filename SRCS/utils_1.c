/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 16:23:32 by tverdood          #+#    #+#             */
/*   Updated: 2022/04/13 17:13:09 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
}

void	check_if_empty_first_line(char *line)
{
	if (line[0] == '\n')
	{
		ft_printf("Error : La map n'est pas homologuée.\n");
		exit(EXIT_SUCCESS);
	}
}

char	*init_res(char *res, char *line)
{
	res = ft_strjoin(res, line);
	if (!res)
		exit(EXIT_SUCCESS);
	return (res);
}

void	ft_parsing_fichier(char **argv)
{
	int	x;
	int	fd;

	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] != 'r' || argv[1][x - 1] != 'e' || argv[1][x - 2] != 'b' ||
		argv[1][x - 3] != '.')
	{
		ft_printf("Error : Format of map file must be '.ber'\n");
		exit(EXIT_SUCCESS);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error : Les droits de lecture du fichier ne sont pas bon\n");
		exit(EXIT_SUCCESS);
	}
	close(fd);
}
