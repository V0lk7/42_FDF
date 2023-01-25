/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_face_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 13:49:01 by jduval            #+#    #+#             */
/*   Updated: 2023/01/25 15:07:42 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_face_view(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	ft_clear(vars);
	while (i < vars->map[0][0].lines)
	{
		j = 0;
		while (j < vars->map[0][0].cols)
		{
			vars->map[i][j].x1 = vars->map[i][j].x;
			vars->map[i][j].y1 = vars->map[i][j].y;
			vars->map[i][j].z1 = vars->map[i][j].z;
			j++;
		}
		i++;
	}
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
}
