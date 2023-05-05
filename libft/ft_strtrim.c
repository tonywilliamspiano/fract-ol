/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:03:50 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/15 12:21:36 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	int		beg;
	int		end;
	int		len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	beg = 0;
	end = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[beg]) && s1[beg])
		beg++;
	while (ft_strchr(set, s1[len - end - 1]) && (len - end - 1 > 0))
		end++;
	len = len - beg - end;
	if (len <= 0)
		return (ft_strdup(""));
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (0);
	ft_strlcpy(new_str, &s1[beg], len + 1);
	return (new_str);
}
