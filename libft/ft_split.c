/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:31:14 by awilliam          #+#    #+#             */
/*   Updated: 2022/12/21 15:01:20 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		mod_ft_strlen(const char *str, char c);
static int		word_count(const char *str, char c);
static void		free_strings(char **result, int index);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;

	i = 0;
	result = malloc(((word_count(s, c) + 1) * sizeof(char *)));
	if (result == NULL)
		return (0);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		result[i] = malloc(mod_ft_strlen(s, c) + 1);
		if (result[i] == NULL)
		{
			free_strings(result, i);
			return (0);
		}
		ft_strlcpy(result[i], s, mod_ft_strlen(s, c) + 1);
		i++;
		s += mod_ft_strlen(s, c);
		while (*s == c && c)
			s++;
	}
	result[i] = 0;
	return (result);
}

static void	free_strings(char **result, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(result[i]);
		i++;
	}
	free(result);
}

static int	word_count(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!c)
		return (1);
	if (!str || !*str)
		return (0);
	if (str[i] != c)
		count++;
	while (str[i + 1])
	{
		if (str[i] == c)
			if (str[i + 1] != c)
				count++;
		i++;
	}
	return (count);
}

static int	mod_ft_strlen(const char	*str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}
