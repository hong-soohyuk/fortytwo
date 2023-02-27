/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:59 by soohong           #+#    #+#             */
/*   Updated: 2023/02/28 00:19:05 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	throw_error(char *msg, int status)
{
	if (msg)
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(msg, 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	else
	{
		ft_putstr_fd("\033[31mError : ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n\033[0m", 2);
	}
	exit(status);
}


char	*find_path(char *cmd, char **envp)
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
		delimeted_path = ft_strjoin(delimeted_path, cmd);
		if (access(delimeted_path, F_OK) == 0)
			return (delimeted_path);
	}
	return (NULL);
}

void	execute_cmd(char *cmd, char **envp)
{
	char	*path;
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	path = find_path(cmds[0], envp);
	if (path == NULL)
		throw_error("command not found", 127);
	if (execve(path, cmds, envp) == -1)
		throw_error(NULL, 126);
}
