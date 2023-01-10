/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:17:14 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 10:33:39 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_calc_rz_x(int x, int y, float angle)
{
	float	cos;
	float	sin;
	int		result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = round(x * cos - y * sin);
	return (result);
}

int	ft_calc_rz_y(int x, int y, float angle)
{
	float	cos;
	float	sin;
	int		result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = round(x * sin + y * cos);
	return (result);
}

void	ft_rotation_z(t_dot *dot, float angle)
{
	int		xtemp;
	int		ytemp;

	angle *= PI / 180;
	xtemp = dot->x - dot->i;
	ytemp = dot->y - dot->j;
	dot->x1 = ft_calc_rz_x(xtemp, ytemp, angle) + dot->i;
	dot->y1 = ft_calc_rz_y(xtemp, ytemp, angle) + dot->j;
	return ;
}
