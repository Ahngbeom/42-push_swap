/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:26:34 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:42:07 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->a) < 2)
		return (1);
	temp = frame->a;
	temp->prev = last_element(frame->a);
	frame->a = frame->a->next;
	frame->a->prev = NULL;
	last_element(frame->a)->next = temp;
	temp->next = NULL;
	add_command(frame, "ra");
	return (1);
}

int	rotate_b(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->b) < 2)
		return (1);
	temp = frame->b;
	temp->prev = last_element(frame->b);
	frame->b = frame->b->next;
	frame->b->prev = NULL;
	last_element(frame->b)->next = temp;
	temp->next = NULL;
	add_command(frame, "rb");
	return (1);
}

void	rotate_r(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->a) < 2 || length(frame->b) < 2)
	{
		if (length(frame->a) >= 2 && length(frame->b) < 2)
			rotate_a(frame);
		else if (length(frame->a) < 2 && length(frame->b) >= 2)
			rotate_b(frame);
		return ;
	}
	temp = frame->a;
	temp->prev = last_element(frame->a);
	frame->a = frame->a->next;
	frame->a->prev = NULL;
	last_element(frame->a)->next = temp;
	temp->next = NULL;
	temp = frame->b;
	temp->prev = last_element(frame->b);
	frame->b = frame->b->next;
	frame->b->prev = NULL;
	last_element(frame->b)->next = temp;
	temp->next = NULL;
	add_command(frame, "rr");
}
