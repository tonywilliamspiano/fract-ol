/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:15:04 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 09:46:40 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, unsigned int len)
{
	unsigned int	i;
	char			*cpy;

	cpy = (char *)s;
	i = 0;
	while (i < len)
	{
		cpy[i] = '\0';
		i++;
	}
	return ;
}
