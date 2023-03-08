/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/07 18:32:48 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
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
	free_split(path_list);
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
