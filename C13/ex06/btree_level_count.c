/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:02:39 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/16 08:02:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

int	max(int	nb1, int nb2)
{
	if (nb1 < nb2)
		return (nb2);
	else
		return (nb1);
}

int	btree_level_count(t_btree *root)
{
	int	nb1;
	int	nb2;

	nb1 = 0;
	nb2 = 0;
	if (root->left)
		nb1 = btree_level_count(root->left);
	if (root->right)
		nb2 = btree_level_count(root->right);
	return (max(nb1, nb2) + 1);
}
