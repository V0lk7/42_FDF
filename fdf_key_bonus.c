/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:29 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 14:00:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_limit_zoom(t_vars *vars, int keycode, int aitoff)
{
	float	dif;
	int		line;
	int		col;

	if (aitoff == 1)
		return ;
	line = vars->map[0][0].lines - 1;
	col = vars->map[0][0].cols - 1;
	dif = vars->map[line][col].x1 - vars->map[0][0].x1;
	if (dif <= 100)
	{
		if (keycode == I)
			ft_zoom(vars, keycode);
		return ;
	}
	else if (dif >= 5000)
	{
		if (keycode == O)
			ft_zoom(vars, keycode);
		return ;
	}
	ft_zoom(vars, keycode);
}

int	ft_key(int keycode, t_datum *database)
{
	if (keycode == ESC)
		ft_close_program(&database->vars);
	else if (keycode == I || keycode == O)
		ft_limit_zoom(&database->vars, keycode, database->aitoff);
	else if (keycode == R)
		ft_reset_view(&database->vars, &database->aitoff);
	else if (keycode == F)
		ft_face_view(&database->vars, &database->aitoff);
	else if (keycode == G)
		ft_aitoff(&database->vars, &database->aitoff);
	ft_translation(&database->vars, keycode);
	ft_rotation(&database->vars, &database->shift, keycode);
	return (0);
}
