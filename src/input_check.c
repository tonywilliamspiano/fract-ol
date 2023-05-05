/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:23:12 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/22 13:03:00 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

int	julia_check(char *str, t_fractal *f)
{
	int	num;

	num = ft_atoi(str);
	if (num < 1 || num > 5)
		return (0);
	if (num == 1)
		f->konst = make_complex(-1.0, 0.272);
	if (num == 2)
		f->konst = make_complex(-0.776, -0.108);
	if (num == 3)
		f->konst = make_complex(-0.144, -0.67);
	if (num == 4)
		f->konst = make_complex(0.336, 0.432);
	if (num == 5)
		f->konst = make_complex(0.32, -0.036);
	return (1);
}

int	input_helper(int argc, char *argv[], t_fractal *f)
{
	int	i;

	i = 0;
	f->konst = make_complex(-1.0, 0.272);
	if (argc > 2 && f->id == 2)
	{
		if (julia_check(argv[2], f))
			i++;
	}
	if (argc > (2 + i))
		f->col2 = ft_atoi_base(argv[2 + i], "0123456789abcdef");
	if (argc > (3 + i))
		f->col1 = ft_atoi_base(argv[3 + i], "0123456789abcdef");
	return (1);
}

int	check_input(int argc, char *argv[], t_fractal *f)
{
	if (argc < 2 || argc > 5)
		return (0);
	f->id = -1;
	f->col1 = 0x400c06;
	f->col2 = 0xd47833;
	if (ft_strncmp(argv[1], "M", ft_strlen(argv[1])) == 0)
		f->id = 1;
	if (ft_strncmp(argv[1], "J", ft_strlen(argv[1])) == 0)
		f->id = 2;
	if (ft_strncmp(argv[1], "B", ft_strlen(argv[1])) == 0)
		f->id = 0;
	input_helper(argc, argv, f);
	if (f->id == -1 || f->col1 == -1 || f->col2 == -1)
		return (0);
	if (f->id != 2 && argc > 4)
		return (0);
	else
		return (1);
}
