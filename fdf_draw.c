/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 10:31:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= 1920)
			&& (y >= 0 && y <= 1080))
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

t_dot	ft_insert_points(int xa, int ya, int za)
{
	t_dot	dot;

	dot.x = xa;
	dot.y = ya;
	dot.z = za;
	dot.x1 = xa;
	dot.y1 = ya;
	dot.z1 = za;
	dot.i = 960;
	dot.j = 540;
	dot.k = 0;
	dot.color = 0xFFFFFFFF;
	return (dot);
}

void	ft_dda(t_data *img, t_dot *dot1, t_dot *dot2)
{
	float	steps;
	t_line	params;	

	steps = 0;
	params.x0 = dot1->x1;
	params.y0 = dot1->y1;
	params.dx = dot2->x1 - dot1->x1;
	params.dy = dot2->y1 - dot1->y1;
	if (abs(params.dx) > abs(params.dy))
		steps = abs(params.dx);
	else
		steps = abs(params.dy);
	params.xinc = params.dx / steps;
	params.yinc = params.dy / steps;
	while (steps >= 0)
	{
		ft_pixel_put(img, params.x0, params.y0, dot1->color);
		params.x0 += params.xinc;
		params.y0 += params.yinc;
		steps--;
	}
}
