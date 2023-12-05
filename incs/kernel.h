/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:18:26 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/05 21:18:27 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KERNEL_H
#define KERNEL_H

#include "vga.h"

#define ulong unsigned long
#define uchar unsigned char
#define ushort unsigned short

typedef struct s_tty {
	ulong	columns[10];
	ulong	rows[10];
	ulong	row;
	ulong	column;
	uchar	color;
	ushort	*buffer;
}	t_tty;
extern t_tty g_tty;

void			init_term();
void			khello(void);
ulong			kstrlen(const char *s);
void			kputchar(const char c);
void			kputstr(const char *s);

#endif