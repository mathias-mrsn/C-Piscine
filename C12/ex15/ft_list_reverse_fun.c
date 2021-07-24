#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*list;
	unsigned int	i;

	i = 0;
	list = begin_list;
	while (list && i <= nbr)
	{
		if (i == nbr)
			return (list);
		list = list->next;
		i++;
	}
	return (0);
}

unsigned int	ft_list_size(t_list *begin_list)
{
	unsigned int	i;
	t_list			*tmp;

	i = 0;
	tmp = begin_list;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	sb;
	unsigned int	se;
	void			*tmp;

	sb = 0;
	se = ft_list_size(begin_list);
	while (sb < se / 2)
	{
		tmp = ft_list_at(begin_list, sb)->data;
		ft_list_at(begin_list, sb)->data = ft_list_at(begin_list,
			se - sb - 1)->data;
		ft_list_at(begin_list, se - sb - 1)->data = tmp;
		sb++;
	}
}
