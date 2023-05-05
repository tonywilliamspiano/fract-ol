/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:22:24 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 11:27:19 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int		i;
	char	*p_src;
	char	*p_dst;

	p_src = (char *)src;
	p_dst = (char *)dst;
	if (!src && !dst)
		return (0);
	i = 0;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		i++;
	}
	return (p_dst);
}
