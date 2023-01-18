/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:33:53 by jduval            #+#    #+#             */
/*   Updated: 2023/01/17 08:53:12 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom_out(t_dot *map)
{
	if (map->x1 < map->i && map->y1 < map->j)
	{
		map->x1++;
		map->y1++;
	}
	else if (map->x1 < map->i && map->y1 > map->j)
	{
		map->x1++;
		map->y1--;
	}
	else if (map->x1 > map->i && map->y1 < map->j)
	{
		map->x1--;
		map->y1++;
	}
	else if (map->x1 > map->i && map->y1 > map->j)
	{
		map->x1--;
		map->y1--;
	}
	else if (map->x1 = map->i && map->y1 != map->j)
	{
		if (map->y1 < map->j)
			map->y1++;
		else
			map->y1--;
	}
	else if (map->y1 = map->j && map->x1 != map->i)
	{
		if (map->x1 < map->i)
			map->x1++;
		else
			map->x1--;
	}
}
