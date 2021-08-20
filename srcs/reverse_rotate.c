/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 13:42:37 by bahn              #+#    #+#             */
/*   Updated: 2021/08/20 21:03:33 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     reverse_rotate_check(t_frame *frame, t_stack *stack)
{
    if (length(stack) < 2)
        return (FALSE);
    if (frame->a == stack && check_asc(stack) == FALSE)
    {
        if (frame->big_pivot > last_element(stack)->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else if (frame->b == stack && check_desc(stack) == FALSE)
    {
        if (frame->small_pivot < last_element(stack)->element)
            return (TRUE);
        else if (max(stack, length(frame->b)) == last_element(stack)->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else
        return (FALSE);
}

int    reverse_rotate_a(t_frame *frame)
{
    t_stack *temp;
    
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

int    reverse_rotate_b(t_frame *frame)
{
    t_stack *temp;

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

void    reverse_rotate_r(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2 && length(frame->b) >= 2)
    {
        reverse_rotate_b(frame);
        return ;
    }
    if (length(frame->b) >= 2 && length(frame->b) < 2)
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