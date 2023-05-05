/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:07:03 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/20 17:21:39 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	destroy_window(t_fractal *f)
{
	f->c_on = 0;
	f->v_on = 0;
	f->on = -1;
	f->p_on = 0;
	make_img(f);
	mlx_destroy_window(f->mlx_ptr, f->win_ptr);
	mlx_destroy_image(f->mlx_ptr, f->img.mlx_img);
	f->win_ptr = NULL;
	return (0);
}

int	expose_protocol(t_fractal *f)
{
	make_img(f);
	return (0);
}
