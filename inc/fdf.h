/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kromain <kromain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 19:00:51 by kromain           #+#    #+#             */
/*   Updated: 2017/05/20 20:03:53 by kromain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define SIZE env->size
# define OFF_X env.horz
# define OFF_Y env.vert

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../minilibx/mlx.h"
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

/*
*** Establish proper key codes
*/

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_ZOOM_IN 12
# define KEY_ZOOM_OUT 13

/*
*** Establish different colors
*/

# define BLU 0x0099FF
# define GRE 0x83F52C
# define YEL 0xF3F315
# define RED 0xFF0099

typedef struct		s_env
{
	void	*mlx;
	void	*win;
	int		x1;
	int		y1;
	int		height;
	int		width;
	int		vert;
	int		horz;
	int		top;
	int		size;
	int		x2;
	int		y2;
	int		z;
	int		delt_x;
	int		delt_y;
	int		**grid;
}					t_env;

int					fdf(char *s);
void				error_out(int value, t_env *env);
t_env				parse_in(int fd);
void				show_controls(t_env *env);
void				show_banner(t_env *env);
int					image_loop(t_env *env);
void				set_bresenham(t_env *env, int i, int j);
t_env				organize_bresenham(t_env env);
void				run_bresenham(t_env env);

#endif
