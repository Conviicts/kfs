/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:22:25 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 19:09:56 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <kernel/io.h>
#include <kernel/interrupts/keyboard.h>
#include <libk.h>
#include <kfs.h>

static void	read_line(char *buffer) {
	char		c = 0;
	uint32_t	i = 0;
	
	while (42) {
		c = keyboard_state.c;
		keyboard_state.c = 0;
		if (c == 0)
			continue ;
		if (strlen(tty[cur_tty].buffer) > 0)
			i = strlen(tty[cur_tty].buffer);
		else
			i = 0;
		if (c == '\n') {
			putchar(c);
			return ;
		}
		if (keyboard_state.ctrl) {
			if (c == 'l') {
				memset(tty[cur_tty].buffer, 0, 256);
				tty_initialize();
				print_intro();
				return ;
			}
		}
		putchar(c);
		tty[cur_tty].buffer[i] = c;
		if (strlen(buffer) == 256)
			return;
		i++;
	}
}

static void run(void) {
	if (strcmp(tty[cur_tty].buffer, "shutdown") == 0) {
		outw(0x604, 0x2000);
	} else if (strcmp(tty[cur_tty].buffer, "reboot") == 0) {
		uint8_t good = 0x02;
		while (good & 0x02)
			good = inb(0x64);
		outb(0x64, 0xFE);
		asm("hlt");
	} else {
		printk("kfs: command not found: %s\n", tty[cur_tty].buffer);
	}
}

void		shell(void) {
	while (42) {
		printk("kfs > ");
		memset(tty[cur_tty].buffer, 0, 256);
		read_line(tty[cur_tty].buffer);
		if (strlen(tty[cur_tty].buffer) > 0){
			run();
		}
	}
}
