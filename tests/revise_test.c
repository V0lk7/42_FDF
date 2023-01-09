/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revise_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 09:21:47 by jduval            #+#    #+#             */
/*   Updated: 2023/01/09 14:09:40 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"
#include "../fdf.h"

TEST revise_rx(void)
{
	//					   y, z, angle
	ASSERT_EQ(ft_calc_rx_y(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_rx_z(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_rx_y(0, 0, (38* PI / 180)), 0);
	ASSERT_EQ(ft_calc_rx_z(0, 0, 38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_rx_y(0, 0, -38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_rx_z(0, 0, -38 * PI / 180), 0);

	ASSERT_EQ(ft_calc_rx_y(10, 50, 0), 10);
	ASSERT_EQ(ft_calc_rx_z(10, 50, 0), 50);
	ASSERT_EQ(ft_calc_rx_y(10, 50, 38 * PI / 180), -23);
	ASSERT_EQ(ft_calc_rx_z(10, 50, 38 * PI / 180), 46);
	ASSERT_EQ(ft_calc_rx_y(10, 50, -38 * PI / 180), 39);
	ASSERT_EQ(ft_calc_rx_z(10, 50, -38 * PI / 180), 33);
	PASS();
}

TEST revise_ry(void)
{
	//					   x, z, angle
	ASSERT_EQ(ft_calc_ry_x(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_ry_z(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_ry_x(0, 0, (38* PI / 180)), 0);
	ASSERT_EQ(ft_calc_ry_z(0, 0, 38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_ry_x(0, 0, -38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_ry_z(0, 0, -38 * PI / 180), 0);

	ASSERT_EQ(ft_calc_ry_x(10, 50, 0), 10);
	ASSERT_EQ(ft_calc_ry_z(10, 50, 0), 50);
	ASSERT_EQ(ft_calc_ry_x(10, 50, 38 * PI / 180), 39);
	ASSERT_EQ(ft_calc_ry_z(10, 50, 38 * PI / 180), 33);
	ASSERT_EQ(ft_calc_ry_x(10, 50, -38 * PI / 180), -23);
	ASSERT_EQ(ft_calc_ry_z(10, 50, -38 * PI / 180), 46);
	PASS();
}

TEST revise_rz(void)
{
	//					   x, y, angle
	ASSERT_EQ(ft_calc_rz_x(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_rz_y(0, 0, 0), 0);
	ASSERT_EQ(ft_calc_rz_x(0, 0, (38* PI / 180)), 0);
	ASSERT_EQ(ft_calc_rz_y(0, 0, 38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_rz_x(0, 0, -38 * PI / 180), 0);
	ASSERT_EQ(ft_calc_rz_y(0, 0, -38 * PI / 180), 0);

	ASSERT_EQ(ft_calc_rz_x(10, 50, 0), 10);
	ASSERT_EQ(ft_calc_rz_y(10, 50, 0), 50);
	ASSERT_EQ(ft_calc_rz_x(10, 50, 38 * PI / 180), -23);
	ASSERT_EQ(ft_calc_rz_y(10, 50, 38 * PI / 180), 46);
	ASSERT_EQ(ft_calc_rz_x(10, 50, -38 * PI / 180), 39);
	ASSERT_EQ(ft_calc_rz_y(10, 50, -38 * PI / 180), 33);
	PASS();
}

SUITE (revise_suite)
{
	RUN_TEST(revise_rx);
	RUN_TEST(revise_ry);
	RUN_TEST(revise_rz);
}
