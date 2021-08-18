/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:42:19 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 12:00:12 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack     *last_element(t_stack *stack)
{
    t_stack     *ptr;

    ptr = stack;
    while (ptr->next != NULL)
        ptr = ptr->next;
    return (ptr);
}

t_stack     *mid_element(t_stack *stack)
{
    t_stack     *ptr;
    int         count;

    count = 0;
    ptr = stack;
    while (count++ < length(stack) / 2)
        ptr = ptr->next;
    return (ptr);
}

int     min(t_stack *stack, int range)
{
    int         min;
    t_stack     *ptr;
    
    min = stack->element;
    ptr = stack->next;
    while (ptr != NULL && --range)
    {
        if (min > ptr->element)
            min = ptr->element;
        ptr = ptr->next;   
    }
    return (min);
}

int     max(t_stack *stack, int range)
{
    int         max;
    t_stack     *ptr;
    
    max = stack->element;
    ptr = stack->next;
    while (ptr != NULL && --range)
    {
        if (max < ptr->element)
            max = ptr->element;
        ptr = ptr->next;   
    }
    return (max);
}

int     median(t_stack *stack, int range)
{
    int     arr[length(stack)];
    t_stack *ptr;
    int     i;
    int     j;
    int     temp;
    
    if (length(stack) < 2)
        return (0);
    i = 0;
    ptr = stack;
    while (i < length(stack))
    {
        arr[i++] = ptr->element;
        ptr = ptr->next;
    }

    i = 0;
    while (i < length(stack) - 1)
    {
        j = i + 1;
        while (j < length(stack))
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
        i++;
    }
    return (arr[range / 2]);
}
