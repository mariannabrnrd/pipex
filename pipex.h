/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 12:44:19 by mariaber          #+#    #+#             */
/*   Updated: 2025/06/04 12:44:25 by mariaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

/* pipex */
void	ft_first_child(char **av, char **ev, int *fd);
void	ft_second_child(char **av, char **ev, int *fd);
int		ft_child_process(char *av, char **ev);
void	ft_last_child(char *av, char **ev);
void	ft_heredoc(int ac, char *eof, int *outfile, char *filename);
void	ft_child_heredoc(char *eof);

/* utils */
void	ft_error(void);
void	ft_error_args(void);
void	ft_exec_cmd(char *av, char **ev);
void	ft_wait(pid_t pid1, pid_t pid2);
char	*ft_search_path(char *cmd, char **ev);
int		ft_file(char *filename, int flag);
int		get_line(char **line);
void	ft_close(int fd, int infile, int outfile);
int		ft_strcmp(char *s1, char *s2);
void	ft_child_helper(char *eof, int fd);
#endif
