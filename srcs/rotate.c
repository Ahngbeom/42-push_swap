/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:26:34 by bahn              #+#    #+#             */
/*   Updated: 2021/08/19 13:11:31 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     rotate_check(t_frame *frame, t_stack *stack)
{
    if (length(stack) < 2)
        return (FALSE);
    if (frame->a == stack && check_asc(stack) == FALSE)
    {
        if (stack->element == max(stack, length(frame->a)))
            return (TRUE);
        else if (frame->big_pivot < stack->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else if (frame->b == stack && check_desc(stack) == FALSE)
    {
        if (stack->element == min(stack, length(frame->b)))
            return (TRUE);
        else if (frame->small_pivot > stack->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else
        return (FALSE);
}

int    rotate_a(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2)
        return (1); 
    temp = frame->a;
    temp->prev = last_element(frame->a);
    frame->a = frame->a->next;
    frame->a->prev = NULL;
    last_element(frame->a)->next = temp;
    temp->next = NULL;
    add_command(frame, "ra");
    print_stack(frame);
    return (1);
}

int    rotate_b(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->b) < 2)
        return (1);
    temp = frame->b;
    temp->prev = last_element(frame->b);
    frame->b = frame->b->next;
    frame->b->prev = NULL;
    last_element(frame->b)->next = temp;
    temp->next = NULL;
    add_command(frame, "rb");
    print_stack(frame);
    return (1);
}

void    rotate_r(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2 || length(frame->b) < 2)
        return ;

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
    print_stack(frame);
}
