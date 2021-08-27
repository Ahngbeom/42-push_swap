/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:29 by bahn              #+#    #+#             */
/*   Updated: 2021/08/27 15:44:25 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_frame *frame)
{
	t_stack	*temp;

	temp = frame->a->next;
	frame->a->prev = temp;
	frame->a->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = frame->a;
	temp->prev = NULL;
	temp->next = frame->a;
	frame->a = temp;
	add_command(frame, "sa");
}

void	swap_b(t_frame *frame)
{
	t_stack	*temp;

	temp = frame->b->next;
	frame->b->prev = temp;
	frame->b->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = frame->b;
	temp->prev = NULL;
	temp->next = frame->b;
	frame->b = temp;
	add_command(frame, "sb");
}

void	swap_s(t_frame *frame)
{
	t_stack	*temp;

	temp = frame->a->next;
	frame->a->prev = temp;
	frame->a->next = temp->next;
	temp->prev = NULL;
	temp->next = frame->a;
	frame->a = temp;
	temp = frame->b->next;
	frame->b->prev = temp;
	frame->b->next = temp->next;
	temp->prev = NULL;
	temp->next = frame->b;
	frame->b = temp;
	add_command(frame, "ss");
}
