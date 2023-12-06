/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:54:20 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/06 15:00:07 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel/tty.h"

void	tty_color(uint8_t color) {
	tty.color = color;
}