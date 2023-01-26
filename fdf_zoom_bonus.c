/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:33:53 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 13:15:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static	void	ft_zoom_in(t_dot *dot)
{
	float	i;

	i = 1.2;
	dot->y1 = dot->y1 * i;
	dot->x1 = dot->x1 * i;
	return ;
}

static	void	ft_zoom_out(t_dot *dot)
{
	float	i;

	i = 0.8;
	dot->y1 = dot->y1 * i;
	dot->x1 = dot->x1 * i;
	return ;
}

static void	ft_apply(t_dot **map, int keycode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map[0][0].lines)
	{
		j = 0;
		while (j < map[0][0].cols)
		{
			if (keycode == I)
				ft_zoom_in(&map[i][j]);
			else if (keycode == O)
				ft_zoom_out(&map[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_zoom(t_vars *vars, int keycode)
{
	ft_clear(vars);
	ft_apply(vars->map, keycode);
	ft_middle_position(vars->map);
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
	return ;
}
