/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_z.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:17:14 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 11:34:54 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_calc_rz_x(float x, float y, float angle)
{
	float	cos;
	float	sin;
	float	result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = x * cos - y * sin;
	return (result);
}

float	ft_calc_rz_y(float x, float y, float angle)
{
	float	cos;
	float	sin;
	float	result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = x * sin + y * cos;
	return (result);
}

void	ft_rotation_z(t_dot *dot, float angle)
{
	float	xtemp;
	float	ytemp;

	angle *= PI / 180;
	xtemp = dot->x1 - dot->i;
	ytemp = dot->y1 - dot->j;
	dot->x1 = ft_calc_rz_x(xtemp, ytemp, angle) + dot->i;
	dot->y1 = ft_calc_rz_y(xtemp, ytemp, angle) + dot->j;
	return ;
}
