/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:28:52 by jduval            #+#    #+#             */
/*   Updated: 2023/01/11 10:41:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_str(char *str, char **list)
{
	int	i;

	i = 0;
	if (str != NULL)
		free(str);
	if (*list != NULL && list != NULL)
	{
		while (list[i])
		{
			free(list[i]);
			i++;
		}
		free(list);
	}
	return ;
}
