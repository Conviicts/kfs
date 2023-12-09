/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:08:39 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/09 13:20:22 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/gdt.h>

struct gdt_entry gdt[5];
struct gdt_ptr gdt_ptr;

static void create_descriptor(int pos, uint32_t base, uint32_t limit, uint16_t flag, uint8_t granularity) {

    gdt[pos].limit_low = (limit & 0xFFFF);
	gdt[pos].base_low = (base & 0xFFFF);
	gdt[pos].base_middle = (base >> 16) & 0xFF;
	gdt[pos].base_high = (base >> 24) & 0xFF;
	gdt[pos].access = flag;
	gdt[pos].granularity = (limit >> 16) & 0x0F;
	gdt[pos].granularity |= granularity & 0xF0;
	
}

void init_gdt(void) {
	gdt_ptr.base = (uint32_t)&gdt;
	gdt_ptr.limit = (sizeof(struct gdt_ptr) * 5) - 1;
	create_descriptor(0, 0, 0, 0, 0); // Null segment
	create_descriptor(1, 0, 0x000FFFFF, (GDT_CODE_PL0), 0xCF); // Kernel code
    create_descriptor(2, 0, 0x000FFFFF, (GDT_DATA_PL0), 0xCF); // Kernel data
    create_descriptor(3, 0, 0x000FFFFF, (GDT_STACK_PL0), 0xCF); // Kernel data

	
    create_descriptor(4, 0, 0x000FFFFF, (GDT_CODE_PL3), 0xCF); // User code
    create_descriptor(5, 0, 0x000FFFFF, (GDT_DATA_PL3), 0xCF); // User data
    create_descriptor(6, 0, 0x000FFFFF, (GDT_STACK_PL3), 0xCF); // User data

	asm volatile("lgdt %0" : : "m" (gdt_ptr)); // Load the GDT in GDTR register
}