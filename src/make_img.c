/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:48:18 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 16:48:55 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	make_img(t_fractal *f)
{
	int	y;
	int	x;
	int	color;

	y = 0;
	f->factor.rl = (f->max.rl - f->min.rl) / WIDTH;
	f->factor.im = (f->max.im - f->min.im) / HEIGHT;
	while (y < HEIGHT)
	{
		f->c.im = f->max.im - y * f->factor.im;
		x = 0;
		while (x < WIDTH)
		{
			f->c.rl = f->min.rl + x * f->factor.rl;
			color = get_color(f->max_iter, fractal_check(f), f);
			img_pix_put(&f->img, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.mlx_img, 0, 0);
}
