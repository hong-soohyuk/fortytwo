/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/03/09 18:19:02 by soohong          ###   ########.fr       */
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

static char	*get_path_command(char const *path, char *command)
{
	char	*delimeted_path;
	char	*path_joined_command;

	delimeted_path = ft_strjoin(path, "/");
	path_joined_command = ft_strjoin(delimeted_path, command);
	free(delimeted_path);
	return (path_joined_command);
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
	char	*path_joined_command;
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
		path_joined_command = get_path_command(path_list[index], command);
		if (access(path_joined_command, F_OK | X_OK) == 0)
		{
			free_split(path_list);
			return (path_joined_command);
		}
		free(path_joined_command);
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
	{
		free_split(commands);
		throw_error("command not found", 127);
	}
	if (execve(path, commands, envp) == -1)
		throw_error(NULL, 126);
}
