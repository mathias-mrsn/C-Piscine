#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	new->next = (*begin_list);
	(*begin_list) = new;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*res;

	i = -1;
	res = 0;
	while (++i < size)
		ft_list_push_front(&res, strs[i]);
	return (res);
}
