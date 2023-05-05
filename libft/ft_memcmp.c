/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:03:47 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/15 13:56:31 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(void *s1, void *s2, unsigned int n)
{
	unsigned int	counter;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	p_s1 = s1;
	p_s2 = s2;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (p_s1[counter] != p_s2[counter])
			return (p_s1[counter] - p_s2[counter]);
		counter++;
	}	
	return (0);
}
