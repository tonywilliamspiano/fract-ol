/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_protocol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:42:47 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 16:46:35 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static double	interpolate(double start, double end, double zoom)
{
	return (start + ((end - start) * zoom));
}

static void	zoom(int button, t_complex m_pos, t_fractal *f)
{
	double	zoom;

	if (button == 5)
		zoom = 0.8;
	if (button == 4)
		zoom = 1.2;
	f->min.rl = interpolate(m_pos.rl, f->min.rl, zoom);
	f->min.im = interpolate(m_pos.im, f->min.im, zoom);
	f->max.rl = interpolate(m_pos.rl, f->max.rl, zoom);
	f->max.im = interpolate(m_pos.im, f->max.im, zoom);
	f->scale *= zoom;
	make_img(f);
}

int	mouse_protocol(int button, int x, int y, t_fractal *f)
{
	t_complex	m_pos;

	m_pos.rl = (double)x / (WIDTH / (f->max.rl - f->min.rl)) + f->min.rl;
	m_pos.im = (double)y / (HEIGHT / (f->max.im - f->min.im)) * -1 + f->max.im;
	if (button == 4 || button == 5)
		zoom(button, m_pos, f);
	if (button == 1 && f->on != 4 && f->id == 2)
	{
		f->konst = m_pos;
		make_img(f);
	}
	return (0);
}
