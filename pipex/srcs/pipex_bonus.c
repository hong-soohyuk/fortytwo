/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/07 17:16:42 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	process_command(char *command, char **envp)
{
	int		pipe_fd[2];
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
		waitpid(pid, NULL, 0);
	}
}

void	here_doc(char *limiter, int argc)
{
	int		pipe_fd[2];
	pid_t	pid;
	char	*read_line;

	if (argc < 6)
		throw_error("wrong heredoc argument", 1);
	if (pipe(pipe_fd) == -1)
		throw_error("pipe error", 1);
	pid = fork();
	if (pid == -1)
		throw_error("process fork fail", 1);
	else if (pid == 0)
	{
		close(pipe_fd[0]);
		read_line = get_next_line(0);
		while (read_line)
		{
			if (ft_strcmp(read_line, limiter) == 0)
			{
				free(limiter);
				free(read_line);
				exit(EXIT_SUCCESS);
			}
			write(pipe_fd[1], read_line, ft_strlen(read_line));
			free(read_line);
			read_line = get_next_line(0);
		}
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		wait(NULL);
	}
}

void le()
{
	system("leaks pipex_bonus");
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd_infile;
	int	fd_outfile;
	int	i;

	atexit(le);

	if (argc < 5)
		throw_error("arguments error", 1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		here_doc(ft_strjoin(argv[2], "\n"), argc);
		fd_outfile = open_file(argv[argc - 1], 0);
		if (fd_outfile == -1)
			throw_error("fail to open outfile.", 1);
		i = 3;
	}
	else
	{
		fd_infile = open_file(argv[1], 2);
		fd_outfile = open_file(argv[argc - 1], 1);
		if (fd_infile == -1 || fd_outfile == -1)
			throw_error("fail to open files.", 1);
		if (dup2(fd_infile, STDIN_FILENO) == -1)
			throw_error("fail on redirection not heredoc", 1);
		i = 2;
	}
	while (i < argc - 2)
		process_command(argv[i++], envp);
	if (dup2(fd_outfile, STDOUT_FILENO) == -1)
		throw_error("fail on redirection in last file", 1);
	close(fd_infile);
	close(fd_outfile);
	execute_command(argv[argc - 2], envp);
	return (0);
}
