/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:59:49 by bahn              #+#    #+#             */
/*   Updated: 2021/08/18 19:23:47 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  t_command     *last_command(t_command *command)
{
    t_command     *ptr;
    
    if (command == NULL)
        return (NULL);
    ptr = command;
    while (ptr->next != NULL)   
        ptr = ptr->next;
    return (ptr);
}

// static  void    print_strupper(char *str)
// {
//     int     i;

//     i = 0;
//     while (str[i] != '\0')
//         printf("\e[1;33m%c\e[0m", ft_toupper(str[i++]));
//     printf("\n");
// }

void    print_command(t_command *cmd_list)
{
    t_command *ptr;

    ptr = cmd_list;
    while (ptr != NULL)
    {
        printf("%s\n", ptr->cmd);
        ptr = ptr->next;
    }
}

void    print_stack(t_frame *frame)
{
    (void)frame;
    t_stack     *a;
    t_stack     *b;
    t_command   *last_cmd;
    
    a = frame->a;
    b = frame->b;
    // cmd_list = frame->cmd_list;
    printf("\e[1;92mA\e[0m\t\t\e[1;96mB\e[0m\t\t[pivot(\e[1;92mA\e[0m) : \e[1;30;102m %d \e[0m, pivot(\e[1;96mB\e[0m) : \e[1;30;46m %d \e[0m]\n", frame->big_pivot, frame->small_pivot);
    printf("=====================");
    if ((last_cmd = last_command(frame->cmd_list)) != NULL)
        printf("\t\t\e[1;33m%s\e[0m\n", last_cmd->cmd);
    else
    {
        printf("\n");
    }
	while (a != NULL || b != NULL)
	{
        if (a != NULL)
        {
            // if (a->prev == NULL)
            //     printf("NULL->");
            // else
            //     printf("%d->", a->prev->element);
            printf("\e[1;92m%d\e[0m\t\t", a->element);
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
    // sleep(1);
}