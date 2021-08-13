/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 13:47:29 by bahn              #+#    #+#             */
/*   Updated: 2021/08/13 22:09:01 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     swap_check(t_frame *frame, t_stack *stack)
{
    if (length(stack) < 2)
        return (FALSE);
    if (frame->a == stack)
    {   
        if (stack->element > stack->next->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else if (frame->b == stack)
    {   
        if (stack->element < stack->next->element)
            return (TRUE);
        else
            return (FALSE);
    }
    else
    {
        printf("ERROR\n");
        exit(1);
    }
}

void     swap_a(t_frame *frame)
{
    t_stack     *temp;

    // if (swap_check(frame, frame->b))
    //     swap_s(frame);
    // else
    // {
        temp = frame->a->next;
        frame->a->prev = temp;
        frame->a->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->a;
        frame->a = temp;
        add_command(frame, "sa");
        print_stack(frame);
    // }
}

void       swap_b(t_frame *frame)
{
    t_stack     *temp;

    // if (swap_check(frame, frame->a))
    //     swap_s(frame);
    // else
    // {
        temp = frame->b->next;
        frame->b->prev = temp;
        frame->b->next = temp->next;
        temp->prev = NULL;
        temp->next = frame->b;
        frame->b = temp;
        add_command(frame, "sb");
        print_stack(frame);
    // }
}

void       swap_s(t_frame *frame)
{
    t_stack     *temp;

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
    print_stack(frame);
}