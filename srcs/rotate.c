/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:26:34 by bahn              #+#    #+#             */
/*   Updated: 2021/07/29 16:33:16 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     rotate_check(t_frame *frame, t_stack *stack)
{
    if (length(stack) < 2)
        return (FALSE);
    if (frame->a == stack && check_asc(stack) == FALSE)
    {
        if (stack->element == max(stack))
            return (TRUE);
        else if (frame->pivot_a < stack->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else if (frame->b == stack && check_desc(stack) == FALSE)
    {
        if (stack->element == min(stack))
            return (TRUE);
        else if (frame->pivot_b > stack->element)
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
    
    // if (rotate_check(frame, frame->b))
    //     rotate_r(frame);
    // else
    // {
        temp = frame->a;
        temp->prev = last_element(frame->a);
        frame->a = frame->a->next;
        frame->a->prev = NULL;
        last_element(frame->a)->next = temp;
        temp->next = NULL;
        add_command(frame, "ra");
        print_stack(frame);
    // }
    return (1);
}

int    rotate_b(t_frame *frame)
{
    t_stack *temp;
    
    // if (rotate_check(frame, frame->a))
    //     rotate_r(frame);
    // else
    // {
        temp = frame->b;
        temp->prev = last_element(frame->b);
        frame->b = frame->b->next;
        frame->b->prev = NULL;
        last_element(frame->b)->next = temp;
        temp->next = NULL;
        add_command(frame, "rb");
        print_stack(frame);
    // }
    return (1);
}

void    rotate_r(t_frame *frame)
{
    t_stack *temp;
    
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
