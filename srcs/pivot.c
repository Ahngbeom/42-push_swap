/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/08/19 23:21:56 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     select_pivot(t_stack *stack, int limit)
{
    int     i;
    int     j;
    int     arr[length(stack)];
    int     temp;
    t_stack *ptr;

    i = 0;
    ptr = stack;
    while (i < length(stack))
    {
        arr[i++] = ptr->element;
        ptr = ptr->next;
    }
    i = 0;
    while (i < limit)
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
    return (arr[(limit - 1) / 2]);
}