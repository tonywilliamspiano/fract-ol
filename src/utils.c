/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:56:14 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 17:47:26 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static int	shift_helper(int *rgb, int min, int max)
{
	static int			i = 0;

	if (rgb[i] < max)
		rgb[i]++;
	if (rgb[(i + 1) % 3] > min)
		rgb[(i + 1) % 3]--;
	if (rgb[i] >= max)
		i = (i + 1) % 3;
	return (0xFF << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	color_shift(t_fractal *f, int color, int x)
{
	int					rgb[3];
	static unsigned int	i = 0;

	rgb[0] = ((color >> 16) & 0xFF);
	rgb[1] = ((color >> 8) & 0xFF);
	rgb[2] = ((color >> 0) & 0xFF);
	if (x == 1 && i % 2 == 0)
		f->col1 = shift_helper(&rgb[0], 0, 70);
	else if (!x)
		f->col2 = shift_helper(&rgb[0], 150, 255);
	else if (x == 2 && i % 2 == 0)
	{
		f->col1 += 1000;
		f->col2 += 700;
	}
	i++;
	make_img(f);
}

int	no_event(t_fractal *fractal)
{
	if (fractal->id == 2 && fractal->on > 0)
	{
		if (fractal->r_on == 0)
			fractal->konst.rl += (0.005 / fractal->on);
		else
			fractal->konst.rl -= (0.005 / fractal->on);
		if (fractal->e_on == 0)
			fractal->konst.im += (0.005 / fractal->on);
		else
			fractal->konst.im -= (0.005 / fractal->on);
		make_img(fractal);
	}
	if (fractal->konst.rl > 2.0 || fractal->konst.rl < -2.0)
		fractal->r_on = (fractal->r_on + 1) % 2;
	if (fractal->konst.im > 2.0 || fractal->konst.im < -2.0)
		fractal->e_on = (fractal->e_on + 1) % 2;
	if (fractal->c_on)
		color_shift(fractal, fractal->col1, 1);
	if (fractal->v_on)
		color_shift(fractal, fractal->col2, 0);
	if (fractal->p_on)
		color_shift(fractal, fractal->col2, 2);
	return (0);
}
