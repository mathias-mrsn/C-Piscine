/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:02:37 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/16 09:21:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

void	*btree_search_item(t_btree *root,
void *data_ref, int (*cmpf)(void *, void *))
{
	void	*left;
	void	*right;

	left = 0;
	right = 0;
	if (!root)
		return (NULL);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	left = btree_search_item(root->left, data_ref, cmpf);
	right = btree_search_item(root->right, data_ref, cmpf);
	if (left)
		return (left);
	if (right)
		return (right);
	return (NULL);
}
