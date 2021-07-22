/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:26:34 by bahn              #+#    #+#             */
/*   Updated: 2021/07/22 14:27:18 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_a(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2)
        printf("ra : 해당 연산을 수행할 수 없습니다.\n");
    else if (length(frame->b) >= 2 && check_desc(frame->b) != 0 &&\
        (frame->b->element == min(frame->b) || frame->pivot_b > frame->b->element))
        rotate_r(frame);
    else
    {
        temp = frame->a;
        temp->prev = last_element(frame->a);
        frame->a = frame->a->next;
        frame->a->prev = NULL;
        last_element(frame->a)->next = temp;
        temp->next = NULL;
        add_command(frame, "ra");
        print_stack(frame);
    }
    
}

void    rotate_b(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2)
    {
        printf("rb : 해당 연산을 수행할 수 없습니다.\n");
        return ;
    }
    else if (length(frame->a) >= 2 && check_asc(frame->a) != 0 && \
        (frame->a->element == max(frame->a) || frame->pivot_a <= frame->a->element))
        rotate_r(frame);
    else
    {
        temp = frame->b;
        temp->prev = last_element(frame->b);
        frame->b = frame->b->next;
        frame->b->prev = NULL;
        last_element(frame->b)->next = temp;
        temp->next = NULL;
        add_command(frame, "rb");
        print_stack(frame);
    }
}

void    rotate_r(t_frame *frame)
{
    t_stack *temp;
    
    if (length(frame->a) < 2 || length(frame->b) < 2)
    {
        printf("rr : 해당 연산을 수행할 수 없습니다.\n");
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
    print_stack(frame);
}
