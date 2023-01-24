/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:29 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 17:58:20 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_key(int keycode, t_datum *database)
{
	printf("%i\n", keycode);
	if (keycode == ESC)
		ft_close_program(&database->vars);
	else if (keycode == I || keycode == O)
		ft_zoom(&database->vars, keycode);
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
