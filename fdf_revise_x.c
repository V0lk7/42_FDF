/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_revise_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:36:16 by jduval            #+#    #+#             */
/*   Updated: 2023/01/09 15:12:09 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_calc_rx_y(int y, int z, float angle)
{
	float	cos;
	float	sin;
	int		result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = round(y * cos - (z * sin));
	return (result);
}

int	ft_calc_rx_z(int y, int z, float angle)
{
	float	cos;
	float	sin;
	int		result;

	cos = cosf(angle);
	sin = sinf(angle);
	result = round(y * sin + (z * cos));
	return (result);
}

void	ft_rotation_x(t_dot *dot, float angle)
{
	int		ytemp;

	angle *= PI / 180;
	ytemp = dot->y;
	dot->y = ft_calc_rx_y(dot->y, dot->z, angle);
	dot->z = ft_calc_rx_z(ytemp, dot->z, angle);
	return ;
}
