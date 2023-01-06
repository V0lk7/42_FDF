/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:19 by jduval            #+#    #+#             */
/*   Updated: 2023/01/03 15:35:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <stdlib.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_line(t_data *data, t_line *line)
{
	int	i;

	i = 0;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
	if (abs(line->dx) > abs(line->dx))
		line->steps = abs(line->dx);
	else
		line->steps = abs(line->dy);
	line->xinc = line->dx / line->steps;
	line->yinc = line->dy / line->steps;
	while (i < line->steps)
	{
		my_mlx_pixel_put(data, round(line->x1), round(line->y1), line->color);
		line->x1 += line->xinc;
		line->y1 += line->yinc;
		i++;
	}
}

t_line	ft_insert_points(int xa, int ya, int xb, int yb)
{
	t_line	line;

	line.x1 = xa;
	line.x2 = xb;
	line.y1 = ya;
	line.y2 = yb;
	line.color = 0x0000FF00;
	return (line);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_line	line;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 480, "Hello world!");	
	img.img = mlx_new_image(mlx, 720, 480);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);	
	line = ft_insert_points(100, 10, 50, 60);
	ft_draw_line(&img, &line);
	line = ft_insert_points(50, 60, 100, 110);
	ft_draw_line(&img, &line);
	line = ft_insert_points(100, 110, 150, 60);
	ft_draw_line(&img, &line);
	line = ft_insert_points(150, 60, 100, 10);
	ft_draw_line(&img, &line);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);	

}
