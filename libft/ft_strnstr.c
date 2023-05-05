/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:10:23 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 10:25:05 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*helper(char *str, char *to_find, unsigned int len, unsigned int i);

char	*ft_strnstr(char *str, char *to_find, unsigned int len)
{
	char			*location;
	unsigned int	i;

	if (!*to_find)
		return (str);
	if (len == 0)
		return (0);
	i = 0;
	location = helper(str, to_find, len, i);
	return (location);
}

static char	*helper(char *str, char *to_find, unsigned int len, unsigned int i)
{
	unsigned int	j;
	char			*location;

	while (*str && i < len)
	{
		j = 0;
		location = str;
		if (*str == to_find[j])
		{
			while (to_find[j] && *str && i < len)
			{
				if (*str != to_find[j])
					break ;
				str++;
				j++;
			}
			if (!to_find[j] && (i + j) <= len)
				return (location);
		}
		str = location + 1;
		i++;
	}
	return (0);
}
