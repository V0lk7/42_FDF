/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:19 by jduval            #+#    #+#             */
/*   Updated: 2023/01/09 18:24:25 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void static	ft_display(t_dot *dot)
{
	printf("x = %i\t", dot->x);
	printf("y = %i\t", dot->y);
	printf("z = %i\n", dot->z);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_dot	dot1;
	t_dot	dot2;
	t_dot	dot3;
	t_dot	dot4;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fuck this shit !");	
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);	
	dot1 = ft_insert_points(300, 200, 0);
	dot2 = ft_insert_points(600, 200, 0);
	dot3 = ft_insert_points(300, 600, 0);
	dot4 = ft_insert_points(600, 600, 0);
	ft_display(&dot1);
	ft_display(&dot2);
	ft_dda(&img, &dot1, &dot2);
	ft_dda(&img, &dot1, &dot3);
	ft_dda(&img, &dot3, &dot4);
	ft_dda(&img, &dot2, &dot4);
	ft_rotation_z(&dot1, 10);
	ft_rotation_z(&dot2, 10);
	ft_rotation_z(&dot3, 10);
	ft_rotation_z(&dot4, 10);
	dot1.color = 0x00FF0000;
	dot2.color = 0x00FF0000;
	dot3.color = 0x00FF0000;
	dot4.color = 0x00FF0000;
	ft_dda(&img, &dot1, &dot2);
	ft_dda(&img, &dot1, &dot3);
	ft_dda(&img, &dot3, &dot4);
	ft_dda(&img, &dot2, &dot4);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);	
}
