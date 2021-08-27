/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:51:59 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 13:12:29 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	apply_stack(t_frame *frame, t_stack *stack)
{
	t_stack	*ptr;

	if (frame->a == NULL)
	{
		frame->a = stack;
		frame->a->prev = NULL;
	}
	else
	{
		ptr = frame->a;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = stack;
		stack->prev = ptr;
	}
}

void	stack_init(t_frame *frame, char **argv)
{
	t_stack	*stack;
	int		i;

	i = 0;
	while (argv[i + 1] != NULL)
	{
		stack = (t_stack *)malloc(sizeof(t_stack));
		if (stack == NULL)
			ft_puterr();
		stack->element = ft_atoi(argv[i + 1]);
		stack->next = NULL;
		apply_stack(frame, stack);
		i++;
	}
}
