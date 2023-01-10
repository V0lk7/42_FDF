/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:36:31 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 10:33:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_calc_ry_x(int x, int z, float angle)
{
	float	sin;
	float	cos;
	int		result;

	sin = sinf(angle);
	cos = cosf(angle);
	result = round(x * cos + (z * sin));
	return (result);
}

int	ft_calc_ry_z(int x, int z, float angle)
{
	float	sin;
	float	cos;
	int		result;

	sin = sinf(angle);
	cos = cosf(angle);
	result = round(z * cos - (x * sin));
	return (result);
}

void	ft_rotation_y(t_dot *dot, float angle)
{
	int		xtemp;

	angle *= PI / 180;
	xtemp = dot->x - dot->i;
	dot->x1 = ft_calc_ry_x(xtemp, dot->z, angle) + dot->i;
	dot->z1 = ft_calc_ry_z(xtemp, dot->z, angle);
	return ;
}
