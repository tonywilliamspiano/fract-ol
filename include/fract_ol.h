/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:19 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/22 13:12:26 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define HEIGHT 700
# define WIDTH 700

# ifndef MAX_ITERATIONS
#  define MAX_ITERATIONS 50
# endif

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_complex
{
	double	rl;
	double	im;
}	t_complex;

typedef struct s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	int			max_iter;
	t_complex	min;
	t_complex	max;
	t_complex	c;
	t_complex	factor;
	t_complex	konst;
	int			id;
	double		on;
	int			r_on;
	int			e_on;
	int			c_on;
	int			v_on;
	int			p_on;
	int			col1;
	int			col2;
	double		scale;
}	t_fractal;

int			mouse_protocol(int button, int x, int y, t_fractal *fractal);
int			key_protocol(int key, t_fractal *fractal);
void		make_img(t_fractal *fractal);
int			fractal_check(t_fractal *fractal);
int			init_mlx(t_fractal *f, char *name);
void		init_fractal(t_fractal *fractal);
t_complex	make_complex(double rl, double im);
int			get_color(double max_iter, double iterations, t_fractal *fractal);
int			ft_atoi_base(char *str, char *base);

int			no_event(t_fractal *fractal);
int			check_input(int argc, char *argv[], t_fractal *fractal);
void		print_help(void);
void		print_controls(void);

int			destroy_window(t_fractal *fractal);
int			expose_protocol(t_fractal *fractal);

#endif