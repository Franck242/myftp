/*
** EPITECH PROJECT, 2021
** PSU_myftp_2017
** File description:
** Created by j-f,
*/

#include "myftp.h"

int	size_of_word(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0' && str[size] != ' ' && str[size] != '\n') {
		size = size + 1;
	}
	return (size);
}

int	nbr_of_words(char *str)
{
	int	nbr;
	int	index;

	nbr = 0;
	index = 0;
	while (str[index] != '\0' && str[index] != '\n') {
		if (str[index] == ' ' && str[index + 1] != '\0') {
			nbr = nbr + 1;
		}
	index = index + 1;
	}
	return (nbr);
}

char	**my_str_to_wordtab(char *str)
{
	char	**result;
	int	x, y, z;
	x = 0;
	y = 0;
	z = 0;

	result = malloc(((nbr_of_words(str) + 2)) * sizeof(*result));
	while (str[x] != '\n' && str[x] != '\0') {
		if (str[x] == ' ' || str[x] == '\n') {
			while (str[x] == ' ')
				x = x + 1;
			y = y + 1;
			z = 0;
		}
		result[y] = malloc(((size_of_word(str + x) + 1))
			* sizeof(**result));
		while (str[x] != ' ' && str[x] != '\n' && str[x])
			result[y][z++] = str[x++];
		result[y][z] = '\0';
	}
	result[y + 1] = '\0';
	return (result);
}
