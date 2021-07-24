/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:02:42 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/18 09:04:13 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node_bis(void *item)
{
	t_btree	*res;

	res = malloc(sizeof(t_btree) * 1);
	if (!res)
		return (NULL);
	res->item = item;
	res->left = 0;
	res->right = 0;
	return (res);
}

void	btree_push_left(t_btree **root, void *item)
{
	t_btree	*tmp;

	tmp = *root;
	if (!tmp)
		*root = btree_create_node_bis(item);
	else
	{
		while (tmp)
		{
			if (!tmp->left)
			{
				tmp->left = btree_create_node_bis(item);
				return ;
			}
			tmp = tmp->left;
		}
	}
}

void	btree_at_level_bis(t_btree *root, t_btree **res, int level)
{
	if (root && level == 0)
	{
		btree_push_left(res, root->item);
	}
	else if (root)
	{
		btree_at_level_bis(root->left, res, level - 1);
		btree_at_level_bis(root->right, res, level - 1);
	}
}

int	btree_level_count_bis(t_btree *root)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 0;
	if (root->left)
		nb1 = btree_level_count_bis(root->left);
	if (root->right)
		nb2 = btree_level_count_bis(root->right);
	if (nb1 > nb2)
		return (nb1 + 1);
	else
		return (nb2 + 1);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
int current_level, int is_first_elem))
{
	t_btree	*level;
	int		size;
	int		first;
	int		i;

	if (!root)
		return ;
	size = btree_level_count_bis(root);
	i = 0;
	while (i < size)
	{
		level = 0;
		first = 0;
		btree_at_level_bis(root, &level, i);
		while (level)
		{
			applyf(level->item, i, first == 0);
			level = level->left;
			first++;
		}
		i++;
	}
}
