/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:37 by bahn              #+#    #+#             */
/*   Updated: 2021/07/23 13:17:04 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     reverse_rotate_check(t_frame *frame, t_stack *stack)
{
    if (length(stack) < 2)
        return (FALSE);
    if (frame->a == stack && check_asc(stack) == FALSE)
    {
        if (frame->pivot_a > last_element(stack)->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else if (frame->b == stack && check_desc(stack) == FALSE)
    {
        if (frame->pivot_b < last_element(stack)->element)
            return (TRUE);
        else if (max(stack) == last_element(stack)->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else
        return (FALSE);
}

void    reverse_rotate_a(t_frame *frame)
{
    t_stack *temp;
    
    if (reverse_rotate_check(frame, frame->b))
        reverse_rotate_r(frame);
    temp = last_element(frame->a);
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = frame->a;
    frame->a->prev = temp;
    frame->a = temp;
    add_command(frame, "rra");
    print_stack(frame);
}

void    reverse_rotate_b(t_frame *frame)
{
    t_stack *temp;

    if (reverse_rotate_check(frame, frame->a))
        reverse_rotate_r(frame);
    temp = last_element(frame->b);
    temp->prev->next = NULL;
    temp->prev = NULL;
    temp->next = frame->b;
    frame->b->prev = temp;
    frame->b = temp;
    add_command(frame, "rrb");
    print_stack(frame);
}

void    reverse_rotate_r(t_frame *frame)
{
    t_stack *temp;
    
    temp = last_element(frame->a);
    temp->prev->next = NULL;
    temp->next = frame->a;
    frame->a = temp;

    temp = last_element(frame->b);
    temp->prev->next = NULL;
    temp->next = frame->b;
    frame->b = temp;
    
    add_command(frame, "rrr");
    print_stack(frame);
}