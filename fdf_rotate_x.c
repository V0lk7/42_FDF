/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:36:16 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 11:34:32 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_calc_rx_y(float y, float z, float angle)
{
	float	cos;
	float	sin;
	float	result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = y * cos - (z * sin);
	return (result);
}

float	ft_calc_rx_z(float y, float z, float angle)
{
	float	cos;
	float	sin;
	float	result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = y * sin + (z * cos);
	return (result);
}

void	ft_rotation_x(t_dot *dot, float angle)
{
	float	ytemp;

	angle = angle * PI / 180;
	ytemp = dot->y1 - dot->j;
	dot->y1 = ft_calc_rx_y(ytemp, dot->z1, angle) + dot->j;
	dot->z1 = ft_calc_rx_z(ytemp, dot->z1, angle);
	return ;
}
