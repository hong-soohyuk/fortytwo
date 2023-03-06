/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/06 20:45:17 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <unistd.h>

void	process_command(char *command, char **envp)
{
	int		pipe_fd[2];
	int		status;
	pid_t	pid;

	if (pipe(pipe_fd) == -1)
		throw_error("pipe error", 1);
	pid = fork();
	if (pid == -1)
		throw_error("process fork fail", 1);
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
			throw_error("fail on redirection pid == 0", 1);
		execute_command(command, envp);
	}
	else
	{
		close(pipe_fd[1]);
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			throw_error("fail on redirection  pid > 0", 1);
		waitpid(pid, &status, 0);
	}
}

void	last_process(char *outfile, char *cmd, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(outfile, O_RDWR | O_CREAT | O_TRUNC , 0644);// if (heredoc) O_APPEND else O_TRUNC
	if (fd_outfile == -1)
		throw_error("fail on opening outfile", 1);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		throw_error("fail on redirection in last file", 1);
	execute_command(cmd, envp);
}

void	here_doc(char *limiter, int argc)
{
	int		pipe_fd[2];
	// pid_t	pid;
	char	*read_line;

	if (argc < 6)
		throw_error("wrong heredoc argument", 1);
	if (pipe(pipe_fd) == -1)
		throw_error("pipe error", 1);

	close(pipe_fd[0]);
	read_line = get_next_line(0);
	while (read_line && ft_strcmp(read_line, limiter) != 0)
	{
		read_line = get_next_line(0);
		write(pipe_fd[1], read_line, ft_strlen(read_line));
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_infile;
	int	i;
	
	if (argc < 5)
		throw_error("arguments error", 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		here_doc(argv[2], argc);
		i = 3;
	}
	else
	{
		fd_infile = open(argv[1], O_RDONLY, 0777);
		if (dup2(fd_infile, STDIN_FILENO) == -1)
			throw_error("fail on redirection not heredoc", 1);
		i = 2;
	}
	while (i < argc - 2)
		process_command(argv[i++], envp);
	last_process(argv[argc - 1], argv[argc - 2], envp);
	return (0);
}
