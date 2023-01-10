/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:07:22 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 15:50:53 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../fdf.h"

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
	char	*str;

	str = ft_get_map("1.fdf");
	ASSERT_EQ_FMT(0, strcmp(str, "0 0 0  "), "%d");
	free(str);
	PASS();
}

SUITE (parsing_suite)
{
	RUN_TEST(valid_file);
	RUN_TEST(get_map);
}
