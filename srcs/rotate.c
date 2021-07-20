/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 18:26:34 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 18:39:19 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate(t_frame *frame, char target)
{
    t_stack *temp;
    
    if (target == 'A')
    {
        temp = frame->a;
        temp->prev = last_element(frame->a);
        frame->a = frame->a->next;
        frame->a->prev = NULL;
        last_element(frame->a)->next = temp;
        temp->next = NULL;
        // frame->cmd = ft_strjoin(frame->cmd, "ra\n");
        add_command(frame, "ra");
        print_stack(frame);
    }
    else if (target == 'B')
    {
        temp = frame->b;
        temp->prev = last_element(frame->b);
        frame->b = frame->b->next;
        frame->b->prev = NULL;
        last_element(frame->b)->next = temp;
        temp->next = NULL;
        // frame->cmd = ft_strjoin(frame->cmd, "rb\n");
        add_command(frame, "rb");
        print_stack(frame);
    }
    else if (target == 'R')
    {
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

        // frame->cmd = ft_strjoin(frame->cmd, "rr\n");
        add_command(frame, "rr");
        print_stack(frame);
    }
    else
        exit(1);
}

void    reverse_rotate(t_frame *frame, char target)
{
    t_stack *temp;
    
    if (target == 'A')
    {
        temp = last_element(frame->a);
        temp->prev->next = NULL;
        temp->prev = NULL;
        temp->next = frame->a;
        frame->a->prev = temp;
        frame->a = temp;
        // frame->cmd = ft_strjoin(frame->cmd, "rra\n");
        add_command(frame, "rra");
        print_stack(frame);
    }
    else if (target == 'B')
    {
        temp = last_element(frame->b);
        temp->prev->next = NULL;
        temp->prev = NULL;
        temp->next = frame->b;
        frame->b->prev = temp;
        frame->b = temp;
        // frame->cmd = ft_strjoin(frame->cmd, "rrb\n");
        add_command(frame, "rrb");
        print_stack(frame);
    }
    else if (target == 'R')
    {
        temp = last_element(frame->a);
        temp->prev->next = NULL;
        temp->next = frame->a;
        frame->a = temp;

        temp = last_element(frame->b);
        temp->prev->next = NULL;
        temp->next = frame->b;
        frame->b = temp;
        
        // frame->cmd = ft_strjoin(frame->cmd, "rrr\n");
        add_command(frame, "rrr");
        print_stack(frame);
    }
    else
        exit(1);
}