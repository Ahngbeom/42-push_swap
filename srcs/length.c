/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:34:16 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:46:21 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length(t_stack *stack)
{
	t_stack	*ptr;
	int		length;

	ptr = stack;
	length = 0;
	while (ptr != NULL)
	{
		length++;
		ptr = ptr->next;
	}
	return (length);
}
