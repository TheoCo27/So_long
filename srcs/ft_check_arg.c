/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 13:29:34 by tcohen            #+#    #+#             */
/*   Updated: 2024/09/16 16:59:37 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_format(void)
{
	ft_putstr_fd("Error\nInvalid format need: ./so_long <your_map.ber>\n", 2);
	exit (1);
}

void	ft_check_argc(int argc)
{
	if (argc != 2)
		ft_error_format();
}

static int	ft_check_hidden_file(char **argv)
{
	size_t	i;

	i = ft_strlen(argv[1]);
	if (i < 5)
		ft_error_format();
	while (i != 0)
	{
		if (argv[1][i] == '.' && i != 0)
		{
			if (argv[1][i - 1] == '/')
				ft_error_format();
			break ;
		}
		i--;
	}
	return (0);
}

void	ft_check_argv(char **argv)
{
	size_t	i;
	char	*ber;

	i = ft_strlen(argv[1]);
	if (i == 0)
		ft_error_format();
	ft_check_hidden_file(argv);
	ber = ft_strrchr(argv[1], '.');
	if (!ber)
		ft_error_format();
	if (ft_strncmp(ber, ".ber", 4) != 0)
		ft_error_format();
	if (ft_strlen(ber) > 4 && ber[4] != '\0')
		ft_error_format();
	if (i <= ft_strlen(ber))
		ft_error_format();
}

// void	ft_check_argv(char **argv)
// {
// 	size_t	i;
// 	int check;

// 	i = 0;
// 	check = 0;
// 	if (argv[1][0] == '\0')
// 		ft_error_format();
// 	ft_check_hidden_file(argv);
// 	while (argv[1][i])
// 	{
// 		if (argv[1][i] == '.')
// 		{
// 			if(ft_strncmp((argv[1] + i), ".ber", 4) != 0)
// 				ft_error_format();
// 			if (argv[1][i + 4] == '\0')
// 				check = 1;
// 		}
// 		i++;
// 	}
// 	if (check == 0)
// 		ft_error_format();
// }

void	ft_check_arg(int argc, char **argv)
{
	ft_check_argc(argc);
	ft_check_argv(argv);
}
