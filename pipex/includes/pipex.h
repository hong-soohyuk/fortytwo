/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:45:52 by soohong           #+#    #+#             */
/*   Updated: 2023/03/07 17:48:33 by soohong          ###   ########.fr       */
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
# include "../get_next_line/get_next_line.h"

# define HERE_DOC_NAME ".temporary.here_doc"

void	execute_command(char *cmd, char **envp);
void	throw_error(char *msg, int status);
int		open_file(char *filename, int option);

#endif
