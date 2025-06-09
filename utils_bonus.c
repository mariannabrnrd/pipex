/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:24 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/05 13:50:33 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1 && s2 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	get_line(char **line)
{
	int		byte_read;
	char	*temp;
	char	c;
	int		i;

	i = 0;
	byte_read = 0;
	temp = (char *)malloc(10000);
	if (!temp)
		return (-1);
	byte_read = read(0, &c, 1);
	while (byte_read && (c != '\n' && c != '\0'))
	{
		temp[i] = c;
		i++;
		byte_read = read(0, &c, 1);
	}
	temp[i++] = '\n';
	temp[i] = '\0';
	*line = temp;
	return (byte_read);
}

void	ft_child_helper(char *eof, int fd)
{
	char	*line;

	while (get_line(&line))
	{
		if (ft_strncmp(line, eof, ft_strlen(line) - 1) == 0)
		{
			free(line);
			close(fd);
			exit(0);
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

void	ft_close(int fd, int infile, int outfile)
{
	if (fd != -1)
		close(fd);
	if (infile != -1)
		close(infile);
	if (outfile != -1)
		close(outfile);
}
