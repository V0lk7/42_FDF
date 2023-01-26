/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:40:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 13:12:11 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resize(t_vars *vars, float k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		while (j < vars->map[0][0].cols)
		{
			vars->map[i][j].x1 *= k;
			vars->map[i][j].y1 *= k;
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
			ft_rotation_x(&vars->map[i][j], 35);
			ft_rotation_z(&vars->map[i][j], 45);
			j++;
		}
		j = 0;
		i++;
	}
	ft_resize(vars, 0.45);
	ft_middle_position(vars->map);
	ft_link_points(vars);
	return ;
}
