/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:28:52 by jduval            #+#    #+#             */
/*   Updated: 2023/01/17 15:05:18 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_str(char *str, char **list)
{
	int	i;

	i = 0;
	if (str != NULL)
		free(str);
	if (list != NULL)
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

void	ft_free_struct(t_dot **map)
{
	int	i;
	int	j;

	j = map[0]->lines;
	i = 0;
	if (*map == NULL || map == NULL)
		return ;
	while (i < j)
	{
		free (map[i]);
		i++;
	}
	free (map);
	return ;
}
