/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:33:58 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 16:41:49 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static int	c_interpolate(int col1, int col2, double percent)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((col1 >> 16) & 0xFF);
	start_rgb[1] = ((col1 >> 8) & 0xFF);
	start_rgb[2] = ((col1 >> 0) & 0xFF);
	end_rgb[0] = ((col2 >> 16) & 0xFF);
	end_rgb[1] = ((col2 >> 8) & 0xFF);
	end_rgb[2] = ((col2 >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * percent + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * percent + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * percent + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
}

int	get_color(double max_i, double i, t_fractal *fractal)
{
	if (i == max_i)
		return (0);
	return (c_interpolate(fractal->col1, fractal->col2, pow(i / max_i, 0.9)));
}
