/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/03 17:11:16 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process(char *infile, char *cmd, int *pipe_fd, char **envp)
{
	int	in_fd;

	close(pipe_fd[0]);
	in_fd = open(infile, O_RDONLY, 0777);
	if (dup2(in_fd, STDIN_FILENO) == -1)
		throw_error("fail on redirection", 1);
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		throw_error("fail on redirection", 1);
	execute_command(cmd, envp);
}

void	parent_process(char *outfile, char *cmd, int *pipe_fd, char **envp)
{
	int	out_fd;

	close(pipe_fd[1]);
	out_fd = open(outfile, O_RDWR | O_CREAT, 0644);
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		throw_error("fail on redirection", 1);
	if (dup2(out_fd, STDOUT_FILENO) == -1)
		throw_error("fail on redirection", 1);
	execute_command(cmd, envp);
}
// argc - 3 = num of cmds = num of children
// pipe 2개 번갈아가면서, 
int	main(int argc, char *argv[], char *envp[])
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
