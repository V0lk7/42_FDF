/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:17:09 by jduval            #+#    #+#             */
/*   Updated: 2023/01/12 14:31:10 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_add_color(char *str)
{
	int		result;
	char	color[8];

	result = ft_strlen(str);
	if ((str == NULL) || (result != 8 && ft_strncmp(str, "0x", 2) != 0))
		return (0x00FFFFFF);
	ft_strlcpy(color, "00", 2);
	ft_strlcat(color, &str[2], 8);
	result = ft_atoi_base(color, 16);
	if (result < 0)
		return (0x00FFFFFF);
	return (result);
}

int	ft_find_comma(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while(str[i])
	{
		if (str[i] == ',')
			return (i);
		i++;
	}
	return (-1);
}

t_bool	ft_valid_file(char *argv)
{
	char	*str;
	int		cmp;
	int		len;

	if (argv == NULL)
		return (FALSE);
	str = ft_strchr(argv, '.');
	if (str == NULL)
		return (FALSE);
	cmp = ft_strncmp(str, ".fdf", 4);
	len = ft_strlen(argv) - ft_strlen(str);
	if (cmp != 0 || len == 0)
		return (FALSE);
	else
		return (TRUE);
}

char	*ft_get_map(char *argv)
{
	int		fd;
	char	*str;
	char	*line;

	str = NULL;
	if (ft_valid_file(argv) == FALSE)
		exit(0);
	fd = open(argv, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin_free(str, line);
		free(line);
		if (str == NULL)
		{
			close(fd);
			exit (0);
		}
		line = get_next_line(fd);
	}
	close(fd);
	return (str);
}
/*
t_dot	**ft_organise(int argc, char **argv)
{
	char	*str;
	t_base	**base;
	t_dot	**map;

	if (argc != 2)
		exit (0);
	str = ft_get_map(argv[1]);
	if (str == NULL)
		exit (0);
	base = ft_classify(str);
	
}*/
