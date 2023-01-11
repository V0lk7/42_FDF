/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:04:43 by jduval            #+#    #+#             */
/*   Updated: 2023/01/11 16:33:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_arg(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str == NULL || str[i] == '\0' || str[i] == ' ')
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] && str[i + 1] != ' ')
			j++;
		i++;
	}
	return (j + 1);
}

int	ft_count_len(char **line)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	if (line == NULL || *line == NULL)
		return (-1);
	tmp = ft_count_arg(line[i]);
	while (line[i] != NULL)
	{
		if (tmp != ft_count_arg(line[i]))
			return (-1);
		j += ft_count_arg(line[i]);	
		i++;
	}
	if (j <= 0)
		return (-1);
	return (j);
}

void	ft_put_data(t_base *base, char *line, int len, int i)
{
	int		i;
	int		index;

	i = 0;
	index = ft_find_comma(line);
	if (index > 0)
	{
		base->color = ft_add_color(&line[index]);
	}
	
}

t_base	**ft_set_base(char	**list, int len)
{
	char	**line;
	t_base	**base;
	int		i;
	int		j;

	i = 0;
	j = 0;
	base = malloc(sizeof(t_base *) * (len + 1));
	base[len + 1] = NULL;
	len = 0;
	while (list[i])
	{
		line = ft_split(list[i], ' ');
		if (line == NULL && len <= 0)
		{
			ft_free_str(NULL, list);
			exit(0);
		}
		while (line(len))
		{
			ft_put_data(base[j], line[len], len, i);
			j++;
			len++;
		}
		ft_free_str(NULL, line);
		i++;
	}
	return (base);
}

t_base	**ft_classify(char *str)
{
	char	**line;
	t_base	**base;
	int		len;

	line = ft_split(str, '\n');
	free(str);
	if (line == NULL)
		exit (0);
	len = ft_count_len(line);
	if (len <= 0)
	{
		ft_free_str(NULL, line);
		exit(0);
	}
	base = ft_set_base(line, len);
}
