/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:46:59 by jduval            #+#    #+#             */
/*   Updated: 2023/01/20 17:33:16 by jduval           ###   ########.fr       */
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
	vars->x = 720;
	vars->y = 480;
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
	ft_create_iso(&vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, vars.data.img, 0, 0);
	mlx_key_hook(vars.mlx_win, ft_key, &vars);
	mlx_hook(vars.mlx_win, 17, 0L, ft_mouse, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
