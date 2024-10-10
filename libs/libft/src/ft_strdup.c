/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aehrl <aehrl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:30:18 by aehrl             #+#    #+#             */
/*   Updated: 2024/05/06 17:01:18 by aehrl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	size;

	size = ft_strlen(s1) + 1;
	cpy = malloc(size);
	if (!cpy)
	{
		errno = 12;
		return (NULL);
	}
	ft_memcpy(cpy, s1, size);
	return (cpy);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char source[] = "String to copy";
	char *target;
	char *target2;

	target = strdup(source);
	target2 = ft_strdup(source);

	printf("Orig: %s\n", target);
	printf("Mine: %s\n", target2);
	return (0);
}
*/