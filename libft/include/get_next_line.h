/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:12:15 by jduval            #+#    #+#             */
/*   Updated: 2022/11/24 09:52:58 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_flag(char *buffer);
void	ft_move(char **buffer, int len);
int		ft_read_for(char **buffer, int fd);
char	*get_next_line(int fd);
#endif
