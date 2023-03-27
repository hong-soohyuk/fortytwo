/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/23 13:01:28 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *infile, char *cmd, int *pipe_fd, char **envp)
{
	int	fd_infile;

	close(pipe_fd[0]);
	fd_infile = open(infile, O_RDONLY, 0777);
	if (fd_infile == -1)
		throw_error("fail on opening infile", 1);
	if (dup2(fd_infile, STDIN_FILENO) == -1)
		throw_error("fail on redirection", 1);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		throw_error("fail on redirection", 1);
	execute_command(cmd, envp);
}

void	parent_process(char *outfile, char *cmd, int *pipe_fd, char **envp)
{
	int	fd_outfile;

	close(pipe_fd[1]);
	fd_outfile = open(outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
		throw_error("fail on opening outfile", 1);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		throw_error("fail on redirection", 1);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		throw_error("fail on redirection", 1);
	execute_command(cmd, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		pipe_fd[2];
	pid_t	pid;

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
			waitpid(pid, NULL, WNOHANG);
			parent_process(argv[4], argv[3], pipe_fd, envp);
		}
		else
			throw_error("process fork fail", 1);
	}
	return (0);
}
