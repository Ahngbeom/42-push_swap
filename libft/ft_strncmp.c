/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 15:43:04 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 16:58:15 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n && ptr1[i] != '\0')
	{
		if (ptr1[i] == ptr2[i])
			i++;
		else
			return (ptr1[i] - ptr2[i]);
	}
	if (ptr1[i] == '\0' && i != n)
		return (ptr1[i] - ptr2[i]);
	return (0);
}
