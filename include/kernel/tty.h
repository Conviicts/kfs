/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tty.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:18:26 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 03:52:47 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include "defines.h"
#include "libk.h"

void tty_initialize(void);
void tty_putchar(char c);
void tty_write(const char* data, size_t size);
void tty_writestring(const char* data);

#endif