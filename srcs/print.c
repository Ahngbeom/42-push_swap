/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bbu0704@gmail.com>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 13:59:49 by bahn              #+#    #+#             */
/*   Updated: 2021/07/20 20:56:28 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_strupper(char *str)
{
    int     i;

    i = 0;
    while (str[i] != '\0')
        printf("\e[1;33m%c\e[0m", ft_toupper(str[i++]));
    printf("\n");
}

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
    // (void)frame;
    t_stack     *a;
    t_stack     *b;
    t_command   *cmd_list;
    
    a = frame->a;
    b = frame->b;
    cmd_list = frame->cmd_list;
    printf("\e[1;92mA\e[0m\t\t\e[1;96mB\e[0m\t\t[pivot(\e[1;92mA\e[0m) : \e[1;30;102m %d \e[0m, pivot(\e[1;96mB\e[0m) : \e[1;30;46m %d \e[0m]\n", frame->pivot_a, frame->pivot_b);
    printf("=====================\n");
	while (a != NULL || b != NULL || cmd_list != NULL)
	{
        if (a != NULL)
        {
            printf("\e[1;92m%d\e[0m\t\t", a->element);
            a = a->next;
        }
        else
            printf("\t\t");
        if (b != NULL)
        {
            printf("\e[1;96m%d\e[0m\t\t", b->element);
            b = b->next;
        }
        else
            printf("\t\t");
        if (cmd_list != NULL)
        {
            // printf("\e[1;33m%s\e[0m\n", cmd_list->cmd);
            print_strupper(cmd_list->cmd);
            cmd_list = cmd_list->next;
        }
        else
            printf("\n");
	}
    printf("\n");
    // usleep(5000);
}