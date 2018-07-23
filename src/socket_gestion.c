/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

void	init_s_in(struct sockaddr_in *s_in, int port_value)
{
	s_in->sin_family = AF_INET;
	s_in->sin_port = htons(port_value);
	s_in->sin_addr.s_addr = INADDR_ANY;
}

void	client_handler(int fd, const char *ip_name)
{
	if (fd == -1 || ip_name == NULL) {
		__ERROR_PROTO__;
		_exit(ERROR_EXIT);
	}
}

t_socket_info	init_socket(t_socket_info sock, int port_value)
{
	sock.size = sizeof(sock.client_s_in);
	sock.proto = getprotobyname("TCP");
	init_s_in(&sock.s_in, port_value);
	check_proto_name(sock.proto);
	sock.fd = socket(AF_INET, SOCK_STREAM, sock.proto->p_proto);
	check_port_and_fd(sock.fd, port_value);
	sock.b = bind(sock.fd, (const struct sockaddr *)&sock.s_in,
		sizeof(sock.s_in));
	check_bind_value(sock.b, sock.fd);
	check_listen(sock.fd);
	return (sock);
}

void	print_msg(t_socket_info *sock)
{
	write(sock->fd_client, __220MSG__, strlen(__220MSG__));
	check_client_fd(sock->fd_client);
	sock->ip_client = inet_ntoa(sock->client_s_in.sin_addr);
	client_handler(sock->fd_client, sock->ip_client);
}

void	create_socket(int port_value, char *path)
{
	t_socket_info	s;

	s = init_socket(s, port_value);
	s.path = path;
	while (1) {
		s.fd_client = accept(s.fd, (struct sockaddr *)&s.client_s_in,
			&s.size);
		s.pid = fork();
		check_pid(s.pid, s);
		if (s.pid == 0) {
			print_msg(&s);
			if (cmd_gestion(s) == 0)
				return;
		}
	}
	check_closing(s.fd, s.fd_client);
}
