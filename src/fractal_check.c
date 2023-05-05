/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 09:51:17 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 17:21:16 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static int	fractal_check_julia(t_fractal *fractal)
{
	int			iter;
	t_complex	n;

	iter = 0;
	n = make_complex(fractal->c.rl, fractal->c.im);
	while (n.rl * n.rl + n.im * n.im <= 4 && iter < fractal->max_iter)
	{
		n = make_complex(
				n.rl * n.rl - n.im * n.im + fractal->konst.rl,
				2.0 * n.rl * n.im + fractal->konst.im);
		iter++;
	}
	return (iter);
}

static int	fractal_check_mandelbrot(t_fractal *fractal)
{
	int			iter;
	t_complex	n;

	iter = 0;
	n = make_complex(fractal->c.rl, fractal->c.im);
	while (n.rl * n.rl + n.im * n.im <= 4 && iter < fractal->max_iter)
	{
		n = make_complex(
				n.rl * n.rl - n.im * n.im + fractal->c.rl,
				2.0 * n.rl * n.im + fractal->c.im);
		iter++;
	}
	return (iter);
}

static int	fractal_check_burning(t_fractal *fractal)
{
	int			iter;
	t_complex	n;

	iter = 0;
	n = make_complex(fractal->c.rl, fractal->c.im);
	while (pow(n.rl, 2.0) + pow(n.im, 2.0) <= 4 && iter < fractal->max_iter)
	{
		n.rl = fabs(n.rl);
		n.im = fabs(n.im);
		n = make_complex(
				n.rl * n.rl - n.im * n.im + fractal->c.rl,
				2.0 * n.rl * n.im - fractal->c.im);
		iter++;
	}
	return (iter);
}

int	fractal_check(t_fractal *fractal)
{
	if (fractal->id == 1)
		return (fractal_check_mandelbrot(fractal));
	else if (fractal->id == 2)
		return (fractal_check_julia(fractal));
	else if (fractal->id == 0)
		return (fractal_check_burning(fractal));
	return (0);
}
