/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_user_interactions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 10:31:39 by jduval            #+#    #+#             */
/*   Updated: 2023/01/18 16:43:50 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	touch(int keycode, t_vars *vars)
{
	if (keycode != XK_Escape)
		return (0);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display()
}
