/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 01:26:17 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/15 01:29:54 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if(ac < 2)
        return (1);
    stack_a = NULL;
    stack_b = NULL;
    
    // Add conditions
    // TODO
    // check if the stack is ordered
    // TODO

    // radix short algorithm
    radix_short(&stack_a, &stack_b);


    // free the stack
    // TODO

    return (0);
}