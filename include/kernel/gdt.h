/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gdt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:47:55 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/18 09:38:12 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GDT_H
# define GDT_H

#include <defines.h>

extern void gdt_flush(uint32_t gdt_ptr);

typedef struct  __attribute__((packed)) gdt_entry {
   uint16_t limit_low;
   uint16_t base_low;
   uint8_t  base_middle;
   uint8_t  access;
   uint8_t  granularity;
   uint8_t  base_high;
}  t_gdt_entry;

typedef struct  __attribute__((packed)) gdt_ptr {
   uint16_t limit;
   uint32_t base;
} t_gdt_ptr;

void    init_gdt();

#endif