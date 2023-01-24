/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:46:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/24 13:49:21 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	ft_init_structs(t_shift *shift)
{
	shift->set = 0;
	shift->r_x = 0;
	shift->r_y = 0;
	shift->r_z = 1;
}

int	main(int argc, char **argv)
{
	t_datum	database;

	ft_init_vars(&database.vars, argc, argv);
	ft_init_structs(&database.shift);
	ft_create_iso(&database.vars);
	mlx_put_image_to_window(database.vars.mlx, database.vars.mlx_win,
		database.vars.data.img, 0, 0);
	mlx_key_hook(database.vars.mlx_win, ft_key, &database.vars);
	mlx_hook(database.vars.mlx_win, 17, 0L, ft_mouse, &database.vars);
	mlx_loop(database.vars.mlx);
	return (0);
}
