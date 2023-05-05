/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:07:41 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:29:10 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fract_ol.h"

static int	ft_numlen(char *str, char *base);
static int	ft_domath(char *str, char *base, int len);

int	ft_atoi_base(char *str, char *base)
{
	int	len;

	len = (ft_numlen(str, base));
	if (!len)
		return (-1);
	return (ft_domath(str, base, len));
}

static int	ft_domath(char *str, char *base, int len)
{
	int	add;
	int	mult;
	int	result;

	result = 0;
	mult = 1;
	while (len >= 1)
	{
		add = ft_char_strlen(base, str[len - 1]);
		add *= mult;
		result += add;
		mult *= ft_strlen(base);
		len--;
	}
	return (result);
}

static int	ft_numlen(char *str, char *base)
{
	int	i;

	i = 0;
	while (str[i] && ft_strchr(base, str[i]))
		i++;
	if (str[i])
		return (0);
	return (i);
}
