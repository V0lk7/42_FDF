/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:07:22 by jduval            #+#    #+#             */
/*   Updated: 2023/01/13 15:11:06 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../fdf.h"

static	int	ft_cmp(char *s1)
{
	if (s1 == NULL)
		return 0;
	else 
		return (1);
}

TEST	valid_file(void)
{
	char	*str = "42.fdf";
	char	*str1 = "oh hey .fdf";
	char	*str2 = " .fdf";
	char	*str3 = "0.fdf";
	char	*str4 = "42fdf.";
	char	*str5 = ".42fdf";
	char	*str6 = NULL;	
	char	*str7 = ".";
	char	*str8 = "oh hey .fd";
	char	*str9 = "";

	ASSERT_EQ(TRUE, ft_valid_file(str));
	ASSERT_EQ(TRUE, ft_valid_file(str1));
	ASSERT_EQ(TRUE, ft_valid_file(str2));
	ASSERT_EQ(TRUE, ft_valid_file(str3));
	ASSERT_EQ(FALSE, ft_valid_file(str4));
	ASSERT_EQ(FALSE, ft_valid_file(str5));
	ASSERT_EQ(FALSE, ft_valid_file(str6));
	ASSERT_EQ(FALSE, ft_valid_file(str7));
	ASSERT_EQ(FALSE, ft_valid_file(str8));
	ASSERT_EQ(FALSE, ft_valid_file(str9));
	PASS();
}

TEST	get_map(void)
{
	char	*str = NULL;
	int		i;

	str = ft_get_map("tests/maps/1.fdf");
	i = strcmp(str, "0 0 0  \n");
	ASSERT_EQ(0, i);
	free(str);
	str = ft_get_map("tests/maps/2.fdf");
	i = strcmp(str, "00000\n");
	ASSERT_EQ(0, i);
	free(str);
	str = ft_get_map("tests/maps/3.fdf");
	i = strcmp(str, "\n");
	ASSERT_EQ(0, i);
	free(str);
	str = ft_get_map("tests/maps/4.fdf");
	i = strcmp(str, "\n000\n00\n000000\n0\n");
	ASSERT_EQ(0, i);
	free(str);
	str = ft_get_map("tests/maps/empty.fdf");
	i = ft_cmp(str);
	ASSERT_EQ_FMT(0, i, "%d");
	PASS();
}

///////////////////////////////////////////////////////////
char	*list[] = {"je suis ton pere",
"et ouais",
" allo ?? FUCK OF !",
" ",
NULL,
};

char	*list2[] = {" je",
 "",
NULL,
};

char	*list3[] = {"0 0 0 0",
"0 0 0 0",
"0 0 0 0",
"0 0 0 0",
"0 0 0 0",
NULL,
};

char	*list4[] = {"0 0 0 0",
"0 0 0 0",
"0 0 0 0",
"0 0 0",
"0 0 0 0",
NULL,
};

char	*list5[] = {"0 0 0",
"0 0 0",
"0 0 0",
"0 0 0",
NULL,
};

char	*list6[] = {"0 0",
NULL,
};

char	*list7[] = {"0",
"0",
NULL,
};

////////////////////////////////////////////////////////////

TEST	listlen(void)
{
	ASSERT_EQ(4, ft_listlen(list));
	ASSERT_EQ(0, ft_listlen(NULL));
	PASS();
}

TEST	count_arg(void)
{
	ASSERT_EQ_FMT(4, ft_count_arg(list[0]), "%d");
	ASSERT_EQ_FMT(2, ft_count_arg(list[1]), "%d");
	ASSERT_EQ_FMT(0, ft_count_arg(list[2]), "%d");
	ASSERT_EQ_FMT(0, ft_count_arg(list2[0]), "%d");
	ASSERT_EQ_FMT(0, ft_count_arg(list2[1]), "%d");
	ASSERT_EQ_FMT(0, ft_count_arg(list2[2]), "%d");
	PASS();
}

TEST	count_len(void)
{
	ASSERT_EQ_FMT(-1, ft_count_len(list), "%d");
	ASSERT_EQ_FMT(-1, ft_count_len(list2), "%d");
	ASSERT_EQ_FMT(20, ft_count_len(list3), "%d");
	ASSERT_EQ_FMT(-1, ft_count_len(list4), "%d");
	ASSERT_EQ_FMT(-1, ft_count_len(NULL), "%d");
	PASS();
}

TEST	find_comma(void)
{
	ASSERT_EQ_FMT(-1, ft_find_comma(""), "%d");
	ASSERT_EQ_FMT(-1, ft_find_comma(NULL), "%d");
	ASSERT_EQ_FMT(2, ft_find_comma("10,0x00FFFFFF"), "%d");
	ASSERT_EQ_FMT(2, ft_find_comma("je,suis"), "%d");
	ASSERT_EQ_FMT(0, ft_find_comma(","), "%d");
	ASSERT_EQ_FMT(0, ft_find_comma(",jesuis"), "%d");
	ASSERT_EQ_FMT(6, ft_find_comma("jesuis,"), "%d");
	PASS();
}

TEST	add_color(void)
{
	int	i = 0x00FFFFFF;

	ASSERT_EQ_FMT(i, ft_add_color("xFFFFFF"), "%d");
	ASSERT_EQ_FMT(16777215, ft_add_color("0xFFFFFF"), "%d");
	ASSERT_EQ_FMT(i, ft_add_color(""), "%d");
	ASSERT_EQ_FMT(255, ft_add_color("0x0000FF"), "%d");
	ASSERT_EQ_FMT(i, ft_add_color(NULL), "%d");
	ASSERT_EQ_FMT(65280, ft_add_color("0x00FF00"), "%d");
	PASS();
}

///////////////////////////////////////////////////////////

t_base	*base;
char	*str1 = "10,0x00FFFFFF";
char	*str2 = ",0x00FFFFFF";
char	*str3 = "100x00FFFFFF";

///////////////////////////////////////////////////////////
/*	PLus d'actualité
TEST	put_data(void)
{
	base = malloc(sizeof(t_base));
	ft_put_data(base, str1, 1, 1);
	ASSERT_EQ_FMT(10, base->z_base, "%d");
	ASSERT_EQ_FMT(16777215, base->color_base, "%d");
	ASSERT_EQ_FMT(1, base->line, "%d");
	ASSERT_EQ_FMT(1, base->column, "%d");
	free(base);
	base = malloc(sizeof(t_base));
	ft_put_data(base, str2, 0, 10);
	ASSERT_EQ_FMT(0, base->z_base, "%d");
	ASSERT_EQ_FMT(16777215, base->color_base, "%d");
	ASSERT_EQ_FMT(0, base->line, "%d");
	ASSERT_EQ_FMT(10, base->column, "%d");
	free(base);
	base = malloc(sizeof(t_base));
	ft_put_data(base, str3, 1, 1);
	ASSERT_EQ_FMT(100, base->z_base, "%d");
	ASSERT_EQ_FMT(0x00FFFFFF, base->color_base, "%d");
	ASSERT_EQ_FMT(1, base->line, "%d");
	ASSERT_EQ_FMT(1, base->column, "%d");
	free(base);
	PASS();
}*/

TEST	get_x(void)
{
	t_base	*base;

	base = ft_set_base(list3, 20, 0, 0);
	ASSERT_EQ_FMT(3, ft_get_x(base), "%d");
	free(base);
	base = ft_set_base(list5, 12, 0, 0);
	ASSERT_EQ_FMT(2, ft_get_x(base), "%d");
	free(base);
	base = ft_set_base(list6, 2, 0, 0);
	ASSERT_EQ_FMT(1, ft_get_x(base), "%d");
	free(base);
	base = ft_set_base(list7, 2, 0, 0);
	ASSERT_EQ_FMT(0, ft_get_x(base), "%d");
	free(base);
	PASS();
}

TEST	get_y(void)
{
	t_base	*base;

	base = ft_set_base(list3, 20, 0, 0);
	ASSERT_EQ_FMT(4, ft_get_y(base), "%d");
	free(base);
	base = ft_set_base(list5, 12, 0, 0);
	ASSERT_EQ_FMT(3, ft_get_y(base), "%d");
	free(base);
	base = ft_set_base(list6, 2, 0, 0);
	ASSERT_EQ_FMT(0, ft_get_y(base), "%d");
	free(base);
	base = ft_set_base(list7, 2, 0, 0);
	ASSERT_EQ_FMT(1, ft_get_y(base), "%d");
	free(base);
	PASS();
}

SUITE (parsing_suite)
{
	RUN_TEST(valid_file);
	RUN_TEST(get_map);
	RUN_TEST(listlen);
	RUN_TEST(count_arg);
	RUN_TEST(count_len);
	RUN_TEST(find_comma);
	RUN_TEST(add_color);
	//RUN_TEST(put_data);
	RUN_TEST(get_x);
	RUN_TEST(get_y);
}
