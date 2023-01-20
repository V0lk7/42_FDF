/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:19:29 by jduval            #+#    #+#             */
/*   Updated: 2023/01/20 17:39:16 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_key(int keycode, t_vars *vars/*, t_shift *shift*/)
{
	printf("%i\n", keycode);
	if (keycode == ESC)
		ft_close_program(vars);
	else if (keycode == I || keycode == O)
	{
		printf("je passe\n");
		ft_zoom(vars, keycode);	
	}
	return (0);
}

