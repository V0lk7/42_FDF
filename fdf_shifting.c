/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:30:49 by jduval            #+#    #+#             */
/*   Updated: 2023/01/13 15:33:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_x(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = base[0].lengh;
	while(i < j - 1)
		i++;
	return (base[i].column);
}

int	ft_get_y(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = base[0].lengh;
	while(i < j - 1)
		i++;
	return (base[i].line);
}

t_dot	*ft_apply_points(t_base *base)
{
	int	x;
	int	y;
	int	i;

	x = ft_get_x(base);
	y = ft_get_y(base);
	i = 0;
}
