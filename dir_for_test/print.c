/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:59:49 by bahn              #+#    #+#             */
/*   Updated: 2021/08/24 16:26:40 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static  char     *last_command(char *cmd)
{
    char    *ptr;
    
    if (cmd == NULL)
        return (NULL);
    if (ft_strlen(cmd) <= 3)
        return (cmd);
    ptr = cmd + ft_strlen(cmd);
    while (*ptr != '\n')
    {
        ptr--;
    }
    return (++ptr);
}

void    print_stack(t_frame *frame)
{
    //// OFF
    // (void)frame;

    //// ON
    t_stack     *a;
    t_stack     *b;
    char        *used_cmd;
    
    a = frame->a;
    b = frame->b;
    printf("\e[1;92mA\e[0m\t\t\e[1;96mB\e[0m\t\t[pivot(\e[1;92mL\e[0m) : \e[1;30;102m %d \e[0m, pivot(\e[1;96mS\e[0m) : \e[1;30;46m %d \e[0m]\n", frame->big_pivot, frame->small_pivot);
    printf("=====================");
    if ((used_cmd = last_command(frame->cmd)) != NULL)
        printf("\t\t\e[1;33m%s\e[0m\n", used_cmd);
    else
    {
        printf("\n");
    }
	while (a != NULL || b != NULL)
	{
        if (a != NULL)
        {
            //// Simple Stack
            printf("\e[1;92m%d\e[0m\t\t", a->element);

            //// Detail Stack
            // if (a->prev == NULL)
            //     printf("NULL->");
            // else
            //     printf("%d->", a->prev->element);
            // printf("\e[1;92m%d\e[0m", a->element);
            // if (a->next == NULL)
            //     printf("->NULL\t\t");
            // else
            //     printf("->%d\t\t", a->next->element);
            
            a = a->next;
        }
        else
            printf("\t\t");
        if (b != NULL)
        {
            printf("\e[1;96m%d\e[0m\n", b->element);
            b = b->next;
        }
        else
            printf("\n");
	}
    printf("\n");
    //// Printing Delay
    // sleep(1);
}