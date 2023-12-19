/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:56:59 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 16:58:58 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>

void	tty_switch_screen(int screen) {
	switch (screen) {
		case 59:
			cur_tty = 0;
			break;
		case 60:
			cur_tty = 1;
			break;
		case 61:
			cur_tty = 2;
			break;
		case 62:
			cur_tty = 3;
			break;
	}
	if (tty[cur_tty].column == 0) {
		tty_initialize();
		print_intro();
		printk("kfs > ");
	}
	else {
		tty_draw(&tty[cur_tty]);
		tty_move_cursor(tty[cur_tty].row * VGA_WIDTH + tty[cur_tty].column);
	}
}