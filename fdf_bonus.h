/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:09:45 by jduval            #+#    #+#             */
/*   Updated: 2023/01/25 16:21:55 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"

typedef	enum e_zoom
{
	IN,
	OUT
}	t_zoom;

typedef enum e_side
{
	A_X,
	A_Y
}	t_side;

typedef enum e_key
{
	R = 114,
	F = 102,
	G = 103,
	E = 101,
	Q = 113,
	I = 105,
	O = 111,
	X = 120,
	Y = 121,
	Z = 122,
	W = 119,
	A = 97,
	D = 100,
	S = 115,
	UP = 65362,
	LEFT = 65361,
	RIGHT = 65363,
	DOWN = 65364,
	CTRL = 65507,
	ESC = 65307
}	t_key;

typedef struct s_shift
{
	int	set;
	int	r_x;
	int	r_y;
	int	r_z;
}	t_shift;

typedef struct s_datum
{
	t_vars	vars;
	t_shift	shift;
	int		zlim;
}	t_datum;

//------fdf_key_bonus.c-------------------------------------//
int		ft_key(int keycode, t_datum *database);
//------fdf_zoom_bonus.c-------------------------------------//
void	ft_zoom(t_vars *vars, int keycode, int *zlimit);
//------fdf_rotate_y_bonus.c-------------------------------------//
void	ft_rotation_y(t_dot *dot, float angle);
float	ft_calc_ry_x(float x, float z, float angle);
float	ft_calc_ry_z(float x, float z, float angle);
//------fdf_clear_bonus.c-------------------------------------//
void	ft_clear(t_vars *vars);
void	ft_reset_map(t_vars *vars);
//------fdf_reset_bonus.c-------------------------------------//
void	ft_reset_view(t_vars *vars);
void	ft_face_view(t_vars *vars);
//------fdf_translate_bonus.c-------------------------------------//
void	ft_translation(t_vars *vars, int keycode);
//------fdf_rotation_bonus.c-------------------------------------//
void	ft_rotation(t_vars *vars, t_shift *shift, int keycode);
//------fdf_aitoff.c-------------------------------------//
void	ft_aitoff(t_vars *vars);
#endif
