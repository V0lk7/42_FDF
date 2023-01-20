/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:28:52 by jduval            #+#    #+#             */
/*   Updated: 2023/01/20 12:24:03 by jduval           ###   ########.fr       */
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

float	ft_calculate_k(t_base *base, t_tool *tool)
{
	int		i;
	float	k;
	int		max;
	int		min;

	i = 0;
	k = 0;
	max = base[i].z_base;
	min = base[i].z_base;
	while (i < base[0].lengh)
	{
		if (max < base[i].z_base)
			max = base[i].z_base;
		if (min > base[i].z_base)
			min = base[i].z_base;
		i++;
	}
	if (tool->incr_y > tool->incr_x)
		k = (tool->incr_y - (abs(max - min))) / (abs(max - min));
	else
		k = (tool->incr_x - (abs(max - min))) / (abs(max - min));
	if (k < 0)
		k *= -1;
	return (k);
}
