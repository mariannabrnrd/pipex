/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:44:33 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/04 12:44:35 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(void)
{
	perror("Error");
	exit(1);
}

void	ft_exec_cmd(char *av, char **ev)
{
	char	**cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(av, ' ');
	path = ft_search_path(cmd[0], ev);
	if (!path)
	{
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		ft_error();
	}
	if (execve(path, cmd, ev) == -1)
		ft_error();
}

char	*ft_search_path(char *cmd, char **ev)
{
	char	**all_paths;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	while (ft_strnstr(ev[i], "PATH", 4) == 0)
		i++;
	all_paths = ft_split(ev[i] + 5, ':');
	i = 0;
	while (all_paths[i])
	{
		temp = ft_strjoin(all_paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (full_path && access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	i = 0;
	while (all_paths[i])
		free(all_paths[i++]);
	free(all_paths);
	return (0);
}

int	ft_file(char *filename, int flag)
{
	int	fd;

	fd = 0;
	if (flag == 1)
		fd = open(filename, O_RDONLY);
	else if (flag == 2)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (flag == 3)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		ft_error();
	if (fd == -1)
		ft_error();
	return (fd);
}

void	ft_error_args(void)
{
	ft_putstr_fd("Error: Bad argument\n", 2);
	exit(1);
}
