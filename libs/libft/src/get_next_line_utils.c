/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:49:58 by aehrl             #+#    #+#             */
/*   Updated: 2024/10/10 13:39:48 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	x;
	char	*src;
	int		i;

	src = (char *)s;
	x = (char)c;
	i = 0;
	if (x == '\0')
	{
		while (s[i++] != '\0')
			src++;
		return (src);
	}
	while (s[i] != '\0')
	{
		if (s[i] == x)
			return (src);
		i++;
		src++;
	}
	return (0);
}

void	*ft_gnl_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
		ptr[i++] = 0;
	return (ptr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_i;
	size_t	src_i;

	dst_i = ft_gnl_strlen(dst);
	src_i = 0;
	if (dst_i >= dstsize)
		return (dstsize + ft_gnl_strlen(src));
	while (src[src_i] != '\0' && src_i < dstsize - dst_i - 1)
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_i + src_i] = '\0';
	return (dst_i + ft_gnl_strlen(src));
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	if (!s1)
	{
		s1 = ft_gnl_calloc(1, sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	size = ft_gnl_strlen(s1) + ft_gnl_strlen(s2);
	str = ft_gnl_calloc((size + 1), sizeof(char));
	if (!str)
		return (free(str), NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	ft_strlcat(str, s2, size + 1);
	str[size] = '\0';
	return (free(s1), str);
}

size_t	ft_gnl_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
