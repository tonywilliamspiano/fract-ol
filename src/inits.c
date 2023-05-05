/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:25:08 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 16:37:02 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static void	odd_window_init(t_fractal *f)
{
	if (HEIGHT > WIDTH)
	{
		f->min.rl /= (HEIGHT / WIDTH);
		f->max.rl /= (HEIGHT / WIDTH);
	}
	else if (WIDTH > HEIGHT)
	{
		f->min.im /= (WIDTH / HEIGHT);
		f->max.im /= (WIDTH / HEIGHT);
	}
}

int	init_mlx(t_fractal *f, char *name)
{
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		return (0);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, name);
	if (!f->win_ptr)
		return (0);
	f->img.mlx_img = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	f->img.addr = mlx_get_data_addr(f->img.mlx_img,
			&f->img.bpp, &f->img.line_len, &f->img.endian);
	return (1);
}

void	init_fractal(t_fractal *f)
{
	f->max_iter = MAX_ITERATIONS;
	f->min = make_complex(-2.0, -2.0);
	f->max = make_complex(2.0, 2.0);
	odd_window_init(f);
	f->on = 0;
	f->c_on = 0;
	f->v_on = 0;
	f->p_on = 0;
	f->scale = 1;
}

t_complex	make_complex(double rl, double im)
{
	t_complex	num;

	num.rl = rl;
	num.im = im;
	return (num);
}
