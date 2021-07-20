/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:37:40 by bahn              #+#    #+#             */
/*   Updated: 2021/05/21 22:13:22 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (src == NULL)
		return (dest);
	i = 0;
	while (i < size && dest[i] != '\0')
	{
		j = 0;
		if (dest[i] == src[j])
		{
			while (dest[i + j] == src[j] && \
					(i + j) < size && src[j] != '\0')
				j++;
			if (src[j] == '\0')
				return (&dest[i]);
		}
		i++;
	}
	return (NULL);
}
