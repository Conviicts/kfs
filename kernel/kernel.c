/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kernel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:45:31 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 03:50:01 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/tty.h>
#include <libk.h>

void	kmain(void) {
	tty_initialize();
	putstr("Hello World !\n");
	// kputstr("Hello World !\n");
}