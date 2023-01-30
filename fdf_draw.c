/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:10:32 by jduval            #+#    #+#             */
/*   Updated: 2023/01/30 11:47:33 by jduval           ###   ########.fr       */
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

int	ft_check_points(t_dot *dot1, t_dot *dot2, int x, int y)
{
	if (dot1->x1 > x && dot1->y1 > y)
	{
		if (dot2->x1 > x && dot2->y1 > y)
			return (0);
	}
	else if (dot1->x1 < 0 && dot1->y1 < 0)
	{
		if (dot2->x1 < 0 && dot2->y1 < 0)
			return (0);
	}
	return (1);
}

void	ft_dda(t_vars *vars, t_dot *dot1, t_dot *dot2, int color)
{
	float	steps;
	t_line	params;	

	if (ft_check_points(dot1, dot2, vars->x, vars->y) == 0)
		return ;
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
