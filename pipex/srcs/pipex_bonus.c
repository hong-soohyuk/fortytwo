/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/09 18:20:16 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	process_command(char *command, char **envp)
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

static int	open_file(char *filename, int option)
{
	int	fd;

	if (option == 0)
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (option == 1)
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (option == 2)
		fd = open(filename, O_RDONLY, 0777);
	else
		fd = -1;
	return (fd);
}

static int	here_doc(char *limiter, int argc)
{
	int		fd;
	char	*read_line;

	if (argc < 6)
		throw_error("wrong heredoc argument", 1);
	fd = open_file(HERE_DOC_NAME, 0);
	if (fd == -1)
		throw_error("fail to open temp heredoc file", 1);
	read_line = get_next_line(0);
	while (read_line && ft_strcmp(read_line, limiter) != 0)
	{
		write(fd, read_line, ft_strlen(read_line));
		free(read_line);
		read_line = get_next_line(0);
	}
	free(limiter);
	free(read_line);
	close(fd);
	return (open_file(HERE_DOC_NAME, 2));
}

static int	configure_fds(int argc, char *argv[], int *here_doc_mode)
{
	int	fd_infile;
	int	fd_outfile;
	int	argument_index;

	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		*here_doc_mode = 1;
		fd_infile = here_doc(ft_strjoin(argv[2], "\n"), argc);
	}
	else
	{
		*here_doc_mode = 0;
		fd_infile = open_file(argv[1], 2);
	}
	argument_index = 2 + *here_doc_mode;
	fd_outfile = open_file(argv[argc - 1], *here_doc_mode);
	if (fd_infile == -1 || fd_outfile == -1)
		throw_error("fail to open outfile.", 1);
	if (dup2(fd_infile, STDIN_FILENO) == -1
		|| dup2(fd_outfile, STDOUT_FILENO) == -1)
		throw_error("fail on redirection", 1);
	return (argument_index);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	here_doc_mode;
	int	i;

	if (argc < 5)
		throw_error("arguments error", 1);
	i = configure_fds(argc, argv, &here_doc_mode);
	while (i < argc - 2)
		process_command(argv[i++], envp);
	if (here_doc_mode == 1)
		if (unlink(HERE_DOC_NAME) == -1)
			ft_putstr_fd("delete fail", 2);
	execute_command(argv[argc - 2], envp);
	return (0);
}
