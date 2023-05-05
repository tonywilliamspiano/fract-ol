/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_protocol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:41 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/22 13:04:37 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static void	move(t_fractal *fractal, int dir)
{
	if (dir == 1)
	{
		fractal->min.rl -= (0.1 * fractal->scale);
		fractal->max.rl -= (0.1 * fractal->scale);
	}
	if (dir == 2)
	{
		fractal->min.rl += (0.1 * fractal->scale);
		fractal->max.rl += (0.1 * fractal->scale);
	}
	if (dir == 3)
	{
		fractal->min.im -= (0.1 * fractal->scale);
		fractal->max.im -= (0.1 * fractal->scale);
	}
	if (dir == 4)
	{
		fractal->min.im += (0.1 * fractal->scale);
		fractal->max.im += (0.1 * fractal->scale);
	}
}

static int	key_helper(int key, t_fractal *fractal)
{
	static int		max_iter = MAX_ITERATIONS;

	if (key == XK_w)
		max_iter += 10;
	else if (key == XK_s && max_iter > 2)
		max_iter -= (max_iter / 2);
	if (key == XK_Left)
		move(fractal, 1);
	else if (key == XK_Right)
		move(fractal, 2);
	else if (key == XK_Down)
		move(fractal, 3);
	else if (key == XK_Up)
		move(fractal, 4);
	fractal->max_iter = max_iter;
	return (0);
}

static double	key_helper_2(int key, t_fractal *f, double speed)
{
	if (key == XK_2)
	{
		if (f->on > 0)
			speed *= 1.3;
	}
	if (key == XK_1)
	{
		if (f->on > 0)
			speed /= 1.3;
	}
	if (key == XK_c && !f->p_on)
		f->c_on = (f->c_on + 1) % 2;
	if (key == XK_v && !f->p_on)
		f->v_on = (f->v_on + 1) % 2;
	if (key == XK_p)
		f->p_on = (f->p_on + 1) % 2;
	if (key == XK_r || key == XK_0)
		f->r_on = (f->r_on + 1) % 2;
	if (key == XK_e || key == XK_0)
		f->e_on = (f->e_on + 1) % 2;
	if (f->on > 0)
		f->on = speed;
	return (speed);
}

int	key_protocol(int key, t_fractal *fractal)
{
	static double	speed = 5.0;

	if (key == XK_Escape)
	{
		destroy_window(fractal);
		return (0);
	}
	else if (key == XK_space)
	{
		if (fractal->on == 0)
			fractal->on = speed;
		else if (fractal->on != -1)
			fractal->on = 0;
	}
	if (key == XK_f)
	{	
		fractal->id = (fractal->id + 1) % 3;
		init_fractal(fractal);
	}
	key_helper(key, fractal);
	speed = key_helper_2(key, fractal, speed);
	make_img(fractal);
	return (0);
}
