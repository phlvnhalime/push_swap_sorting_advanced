/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpehliva <hpehliva@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 18:06:16 by hpehliva          #+#    #+#             */
/*   Updated: 2025/12/19 09:27:03 by hpehliva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/push_swap.h"

t_stack *find_smallest_element(t_stack *a)
{
  t_stack *small;
  t_stack *curr;

  small = NULL;
  curr = a;
  while(curr)
  {
    if(curr->index == -1)
    {
      if(small == NULL || curr->value < small->value)
        small = curr;
    }
    curr = curr->next;
  }
  return (small);

}



int	abs_i(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	set_positions(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		i++;
		stack = stack->next;
	}
}


int	find_min_index_pos(t_stack *a)
{
	int		min_i;
	int		min_pos;
	t_stack	*cur;

	if (!a)
		return (0);
	set_positions(a);
	min_i = a->index;
	min_pos = a->pos;
	cur = a;
	while (cur)
	{
		if (cur->index < min_i)
		{
			min_i = cur->index;
			min_pos = cur->pos;
		}
		cur = cur->next;
	}
	return (min_pos);
}

void	clear_keep(t_stack *a)
{
	while (a)
	{
		a->keep = false;
		a = a->next;
	}
}
