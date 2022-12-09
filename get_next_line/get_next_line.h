/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soohong <soohong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:23:56 by soohong           #+#    #+#             */
/*   Updated: 2022/12/09 15:45:14 by soohong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_strdup(const char *s1);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);

#endif
