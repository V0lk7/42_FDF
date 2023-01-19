/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_user_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:31:39 by jduval            #+#    #+#             */
/*   Updated: 2023/01/19 14:35:15 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_close_program(t_vars *vars)
{
	ft_free_struct(vars->map);
	mlx_destroy_image(vars->mlx, vars->data.img);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(0);
}

int	ft_keyboard(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		ft_close_program(vars);
		exit(0);
	}
	else
		return (0);
}

int	ft_mouse(t_vars *vars)
{
	ft_close_program(vars);
	return (0);
}
