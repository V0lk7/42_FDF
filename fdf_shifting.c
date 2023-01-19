/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_shifting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:30:49 by jduval            #+#    #+#             */
/*   Updated: 2023/01/19 18:30:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_get_x(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = base[0].lengh;
	while (i < j - 1)
		i++;
	return (base[i].column);
}

int	ft_get_y(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = base[0].lengh;
	while (i < j - 1)
		i++;
	return (base[i].line);
}

t_dot	*ft_insert_map(t_base *base, t_tool tool)
{
	int		i;
	t_dot	*map;

	i = 0;
	map = malloc(sizeof(t_dot) * (tool.len_x));
	while (i < tool.len_x)
	{
		map[i].x = tool.incr_x;
		map[i].y = tool.incr_y;
		map[i].z = base[i].z_base * tool.k;
		map[i].x1 = tool.incr_x;
		map[i].y1 = tool.incr_y;
		map[i].z1 = base[i].z_base * tool.k;
		map[i].i = tool.x_origin;
		map[i].j = tool.y_origin;
		map[i].k = 0;
		map[i].color = base[i].color_base;
		map[i].lines = tool.len_y;
		map[i].cols = tool.len_x;
		tool.incr_x += tool.incr_xo;
		i++;
	}
	return (map);
}

void	ft_set_tool(t_base *base, t_tool *tool, int lengh, int width)
{
	tool->x_origin = lengh / 2;
	tool->y_origin = width / 2;
	tool->len_x = ft_get_x(base) + 1;
	tool->len_y = ft_get_y(base) + 1;
	tool->len_xi = tool->len_x;
	tool->len_yi = tool->len_y;
	if ((tool->len_xi) % 2 == 0)
		tool->incr_x = tool->x_origin / ((roundf((tool->len_x + 1) / 2) + 0.5));
	else
		tool->incr_x = tool->x_origin / ((tool->len_x + 1) / 2);
	if ((tool->len_yi) % 2 == 0)
		tool->incr_y = tool->y_origin / ((roundf((tool->len_y + 1) / 2) + 0.5));
	else
		tool->incr_y = tool->y_origin / ((tool->len_y + 1) / 2);
	tool->incr_xo = tool->incr_x;
	tool->incr_yo = tool->incr_y;
	tool->k = ft_calculate_k(base, tool);
	return ;
}

t_dot	**ft_apply_map(t_base *base, int lengh, int width)
{
	t_tool	tool;
	t_dot	**map;
	int		i;
	int		k;

	ft_set_tool(base, &tool, lengh, width);
	i = -1;
	k = 0;
	map = malloc(sizeof(t_dot *) * (tool.len_y));
	if (map == NULL)
		return (NULL);
	while (++i < tool.len_y)
	{
		map[i] = ft_insert_map(&base[k], tool);
		if (map[i] == NULL)
			return (NULL);
		k += tool.len_x;
		tool.incr_y += tool.incr_yo;
	}
	return (map);
}
