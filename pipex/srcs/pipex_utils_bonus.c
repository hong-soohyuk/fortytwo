/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/07 17:40:04 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	open_file(char *filename, int option)
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

void	throw_error(char *message, int status)
{
	if (message)
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(message, 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	else
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(strerror(status), 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	exit(status);
}

static char	*find_path(char *command, char **envp)
{
	char	*path;
	char	*delimeted_path;
	char	**path_list;
	int		index;

	index = -1;
	while (envp[++index])
		if (ft_strncmp(envp[index], "PATH", 4) == 0)
			break ;
	path = ft_strchr(envp[index], '=') + 1;
	path_list = ft_split(path, ':');
	index = -1;
	while (path_list[++index])
	{
		delimeted_path = ft_strjoin(path_list[index], "/");
		delimeted_path = ft_strjoin(delimeted_path, command);
		if (access(delimeted_path, F_OK | X_OK) == 0)
			return (delimeted_path);
	}
	return (NULL);
}

void	execute_command(char *command, char *envp[])
{
	char	*path;
	char	**commands;

	commands = ft_split(command, ' ');
	path = find_path(commands[0], envp);
	if (path == NULL)
		throw_error("command not found", 127);
	if (execve(path, commands, envp) == -1)
		throw_error(NULL, 126);
}
