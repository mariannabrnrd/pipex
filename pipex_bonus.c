/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:50:44 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/05 13:50:47 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	int	infile;
	int	outfile;
	int	fd;
	int	i;

	infile = -1;
	if (ac < 5)
		ft_error_args();
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		i = 3;
		ft_heredoc(ac, av[2], &outfile, av[ac - 1]);
	}
	else
	{
		i = 2;
		infile = ft_file(av[1], 1);
		outfile = ft_file(av[ac - 1], 2);
		dup2(infile, STDIN_FILENO);
	}
	while (i < ac - 2)
		fd = ft_child_process(av[i++], ev);
	dup2(outfile, STDOUT_FILENO);
	ft_last_child(av[ac - 2], ev);
	return (ft_close(fd, infile, outfile), 0);
}

int	ft_child_process(char *av, char **ev)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		ft_exec_cmd(av, ev);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
	return (-1);
}

void	ft_last_child(char *av, char **ev)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_error();
	if (pid == 0)
		ft_exec_cmd(av, ev);
	else
		waitpid(pid, NULL, 0);
}

void	ft_heredoc(int ac, char *eof, int *outfile, char *filename)
{
	if (ac < 6)
		ft_error_args();
	*outfile = ft_file(filename, 3);
	ft_child_heredoc(eof);
}

void	ft_child_heredoc(char *eof)
{
	char	*line;
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		ft_error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (get_line(&line))
		{
			if (ft_strncmp(line, eof, ft_strlen(eof)) == 0)
				exit(0);
			write(fd[1], line, ft_strlen(line));
		}
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}
