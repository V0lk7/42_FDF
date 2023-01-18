/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:18:46 by jduval            #+#    #+#             */
/*   Updated: 2023/01/18 15:44:53 by jduval           ###   ########.fr       */
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
	int		bpp;
	int		l_lengh;
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
	int	cols;
	int	lines;
	int	color;
}	t_dot;

//	Img data					//
typedef struct	s_vars
{
	t_data 	data;
	int		x;
	int		y;
	t_dot	**map;
	void	*mlx;
	void	*mlx_win;
}	t_vars;

//	Struct to draw line		//
typedef	struct	s_line
{
	float	x0;
	float	y0;
	int		dx;
	int		dy;
	float	xinc;
	float	yinc;
}	t_line;

//	Struct parsing set		//
typedef struct	s_base
{
	int	z_base;
	int	color_base;
	int	column;
	int	line;
	int	lengh;
}	t_base;

//	Struct for create the map	//
typedef	struct	s_tool
{
	float	x_origin;
	float	y_origin;
	float	len_x;
	float	len_y;
	int		len_xi;
	int		len_yi;
	float	incr_x;
	float	incr_y;
	float	incr_xo;
	float	incr_yo;

}	t_tool;

//------fdf.c-------------------------------------//
void	ft_init_vars(t_vars *vars, int argc, char **argv);
void	ft_init_data(t_vars *vars, t_data *data, int x, int y);
//------fdf_draw.c-------------------------------------//
void	ft_pixel_put(t_data *data, int x, int y, int color);
void	ft_dda(t_data *img, t_dot *dot1, t_dot *dot2, int color);
//------fdf_rotate_x.c---------------------------------//
void	ft_rotation_x(t_dot *dot, float angle);
int		ft_calc_rx_y(int y, int z, float angle);
int		ft_calc_rx_z(int y, int z, float angle);
//------fdf_rotate_y.c---------------------------------//
void	ft_rotation_y(t_dot *dot, float angle);
int		ft_calc_ry_x(int x, int z, float angle);
int		ft_calc_ry_z(int x, int z, float angle);
//------fdf_rotate_z.c---------------------------------//
void	ft_rotation_z(t_dot *dot, float angle);
int		ft_calc_rz_x(int x, int y, float angle);
int		ft_calc_rz_y(int x, int y, float angle);
//------fdf_translate.c--------------------------------//
void	ft_translate_x(t_dot *dot, int shift);
void	ft_translate_y(t_dot *dot, int shift);
//------fdf_parsing.c--------------------------------//
int		ft_add_color(char *str);
int		ft_find_comma(char *str);
t_bool	ft_valid_file(char *argv);
char	*ft_get_map(char *argv);
t_dot	**ft_organise(int argc, char **argv, int lengh, int width);
//------fdf_parsing_utils.c--------------------------------//
ssize_t	ft_count_arg(char *str);
ssize_t	ft_count_len(char **line);
void	ft_put_data(t_base *base, char **str, int line, int col);
t_base	*ft_set_base(char **list, int len, int i, int j);
t_base	*ft_classify(char *str);
//------fdf_shifting.c--------------------------------//
int		ft_get_x(t_base *base);
int		ft_get_y(t_base *base);
t_dot	*ft_insert_map(t_base *base, t_tool tool);
void	ft_set_utility(t_base *base, t_tool *tool);
t_dot	**ft_apply_map(t_base *base, int lengh, int width);
//------fdf_utils.c--------------------------------//
void	ft_free_str(char *str, char **list);
void	ft_free_struct(t_dot **map);
//------fdf_link_points.c--------------------------------//
void	ft_link_points(t_vars *vars, t_dot **map);
#endif
