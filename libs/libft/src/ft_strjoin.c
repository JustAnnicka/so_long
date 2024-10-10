/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 21:49:56 by aehrl             #+#    #+#             */
/*   Updated: 2024/04/22 22:14:06 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
	{
		errno = 12;
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	ft_strlcat(str, s2, size + 1);
	str[size] = '\0';
	return (str);
}

/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2);
	str = ft_calloc(size + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
*/