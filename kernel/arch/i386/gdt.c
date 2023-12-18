/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:50:24 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 15:28:20 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/gdt.h>

t_gdt_entry gdt_entries[7];
t_gdt_ptr   gdt_ptr;

static void create_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity) {
	gdt_entries[index].base_low = base & 0xFFFF;
	gdt_entries[index].base_middle = (base >> 16) & 0xFF;
	gdt_entries[index].base_high = (base >> 24) & 0xFF;
	gdt_entries[index].limit_low = limit & 0xFFFF;
	gdt_entries[index].access = access;
	gdt_entries[index].granularity = granularity;
}

void    init_gdt() {
	gdt_ptr.limit = (sizeof(t_gdt_entry) * 7) - 1;
	gdt_ptr.base  = (uint32_t)&gdt_entries;

	create_entry(0, 0, 0, 0, 0);                // Null segment
	create_entry(1, 0, 0xFFFFF, 0x9A, 0xCF);    // Kernel Code segment
	create_entry(2, 0, 0xFFFFF, 0x92, 0xCF);    // Kernel Data segment
	create_entry(2, 0, 0xFFFFF, 0x96, 0xCF);    // Kernel Stack segment
	create_entry(4, 0, 0xFFFFF, 0xFA, 0xCF);    // User Code segment
	create_entry(5, 0, 0xFFFFF, 0xF2, 0xCF);    // User Data segment
	create_entry(6, 0, 0xFFFFF, 0xF6, 0xCF);    // User Stack segment
	gdt_flush((uint32_t)&gdt_ptr);
}