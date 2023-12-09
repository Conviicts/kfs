/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   idt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 00:05:11 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/09 13:35:06 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/idt.h>
#include <libk.h>

extern void* isr_stub_table[];

__attribute__((aligned(0x10)))
struct idt_entry idt[256];
struct idt_ptr idt_ptr;

void    idt_exception(void) {
    putstr("Exception has been throw");
    asm volatile("cli; hlt"); // Hang up computer
}

static void create_descriptor(uint8_t pos, void *base, uint8_t flags) {
    idt[pos].isr_low = ((uint32_t)base) & 0xFFFF;
    idt[pos].kernel_cs = 0x08;
    idt[pos].reserved = 0;
    idt[pos].attributes = flags;
    idt[pos].isr_high = ((uint32_t)base >> 16) & 0xFFFF;
}

void    init_idt() {
    idt_ptr.base = (uint32_t)&idt;
    idt_ptr.limit = (sizeof(struct idt_entry) * 256) - 1;

    memset(&idt, 0, sizeof(struct idt_entry) * 256);
    for (uint8_t vector = 0; vector < 32; vector++) {
        create_descriptor(vector, isr_stub_table[vector], 0x8E);
    }
    idt_flush((uint32_t)&idt_ptr);
}