/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:43:17 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/20 18:28:16 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

void	print_help_2(void)
{
	char	*str;
	int		fd;

	fd = open("help_texts/help_2.txt", O_RDONLY);
	ft_printf("\033[96m");
	str = get_next_line(fd);
	while (str)
	{
		ft_printf("%s", str);
		free(str);
		ft_printf("\033[37m");
		str = get_next_line(fd);
	}
	close(fd);
}

void	print_help(void)
{
	char	*str;
	int		fd;

	fd = open("help_texts/help.txt", O_RDONLY);
	ft_printf("\033[93m\nINVALID INPUT\n\n");
	ft_printf("\033[96m");
	str = get_next_line(fd);
	while (str)
	{
		ft_printf("%s", str);
		free(str);
		ft_printf("\033[37m");
		str = get_next_line(fd);
	}
	close(fd);
	print_help_2();
}

void	print_controls(void)
{
	char	*str;
	int		fd;

	fd = open("help_texts/controls_help.txt", O_RDONLY);
	ft_printf("\033[32m\nVALID INPUT, CONGRATS!\n\n");
	ft_printf("\033[96m");
	str = get_next_line(fd);
	while (str)
	{
		ft_printf("%s", str);
		free(str);
		ft_printf("\033[37m");
		str = get_next_line(fd);
	}
	close(fd);
}
