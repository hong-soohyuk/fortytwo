/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:52 by soohong           #+#    #+#             */
/*   Updated: 2023/03/03 16:48:12 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "../libft/includes/libft.h"

void	execute_command(char *cmd, char **envp);
void	throw_error(char *msg, int status);

#endif
