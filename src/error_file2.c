/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	check_client_fd(int fd_client)
{
	if (fd_client == -1) {
		check_closing_file(fd_client);
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

void	check_path(char *file_name)
{
	DIR *dir;

	dir = opendir(file_name);
	if (dir == NULL) {
		write(2, file_name, strlen(file_name) - 1);
		__ERROR_FILE__;
		exit(ERROR_EXIT);
	}
}

void	check_port_and_fd(int fd, int port_value)
{
	if (fd == -1 || port_value < 0) {
		__ERROR_PROTO__;
		exit(ERROR_EXIT);
	}
}

void	check_closing(int fd , int fd_client)
{
	check_closing_file(fd);
	check_closing_file(fd_client);
}

void	check_pid(pid_t pid, t_socket_info sock)
{
	if (pid < 0) {
		check_closing(sock.fd, sock.fd_client);
		__ERROR_FORK__;
		exit(ERROR_EXIT);
	}
}
