/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:49:43 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 13:15:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_translate_x(t_vars *vars, int sign)
{
	int	i;
	int	j;
	int	k;

	k = 5 * sign;
	i = 0;
	j = 0;
	ft_clear(vars);
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			vars->map[i][j].x1 += k;
			j++;
		}
		i++;
	}
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
}

static void	ft_translate_y(t_vars *vars, int sign)
{
	int	i;
	int	j;
	int	k;

	k = 5 * sign;
	i = 0;
	j = 0;
	ft_clear(vars);
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			vars->map[i][j].y1 += k;
			j++;
		}
		i++;
	}
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
}

void	ft_translation(t_vars *vars, int keycode)
{
	if (keycode == UP || keycode == W)
		ft_translate_y(vars, -1);
	else if (keycode == DOWN || keycode == S)
		ft_translate_y(vars, 1);
	else if (keycode == LEFT || keycode == A)
		ft_translate_x(vars, -1);
	else if (keycode == RIGHT || keycode == D)
		ft_translate_x(vars, 1);
	return ;
}
