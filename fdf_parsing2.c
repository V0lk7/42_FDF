/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:04:43 by jduval            #+#    #+#             */
/*   Updated: 2023/01/26 13:13:27 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ssize_t	ft_count_arg(char *str)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	j = 0;
	if (str[i] == ' ')
		i++;
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

ssize_t	ft_count_len(char **line)
{
	ssize_t	i;
	ssize_t	j;
	ssize_t	tmp;

	i = 0;
	j = 0;
	if (line == NULL)
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

void	ft_put_data(t_base *base, char **str, int line, int col)
{
	int		index;

	index = ft_find_comma(str[col]);
	if (index >= 0)
		base->color_base = ft_add_color(&str[col][index + 1]);
	else
		base->color_base = 0xFFFFFF;
	base->z_base = ft_atoi(str[col]);
	base->column = col;
	base->line = line;
}

t_base	*ft_set_base(char **list, int len, int i, int j)
{
	char	**line;
	t_base	*base;

	base = malloc(sizeof(t_base) * len);
	if (base == NULL)
		return (NULL);
	while (i < len)
		base[i++].lengh = len;
	i = -1;
	while (list[++i])
	{
		len = -1;
		line = ft_split(list[i], ' ');
		if (line == NULL)
		{
			ft_free_str(NULL, list);
			exit(0);
		}
		while (line[++len])
			ft_put_data(&base[j++], line, i, len);
		ft_free_str(NULL, line);
	}
	return (base);
}

t_base	*ft_classify(char *str)
{
	char	**line;
	t_base	*base;
	ssize_t	len;

	line = ft_split(str, '\n');
	if (line == NULL)
	{
		ft_free_str(str, line);
		exit (0);
	}
	len = ft_count_len(line);
	if (len <= 1)
	{
		ft_free_str(str, line);
		exit(0);
	}
	base = ft_set_base(line, len, 0, 0);
	ft_free_str(str, line);
	if (base == NULL)
		exit (0);
	return (base);
}
