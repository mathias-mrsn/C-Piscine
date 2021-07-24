#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*res;

	res = begin_list;
	while (res->next)
		res = res->next;
	return (res);
}
