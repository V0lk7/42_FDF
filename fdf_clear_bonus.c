/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_clear_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:09:23 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 13:11:22 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_reset_map(t_vars *vars)
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
			vars->map[i][j].x1 = 0;
			vars->map[i][j].y1 = 0;
			j++;
		}
		i++;
	}
}

void	ft_clear(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->y)
	{
		j = 0;
		while (j < vars->x)
		{
			ft_pixel_put(vars, j, i, 0x000000);
			j++;
		}
		i++;
	}
	return ;
}
