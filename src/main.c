/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:28:05 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 16:37:38 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;

	if (check_input(argc, argv, &fractal) == 0)
	{
		print_help();
		return (0);
	}
	print_controls();
	if (!init_mlx(&fractal, "Fractal Display"))
		return (1);
	init_fractal(&fractal);
	make_img(&fractal);
	mlx_loop_hook(fractal.mlx_ptr, &no_event, &fractal);
	mlx_key_hook(fractal.win_ptr, &key_protocol, &fractal);
	mlx_mouse_hook(fractal.win_ptr, &mouse_protocol, &fractal);
	mlx_hook(fractal.win_ptr, 17, 0, &destroy_window, &fractal);
	mlx_expose_hook(fractal.win_ptr, &expose_protocol, &fractal);
	mlx_loop(fractal.mlx_ptr);
	mlx_destroy_display(fractal.mlx_ptr);
	free(fractal.mlx_ptr);
}
