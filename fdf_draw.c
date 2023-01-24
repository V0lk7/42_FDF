/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 12:12:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;
	int		tmp;

	if ((x >= 0 && x < vars->x) && (y >= 0 && y < vars->y))
	{
		tmp = y * vars->data.l_lengh + x * (vars->data.bpp / 8);
		dst = vars->data.addr + tmp;
		*(unsigned int *)dst = color;
	}
}

void	ft_dda(t_vars *vars, t_dot *dot1, t_dot *dot2, int color)
{
	float	steps;
	t_line	params;	

	steps = 0;
	params.x0 = dot1->x1;
	params.y0 = dot1->y1;
	params.dx = dot2->x1 - dot1->x1;
	params.dy = dot2->y1 - dot1->y1;
	if (fabs(params.dx) > fabs(params.dy))
		steps = fabs(params.dx);
	else
		steps = fabs(params.dy);
	params.xinc = params.dx / steps;
	params.yinc = params.dy / steps;
	while (steps >= 0)
	{
		ft_pixel_put(vars, roundf(params.x0), roundf(params.y0), color);
		params.x0 += params.xinc;
		params.y0 += params.yinc;
		steps--;
	}
}
