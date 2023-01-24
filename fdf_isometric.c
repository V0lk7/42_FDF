/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:40:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 12:51:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_resize(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		while (j < vars->map[0][0].cols)
		{
			vars->map[i][j].x1 *= 0.55;
			vars->map[i][j].y1 *= 0.55;
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_create_iso(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		while (j < vars->map[0][0].cols)
		{
			ft_rotation_z(&vars->map[i][j], 45);
			ft_rotation_x(&vars->map[i][j], 32);
			j++;
		}
		j = 0;
		i++;
	}
	ft_resize(vars);
	ft_middle_position(vars->map);
	ft_link_points(vars);
	return ;
}
