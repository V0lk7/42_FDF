/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:28:52 by jduval            #+#    #+#             */
/*   Updated: 2023/01/25 14:59:02 by jduval           ###   ########.fr       */
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

float	ft_coef_k(t_base *base, t_tool *tool)
{
	int		i;
	float	k;
	float	max;
	float	min;

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
	if (min == 0 && max == 0)
		k = 0;
	else if (tool->incr_y > tool->incr_x)
		k = (tool->incr_y - (fabs(max - min))) / (fabs(max - min));
	else
		k = (tool->incr_x - (fabs(max - min))) / (fabs(max - min));
	return (k);
}
