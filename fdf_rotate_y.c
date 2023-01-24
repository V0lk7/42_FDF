/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:36:31 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 10:32:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_calc_ry_x(float x, float z, float angle)
{
	float	sin;
	float	cos;
	float	result;

	sin = sinf(angle);
	cos = cosf(angle);
	result = x * cos + (z * sin);
	printf("result x = %f\n", result);
	return (result);
}

float	ft_calc_ry_z(float x, float z, float angle)
{
	float	sin;
	float	cos;
	float	result;

	sin = sinf(angle);
	cos = cosf(angle);
	result = (x * -sin) + (z * cos);
	printf("result z = %f\n", result);
	return (result);
}

void	ft_rotation_y(t_dot *dot, float angle)
{
	float		xtemp;

	angle *= PI / 180;
	xtemp = dot->x1 - dot->i;
	dot->x1 = ft_calc_ry_x(xtemp, dot->z1, angle) + dot->i;
	dot->z1 = ft_calc_ry_z(xtemp, dot->z1, angle);
	return ;
}
