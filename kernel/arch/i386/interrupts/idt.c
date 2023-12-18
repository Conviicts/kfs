/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:07:13 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 15:01:50 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/io.h>
#include <kernel/interrupts/pic.h>
#include <kernel/interrupts/idt.h>
#include <kernel/interrupts/keyboard.h>
#include <libk.h>

t_idt_entry	idt[256];
t_idt_ptr	idt_ptr;

void interrupt_handler(struct cpu_state cpu, uint32_t interrupt, struct stack_state stack) {
	(void)cpu;
	(void)stack;
	uint8_t code;
	uint8_t c;

	switch (interrupt) {
		case 33:
			code = keyboard_read();
			if (code <= 83) {
				c = keybord_get_char(code);
				if (c)
					putchar(c);	
			}
			pic_acknowledge(interrupt);
		default:
			break;
	}
}

static void create_descriptor(int index, uint32_t address) {
	idt[index].offset_high = (address >> 16) & 0xFFFF;
	idt[index].offset_low = (address & 0xFFFF);
	idt[index].segment_selector = 0x08;
	idt[index].reserved = 0x00;
	idt[index].type_and_attr =	(0x01 << 7) | (0x00 << 6) | (0x00 << 5) | 0xe;
}

void	init_idt(void) {
	idt_ptr.size = (sizeof(t_idt_entry) * 256);
	idt_ptr.address = (uint32_t)&idt;

	create_descriptor(33, (uint32_t)interrupt_handler_33);

	load_idt((int)&idt_ptr);
	pic_remap(0x20, 0x28);
}