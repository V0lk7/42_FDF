/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:29 by jduval            #+#    #+#             */
/*   Updated: 2023/01/25 16:36:14 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	ft_limit_zoom(t_datum *database, int keycode)
{
	if (database->zlim > -3 && database->zlim < 3)
		ft_zoom(&database->vars, keycode, &database->zlim);
	else if (database->zlim <= -3 && keycode == O)
		ft_zoom(&database->vars, keycode, &database->zlim);
	else if (database->zlim >= 0 && keycode == I)
		ft_zoom(&database->vars, keycode, &database->zlim);
	else
		return ;
}

int	ft_key(int keycode, t_datum *database)
{
	if (keycode == ESC)
		ft_close_program(&database->vars);
	else if (keycode == I || keycode == O)
		ft_limit_zoom(database, keycode);
	else if (keycode == R)
		ft_reset_view(&database->vars);
	else if (keycode == F)
		ft_face_view(&database->vars);
	else if (keycode == G)
		ft_aitoff(&database->vars);
	ft_translation(&database->vars, keycode);
	ft_rotation(&database->vars, &database->shift, keycode);
	return (0);
}
