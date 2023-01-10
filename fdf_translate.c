/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_translate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 08:49:43 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 10:33:19 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translate_x(t_dot *dot, int shift)
{
	dot->x += shift;
	dot->i += shift;
}

void	ft_translate_y(t_dot *dot, int shift)
{
	dot->y += shift;
	dot->j += shift;
}
