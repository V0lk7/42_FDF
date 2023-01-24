/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_middle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:20:26 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 11:01:57 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_middle_position(t_dot **map)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	tmp;

	x = abs(map[0][0].cols / 2);
	y = abs(map[0][0].lines / 2);
	tmp = map[0][0].i - map[y][x].x1;
	y = map[0][0].j - map[y][x].y1;
	i = 0;
	while (i < map[0][0].lines)
	{
		j = 0;
		while (j < map[0][0].cols)
		{
			map[i][j].x1 += tmp;
			map[i][j].y1 += y;
			j++;
		}
		i++;
	}
}
