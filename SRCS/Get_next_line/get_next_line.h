/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tverdood <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:24:11 by tverdood          #+#    #+#             */
/*   Updated: 2022/02/24 12:24:30 by tverdood         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

char	*ft_error(char *tmp);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*get_nl(int fd, char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*trim_buffer(char *buff);
int		check_for_line_break(char *buffer);
char	*ft_strdup_line(char *src);
char	*ft_bzero(char *s, int n);
char	*ft_strdup(char *src);

#endif