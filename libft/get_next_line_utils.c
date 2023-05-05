/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:09:51 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:18:32 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_char_strlen(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_realloc(int count, char *str)
{
	char	*temp;

	if (count == 0)
		return (str);
	temp = malloc((count + 1) * BUFFER_SIZE + 1);
	if (temp == NULL)
		return (NULL);
	ft_bzero(temp, (count + 1) * BUFFER_SIZE + 1);
	ft_strlcpy(temp, str, count * BUFFER_SIZE + 1);
	if (str)
		free(str);
	return (temp);
}
