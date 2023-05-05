/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:33:40 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 11:53:08 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_numlen(const char *str);
static int	ft_isspace(int c);
static int	ft_domath(const char *str, int len, int neg);

int	ft_atoi(const char *str)
{
	int	len;
	int	result;
	int	neg;

	neg = 1;
	result = 0;
	while (ft_isspace(*str))
		str++;
	if (ft_numlen(str) == 0)
	{
		if (*str == '-')
			neg = -1;
		else if (*str != '+')
			return (0);
		str++;
	}
	len = (ft_numlen(str));
	if (!len)
		return (0);
	result = ft_domath(str, len, neg);
	return (result);
}

static int	ft_domath(const char *str, int len, int neg)
{
	int	add;
	int	mult;
	int	result;

	result = 0;
	mult = neg;
	while (len >= 1)
	{
		add = (str[len - 1]) - 48;
		add *= mult;
		result += add;
		mult *= 10;
		len--;
	}
	return (result);
}

static int	ft_numlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static int	ft_isspace(int c)
{
	if (c >= 9 && c <= 13)
		return (1);
	else if (c == ' ')
		return (1);
	else
		return (0);
}
