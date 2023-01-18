/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_link_points.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 08:59:22 by jduval            #+#    #+#             */
/*   Updated: 2023/01/18 16:29:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_chose_color(int color1, int color2)
{
	if (color1 != 0xFFFFFF)
		return (color1);
	else if (color2 != 0xFFFFFF)
		return (color1);
	else
		return (color1);
}

void	ft_link_points(t_vars *vars, t_dot **map)
{
	int	i;
	int	j;
	int	color;

	i = 0;	
	j = 0;
	while (i < map[0][0].lines)
	{
		while (j < map[0][0].cols - 1)
		{
			color = ft_chose_color(map[i][j].color, map[i][j + 1].color);
			ft_dda(&vars->data, &map[i][j], &map[i][j + 1], color);
			j++;
		}
		j = 0;
		i++;
	}
	j = 0;
	while (j + 1 < map[0][0].lines)
	{
		i = map[0][0].cols - 1;
		while (i >= 0)
		{
			color = ft_chose_color(map[j][i].color, map[j + 1][i].color);
			ft_dda(&vars->data, &map[j][i], &map[j + 1][i], color);
			i--;
		}
		j++;
	}
	return ;
}
