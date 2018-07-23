/*
** EPITECH PROJECT, 2018
** main
** File description:
** all execution
*/

#include "myftp.h"

int	main(int ac, char *argv[])
{
	int	port_value;

	if (ac == 2 && strcmp(argv[1], "-help") == 0) {
		print_help(argv[0]);
		return (SUCCESS_EXIT);
	}
	check_nb_args(ac, argv);
	port_value = atoi(argv[1]);
	create_socket(port_value, argv[2]);
	return (SUCCESS_EXIT);
}
