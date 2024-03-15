/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rrettien <rrettien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:55:29 by rrettien          #+#    #+#             */
/*   Updated: 2023/11/28 12:25:20 by rrettien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*result;
	char		*buffer;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(leftover);
		buffer = NULL;
		leftover = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	result = fill_line(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!result)
		return (NULL);
	leftover = set_leftover(result);
	return (result);
}

char	*fill_line(int fd, char *leftover, char *buffer)
{
	ssize_t	read_value;
	char	*tmp_str;

	read_value = 1;
	while (read_value > 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == -1)
			return (free(leftover), NULL);
		else if (read_value == 0)
			break ;
		buffer[read_value] = '\0';
		if (!leftover)
			leftover = ft_calloc(1, 1);
		tmp_str = leftover;
		leftover = ft_strjoin(tmp_str, buffer);
		free(tmp_str);
		tmp_str = NULL;
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	return (leftover);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

char	*set_leftover(char *result)
{
	char	*left;
	int		i;

	i = 0;
	while (result[i] != '\n' && result[i] != '\0')
		i++;
	if (result[i] == 0 || result[1] == 0)
		return (NULL);
	left = ft_substr(result, i + 1, ft_strlen(result) - i);
	if (*left == 0)
	{
		free(left);
		left = NULL;
	}
	result[i + 1] = 0;
	return (left);
}
