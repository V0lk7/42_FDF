/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:19 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 15:59:35 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <string.h>

int	main(void)
{
	char	*str = malloc(sizeof(char) * 9);
	char	*str2 = "ton pere";
	
	str = "je suis ";
	str = ft_strjoin_free(str, str2);
	printf("%s\n", str);
	return (0);
}
/*
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_dot	**list;

	list = ft_organise(argc, argv);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hey hey hey boy");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	dot1 = ft_insert_points(960, 300, 0);
	dot2 = ft_insert_points(960, 300, 0);
	ft_dda(&img, &dot1, &dot2);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/
