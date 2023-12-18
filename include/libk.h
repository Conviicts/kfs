/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libk.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:27:08 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 15:52:09 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBK_H
#define LIBK_H

#include <defines.h>

size_t	strlen(const char *s);

int		putchar(int c);
void	putstr(const char *s);
void	putnbr(int nb);
int     printf(const char* restrict format, ...);

int		isdigit(int c);
int		isalpha(int c);

int		isalnum(int c);
int		isprint(int c);

void	*memset(void *b, int c, unsigned int len);

#endif