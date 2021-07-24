/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:02:27 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/16 08:02:28 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
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
