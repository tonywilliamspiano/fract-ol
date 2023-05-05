/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:12:43 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/13 13:01:17 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, int len)
{
	int		i;
	char	*cpy;

	cpy = (char *)b;
	i = 0;
	while (i < len)
	{
		cpy[i] = c;
		i++;
	}
	return (cpy);
}
