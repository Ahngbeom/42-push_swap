/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 16:34:16 by bahn              #+#    #+#             */
/*   Updated: 2021/05/31 16:36:58 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     length(t_stack *stack)
{
    int     length;
    t_stack *ptr;

    length = 0;
    ptr = stack;
    while (ptr != NULL)
    {
        length++;
        ptr = ptr->next;
    }
    return (length);
}