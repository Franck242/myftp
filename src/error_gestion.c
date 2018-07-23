/*
** EPITECH PROJECT, 2021
** my_ftp
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	check_nb_args(int ac, char **av)
{
	if (ac < 3 || ac > 3) {
		__ERROR_ARGS__;
		exit(ERROR_EXIT);
	}
	check_path(av[2]);
}

void	check_proto_name(struct protoent *proto)
{
	if (proto == NULL) {
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

void	check_closing_file(int fd)
{
	if (close(fd) == -1) {
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

void	check_bind_value(int b, int fd)
{
	if (b == - 1) {
		check_closing_file(fd);
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

void	check_listen(int fd)
{
	if (listen(fd, 42) == -1) {
		check_closing_file(fd);
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

