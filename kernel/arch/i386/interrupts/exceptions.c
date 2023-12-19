/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:18:57 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/19 11:23:33 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kernel/interrupts/exceptions.h>

void exception_handler() {
    asm("cli; hlt"); // Completely hangs the computer
}