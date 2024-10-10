/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 19:46:31 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/10 15:14:22 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string;
	size_t		i;	

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	string = ft_calloc(len + 1, sizeof(const char));
	if (!string)
	{
		errno = 12;
		return (NULL);
	}
	while (i < len && s[start + i] != '\0')
	{
		string[i] = s[i + start];
		i++;
	}
	string[len] = '\0';
	return (string);
}

/*
char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*string;
	char const	*cpy;
	
	cpy = s;
	if (!s)
		return (NULL);
	if (len == 0)
		len = 1;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	string = malloc(len + 1);
	if (!string)
	{	
		errno = 12;
		return (NULL);
	}
	if (ft_strlen(s) <= start)
		return (string);
	while (start-- > 0 && *cpy != '\0')
		cpy++;
	ft_memcpy(string, (const void *)cpy, len);
	string[len] = '\0';
	return (string);
}
*/