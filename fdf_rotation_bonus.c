/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:34:33 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 11:36:29 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_apply_rx(t_vars *vars, float theta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			ft_rotation_x(&vars->map[i][j], theta);
			j++;
		}
		i++;
	}
}

static void	ft_apply_ry(t_vars *vars, float theta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			ft_rotation_y(&vars->map[i][j], theta);
			j++;
		}
		i++;
	}
}

static void	ft_apply_rz(t_vars *vars, float theta)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			ft_rotation_z(&vars->map[i][j], theta);
			j++;
		}
		i++;
	}
}

static void	ft_rotate(t_vars *vars, t_shift *shift, int sign)
{
	float	theta;

	theta = 2.0 * sign;
	ft_clear(vars);
	if (shift->r_x == 1)
		ft_apply_rx(vars, theta);
	else if (shift->r_y == 1)
		ft_apply_ry(vars, theta);
	else if (shift->r_z == 1)
		ft_apply_rz(vars, theta);
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
}

void	ft_rotation(t_vars *vars, t_shift *shift, int keycode)
{
	if (shift->set == 1 && (keycode == X || keycode == Y || keycode == Z))
	{
		shift->r_x = 0;
		shift->r_y = 0;
		shift->r_z = 0;
		if (keycode == X)
			shift->r_x = 1;
		else if (keycode == Y)
			shift->r_y = 1;
		else
			shift->r_z = 1;
		shift->set = 0;
		return ;
	}
	else if (keycode == CTRL)
		shift->set = 1;
	else if (keycode == E && shift->set <= 0)
		ft_rotate(vars, shift, 1);
	else if (keycode == Q && shift->set <= 0)
		ft_rotate(vars, shift, -1);
	else
		return ;
}
