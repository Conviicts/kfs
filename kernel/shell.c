/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:22:25 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 17:24:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <kernel/interrupts/keyboard.h>
#include <libk.h>

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

void		shell(void) {
	while (42) {
		printk("kfs > ");
		memset(tty[cur_tty].buffer, 0, 256);
		read_line(tty[cur_tty].buffer);
		if (strlen(tty[cur_tty].buffer) > 0)
			printk("%s\n", tty[cur_tty].buffer);
	}
}
