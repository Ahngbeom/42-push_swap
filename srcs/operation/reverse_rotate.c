/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:37 by bahn              #+#    #+#             */
/*   Updated: 2021/09/01 15:38:44 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->a) < 2)
		return (1);
	temp = last_element(frame->a);
	(temp->prev)->next = NULL;
	temp->prev = NULL;
	temp->next = frame->a;
	frame->a->prev = temp;
	frame->a = temp;
	add_command(frame, "rra");
	return (1);
}

int	reverse_rotate_b(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->b) < 2)
		return (1);
	temp = last_element(frame->b);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = frame->b;
	frame->b->prev = temp;
	frame->b = temp;
	add_command(frame, "rrb");
	return (1);
}

void	reverse_rotate_r(t_frame *frame)
{
	t_stack	*temp;

	if (length(frame->a) < 2 && length(frame->b) >= 2)
	{
		reverse_rotate_b(frame);
		return ;
	}
	if (length(frame->a) >= 2 && length(frame->b) < 2)
	{
		reverse_rotate_a(frame);
		return ;
	}
	temp = last_element(frame->a);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = frame->a;
	frame->a->prev = temp;
	frame->a = temp;
	temp = last_element(frame->b);
	temp->prev->next = NULL;
	temp->prev = NULL;
	temp->next = frame->b;
	frame->b->prev = temp;
	frame->b = temp;
	add_command(frame, "rrr");
}
