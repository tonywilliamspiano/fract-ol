/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:39:10 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/15 14:28:51 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*temp;

	temp = 0;
	while (*str)
	{
		if (*str == (unsigned char)c)
			temp = (char *)str;
		str++;
	}
	if (*str == (unsigned char)c)
		temp = (char *)str;
	return (temp);
}
