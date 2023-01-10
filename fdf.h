/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:46 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 15:28:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx.h"
#include <math.h>
#include "libft.h"
#include <stdio.h>

#define PI 3.1415926

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

//	Coordinate of each point	//
typedef struct	s_dot
{
	int	x;
	int	y;
	int	z;
	int	x1;
	int	y1;
	int	z1;
	int	i;
	int	j;
	int	k;
	int	color;
}	t_dot;

//	Utilities to draw line		//
typedef	struct	s_line
{
	float	x0;
	float	y0;
	int		dx;
	int		dy;
	float	xinc;
	float	yinc;
}	t_line;

//------fdf_draw.c-------------------------------------//
void	ft_pixel_put(t_data *data, int x, int y, int color);
t_dot	ft_insert_points(int xa, int ya, int za);
void	ft_dda(t_data *img, t_dot *dot1, t_dot *dot2);
//------fdf_revise_x.c---------------------------------//
void	ft_rotation_x(t_dot *dot, float angle);
int		ft_calc_rx_y(int y, int z, float angle);
int		ft_calc_rx_z(int y, int z, float angle);
//------fdf_revise_y.c---------------------------------//
void	ft_rotation_y(t_dot *dot, float angle);
int		ft_calc_ry_x(int x, int z, float angle);
int		ft_calc_ry_z(int x, int z, float angle);
//------fdf_revise_z.c---------------------------------//
void	ft_rotation_z(t_dot *dot, float angle);
int		ft_calc_rz_x(int x, int y, float angle);
int		ft_calc_rz_y(int x, int y, float angle);
//------fdf_translate.c--------------------------------//
void	ft_translate_x(t_dot *dot, int shift);
void	ft_translate_y(t_dot *dot, int shift);
//------fdf_parsing.c--------------------------------//
t_bool	ft_valid_file(char *argv);
char	*ft_get_map(char *argv);
#endif
