/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:33:37 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 13:16:24 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_asc(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->element > j->element)
				return (FALSE);
			j = j->next;
		}
		i = i->next;
	}
	return (TRUE);
}

int	check_desc(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i != NULL)
	{
		j = i->next;
		while (j != NULL)
		{
			if (i->element < j->element)
				return (FALSE);
			j = j->next;
		}
		i = i->next;
	}
	return (TRUE);
}
