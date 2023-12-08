/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:18:26 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 15:15:39 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <defines.h>
#include <libk.h>
#include <vga.h>

typedef struct	s_tty
{
	size_t		row;
	size_t		column;
	uint8_t		color;
	
	uint16_t	screen[VGA_WIDTH * VGA_HEIGHT];
	uint16_t	*vga_buffer;
}				t_tty;
extern t_tty	tty;

void tty_initialize(void);
void tty_clear(t_tty *t);

void tty_color(uint8_t color);
void tty_putchar(char c);

#endif