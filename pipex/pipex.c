/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/02/03 23:52:48 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *infile, char *cmd, int *pipe_fd, char **envp)
{}

void	parent_process(char *infile, char *cmd, int *pipe_fd, char **envp)
{}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid;
	pid_t	wait_pid;

	if (argc != 5)
		throw_error("argument error", 1);
	else
	{
		if (pipe(pipe_fd) == -1)
			throw_error("pipe error", 1);
		pid = fork();
		if (pid == 0)
			child_process(argv[1], argv[2], pipe_fd, envp);
		else if (pid > 0)
		{
			wait_pid = waitpid(pid, &status, WNOHANG);
			parent_process(argv[4], argv[3], pipe_fd, envp);
		}
		else
			throw_error("process fork fail", 1);
	}
	return (0);
}
