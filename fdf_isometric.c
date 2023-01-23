/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:40:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/23 10:17:31 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_iso(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < vars->map[0][0].lines)
	{
		while (j < vars->map[0][0].cols)
		{
			ft_rotation_z(&vars->map[i][j], 40);
			ft_rotation_x(&vars->map[i][j], 32);
			j++;
		}
		j = 0;
		i++;
	}
	ft_link_points(vars);
	return ;
}
