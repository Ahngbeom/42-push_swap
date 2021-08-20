/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:29:09 by bahn              #+#    #+#             */
/*   Updated: 2021/08/20 16:10:35 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     select_pivot(t_stack *stack, int limit, double ratio)
{
    t_stack *ptr;

    int     arr[limit];
    int     cnt;

    int     i;
    int     j;
    int     temp;

    ptr = stack;
    cnt = 0;
    while (cnt < limit)
    {
        arr[cnt++] = ptr->element;
        ptr = ptr->next;
    }
    
    i = 0;
    while (i < limit - 1)
    {
        j = i + 1;
        while (j < limit)
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
    return (arr[(int)(limit * ratio)]);
}

int     select_big_pivot(t_stack *stack, int limit)
{
    t_stack *ptr;

    int     arr[limit];
    int     cnt;

    int     i;
    int     j;
    int     temp;

    // int     min;
    // int     max;

    ptr = stack;
    cnt = 0;
    while (cnt < limit)
    {
        arr[cnt++] = ptr->element;
        ptr = ptr->next;
    }
    
    i = 0;
    while (i < limit - 1)
    {
        j = i + 1;
        while (j < limit)
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
    
    // cnt = 0;
    // while (cnt < limit)
    // {
    //     printf("%d\n", arr[cnt++]);
    // }

    return (arr[limit / 2]);
}

int     select_small_pivot(t_stack *stack, int limit)
{
    t_stack *ptr;

    int     arr[limit];
    int     cnt;

    int     i;
    int     j;
    int     temp;

    // int     min;
    // int     max;

    ptr = stack;
    cnt = 0;
    while (cnt < limit)
    {
        arr[cnt++] = ptr->element;
        ptr = ptr->next;
    }
    
    i = 0;
    while (i < limit - 1)
    {
        j = i + 1;
        while (j < limit)
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
    
    // cnt = 0;
    // while (cnt < limit)
    // {
    //     printf("%d\n", arr[cnt++]);
    // }

    return (arr[limit / 4]);
}