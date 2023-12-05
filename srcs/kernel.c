/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/05 21:17:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"
#include "vga.h"

t_tty g_tty = {};

void	init_term() {
	g_tty.row = 0;
	g_tty.column = 0;
	g_tty.color = VGA_LIGHT_GREY | VGA_BLACK << 4;
	g_tty.buffer = (ushort *)VGA_ADDRESS;
	for (int i = 0; i < 10; i++) {
		g_tty.columns[i] = -1;
		g_tty.rows[i] = -1;
	}
	for (ulong y = 0; y < VGA_HEIGHT; y++) {
		for (ulong x = 0; x < VGA_WIDTH; x++) {
			ulong i = y * VGA_WIDTH + x;
			g_tty.buffer[i] = ' ' | g_tty.color << 8;
		}
	}
}

int	main(void) {
	init_term();
	khello();
	kputstr("Hello World !\n");
	return (0);
}