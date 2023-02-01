/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_aitoff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:06:40 by jduval            #+#    #+#             */
/*   Updated: 2023/02/01 08:44:06 by jduval           ###   ########.fr       */
/*   Updated: 2023/01/26 15:45:51 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static float	ft_do_the_math(float lon, float lat, int side)
{
	float	alpha;
	float	sinc;
	float	result;

	alpha = acosf(cosf(lat) * cosf(lon / 2));
	sinc = sinf(alpha) / (alpha);
	result = 0.0;
	if (side == A_X)
		result = (2 * cosf(lat) * sinf(lon / 2)) / sinc;
	else if (side == A_Y)
		result = sinf(lat) / sinc;
	return (result);
}

static void	ft_set(t_dot **map, int meridian)
{
	int		i;
	int		j;
	float	lat;
	float	lon;

	i = 1;
	while (i < map[0][0].lines - 1)
	{
		lon = fabs(i * PI / (map[0][0].lines / 2) - meridian);
		j = 1;
		while (j < map[0][0].cols - 1)
		{
			lat = fabs(j * PI / (map[0][0].cols / 2) - meridian);
			map[i][j].x1 = ft_do_the_math(lon, lat, A_X);
			map[i][j].y1 = ft_do_the_math(lon, lat, A_Y);
			j++;
		}
		i++;
	}
}

static void	ft_set_aitoff(t_dot **map)
{
	int	meridian;

	meridian = map[0][0].lines / 2;
	ft_set(map, meridian);
}

void	ft_aitoff(t_vars *vars, int *aitoff)
{
	*aitoff = 1;
	ft_reset_map(vars);
	ft_clear(vars);
	ft_set_aitoff(vars->map);
	ft_resize(vars, 50);
	ft_middle_position(vars->map);
	ft_link_points(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->data.img, 0, 0);
}
