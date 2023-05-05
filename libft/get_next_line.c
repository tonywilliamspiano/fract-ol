/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awilliam <awilliam@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:09:48 by awilliam          #+#    #+#             */
/*   Updated: 2023/02/21 10:18:41 by awilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_helper(int count, char *read_str, char *saved_str)
{
	char	*temp;
	int		size;
	int		len;

	len = ft_char_strlen(saved_str, '\0');
	size = ((count + 1) * BUFFER_SIZE) + len;
	temp = malloc(size + 1);
	if (saved_str && temp)
		ft_strlcpy(temp, saved_str, len + 1);
	if (temp)
		ft_strlcpy(temp + len, read_str, size - len);
	if (saved_str)
		free(saved_str);
	return (temp);
}

char	*read_to_str(char *saved_str, int fd)
{
	char	*read_str;
	int		len;
	int		count;

	count = 0;
	len = BUFFER_SIZE;
	read_str = malloc((count + 1) * BUFFER_SIZE + 1);
	if (read_str == NULL)
		return (NULL);
	ft_bzero(read_str, BUFFER_SIZE + 1);
	while (len == BUFFER_SIZE && !ft_strchr(read_str, '\n'))
	{
		read_str = ft_realloc(count, read_str);
		if (read_str == NULL)
			return (NULL);
		len = read(fd, read_str + (count * BUFFER_SIZE), BUFFER_SIZE);
		count++;
	}
	saved_str = read_helper(count, read_str, saved_str);
	if (read_str)
		free (read_str);
	if (len == -1)
		ft_bzero(saved_str, ft_char_strlen(saved_str, '\0'));
	return (saved_str);
}

char	*make_new_saved(char *saved_str)
{
	char	*temp;
	int		old_len;
	int		new_len;

	if (!saved_str)
		return (NULL);
	old_len = ft_char_strlen(saved_str, '\n');
	new_len = ft_char_strlen(saved_str + old_len, '\0');
	temp = malloc(new_len + 1);
	if (temp)
		ft_strlcpy(temp, saved_str + old_len + 1, new_len + 1);
	free (saved_str);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*saved_str = NULL;
	char		*return_str;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!saved_str || !ft_strchr(saved_str, '\n'))
		saved_str = read_to_str(saved_str, fd);
	return_str = malloc(ft_char_strlen(saved_str, '\n') + 2);
	if (return_str)
		ft_bzero(return_str, ft_char_strlen(saved_str, '\n') + 2);
	if (return_str && saved_str)
	{
		ft_strlcpy(return_str, saved_str, ft_char_strlen(saved_str, '\n') + 2);
		saved_str = make_new_saved(saved_str);
	}
	if (return_str && !*return_str)
	{
		if (saved_str)
			free(saved_str);
		saved_str = NULL;
		free(return_str);
		return (NULL);
	}
	return (return_str);
}
