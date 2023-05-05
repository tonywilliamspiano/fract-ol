/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:41:22 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/13 10:41:22 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	if (n == 0)
		return (0);
	while (s1[counter] && s2[counter] && counter < n - 1)
	{
		if (s1[counter] != s2[counter])
			break ;
		counter++;
	}
	if (s1[counter] != s2[counter])
		return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
	else
		return (0);
}
