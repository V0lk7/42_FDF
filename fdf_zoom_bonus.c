/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:33:53 by jduval            #+#    #+#             */
/*   Updated: 2023/01/20 19:22:49 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static	void	ft_zoom_in(t_dot *dot, int shift_x, int shift_y)
{
	float	i;

	i = 1.1;
	//shift_x = shift_y;
	dot->x1 -= shift_x;
	dot->y1 -= shift_y;
	dot->y1 = roundf(dot->y1 * i);
	dot->x1 = roundf(dot->x1 * i);
	dot->x1 += shift_x;
	dot->y1 += shift_y;
	return ;
}

static	void	ft_zoom_out(t_dot *dot, int shift_x, int shift_y)
{
	dot->x1 -= shift_x / 2;
	dot->y1 -= shift_y / 2;
	if (dot->x1 < 0)
		dot->x1 = roundf(dot->x1 * 0.9);
	else
		dot->x1 = roundf(dot->x1 * 1.1);
	if (dot->y1 < 0)
		dot->y1 = roundf(dot->y1 * 0.9);
	else
		dot->y1 = roundf(dot->y1 * 1.1);
	dot->x1 += shift_x / 2;
	dot->y1 += shift_y / 2;
	return ;
}

void	ft_zoom(t_vars *vars, int keycode)
{
	int	shift_x;
	int	shift_y;
	int	i;
	int	j;

	shift_x = vars->x;
	shift_y = vars->y;
	i = 0;
	ft_clear(vars);
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			if (keycode == I)
				ft_zoom_in(&vars->map[i][j], shift_x, shift_y);
			else if (keycode == O)
				ft_zoom_out(&vars->map[i][j], shift_x, shift_y);
			j++;
		}
		i++;
	}
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
	return ;
}
