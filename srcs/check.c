/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahn <bahn@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:55:42 by bahn              #+#    #+#             */
/*   Updated: 2021/08/22 17:02:20 by bahn             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  int ft_nbrlen(int num)
{
    int     i;
    int     n;
    
    i = 1;
    n = num;
    if (num >= 0)
    {
        while ((n / 10)> 0)
        {
            i++;
            n = n / 10;
        }
    }
    else
    {
        ++i;
        while ((n / 10) * -1 > 0)
        {
            i++;
            n = n / 10;
        }
    }
    return (i);
}
int     isInteger(char *str)
{
    int     i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        ++i;
    while (str[i] != '\0')
    {   
        if (!ft_isdigit(str[i]))
            return (1);
        if (ft_strlen(str) != ft_nbrlen(ft_atoi(str)))
            return (1);
        i++;
    }
    return (0);
}

int     invalid_arg(int argc, char *argv[])
{
    int     i;
	int	j;


    if (argc < 2)
    {
        ft_putendl_fd("Error", 1);
        exit(1);
    }
    i = 1;
    while (argv[i] != NULL)
    {
        if (isInteger(argv[i]))
        {

            ft_putendl_fd("Error", 1);
            exit(1);
        }
        j = i + 1;
        while (argv[j] != NULL)
        {
            if (ft_strncmp(argv[i], argv[j], ft_strlen(argv[i])) == 0)
            {
                if (ft_strlen(argv[i]) == ft_strlen(argv[j]))
                {
                    ft_putendl_fd("Error", 1);
                    exit(1);
                }
            }
            j++;
        }
        i++;
    }
    return (i - 1);
}

int     check_asc(t_stack *stack)
{
    t_stack     *i;
    t_stack     *j;
    
    i = stack;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->element > j->element)
                return (FALSE);
            j = j->next;
        }
        i = i->next;
    }
    return (TRUE);
}

int     check_desc(t_stack *stack)
{
    t_stack     *i;
    t_stack     *j;
    
    i = stack;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->element < j->element)
                return (FALSE);
            j = j->next;
        }
        i = i->next;
    }
    return (TRUE);
}