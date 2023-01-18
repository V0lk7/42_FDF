/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:27:19 by jduval            #+#    #+#             */
/*   Updated: 2023/01/18 16:43:52 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static void	ft_display(t_dot **map)
{
	int	i = 0;
	int	k = 0;
	int	z = map[0][0].lines;
	int	m = map[0][0].cols;

	while (k < z)
	{
		printf("ligne numéro %i\n", k);
		while (i < m)
		{
			printf("Structure numéro %i\n", i);
			printf("x = %i, y = %i, z = %i\n", map[k][i].x, map[k][i].y, map[k][i].z);
			printf("x1 = %i, y1 = %i, z1 = %i\n", map[k][i].x1, map[k][i].y1, map[k][i].z1);
			printf("i = %i, j = %i, k = %i\n", map[k][i].i, map[k][i].j, map[k][i].k);
			printf("color = %i\n", map[k][i].color);
			i++;
		}
		i = 0;
		k++;
	}
}
*/

void	ft_init_data(t_vars *vars, t_data *data, int x, int y)
{
	data->img = mlx_new_image(vars->mlx, x, y);
	if (data->img == NULL)
	{
		ft_free_struct(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
				&data->l_lengh, &data->endian);
	if (data->addr == NULL)
	{
		ft_free_struct(vars->map);
		mlx_destroy_display(vars->mlx);
		mlx_destroy_image(vars->mlx, data->img);
		free(vars->mlx);
		exit(0);
	}
}

void	ft_init_vars(t_vars *vars, int argc, char **argv)
{
	vars->x = 1920;
	vars->y = 1080;
	vars->map = ft_organise(argc, argv, vars->x, vars->y);
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
	{
		ft_free_struct(vars->map);
		exit(0);
	}
	vars->mlx_win = mlx_new_window(vars->mlx, vars->x, vars->y, "fdf");
	if (vars->mlx_win == NULL)
	{
		ft_free_struct(vars->map);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
		exit(0);
	}
	ft_init_data(vars, &vars->data, vars->x, vars->y);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	ft_init_vars(&vars, argc, argv);
	ft_link_points(&vars, vars.map);
	ft_free_struct(vars.map);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.data.img, 0, 0);
	mlx_loop(vars.mlx);
	return (0);
}
