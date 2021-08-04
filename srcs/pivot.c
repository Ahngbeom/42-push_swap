/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/08/04 15:36:17 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     select_pivot(t_stack *stack, int max_seq)
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
    return (arr[max_seq]);
}