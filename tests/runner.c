/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   runner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 08:34:48 by jduval            #+#    #+#             */
/*   Updated: 2023/01/10 12:19:05 by jduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "greatest.h"

SUITE(revise_suite);
SUITE(parsing_suite);

GREATEST_MAIN_DEFS();

int	main(int argc, char **argv)
{
	GREATEST_MAIN_BEGIN();      /* command-line options, initialization. */

	/* Tests can also be gathered into test suites. */
	RUN_SUITE(revise_suite);
	RUN_SUITE(parsing_suite);

	GREATEST_MAIN_END();        /* display results */
}
