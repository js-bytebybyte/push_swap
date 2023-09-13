/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:55 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 16:48:52 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sb (swap b): swap the first 2 elements at the top of stack b
do nothing if there is only one or no elements
*/

void	ft_sb(t_stack **b)
{
	t_stack	*second;

	if (!*b || !(*b)->next)
		return ;
	second = *b;
	*b = (*b)->next;
	second->next = (*b)->next;
	(*b)->next = second;  
}

// pb (push b): take the 1st element at the top of a and put it at the top of b
// do nothing if a is empty

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
}

// rb (rotate b): shift up all elements of stack b by 1
// the first element becomes the last one

void	ft_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last_node;
	
	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	last_node = ft_last_list(*b);
	last_node->next = temp;
	temp->next = NULL;	
}

/*
 rrb (reverse rotate b): shift down all elements of stack b by 1
 the last element becomes the first one
*/

void	ft_rrb(t_stack **b)
{
	t_stack	*temp;
	int		i;

	i = 0;
	// store the address of the first node in a tmp pointer
	temp = *b; // 5850

	// loop through the stack until you find the last node
	// the head of the stack is now pointing to the last node
	// keep track of the number of nodes you need to loop through
	while ((*b)->next)
	{
		*b = (*b)->next; // 5820
		i++;
	}
	// assign the next pointer of the head to point to the 'old' first node (= stored in temp)
	(*b)->next = temp; 

	// go back to the before last node
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	// set the next pointer of the former last node to NULL
	temp->next = NULL;
}