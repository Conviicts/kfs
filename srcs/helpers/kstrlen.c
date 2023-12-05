/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kstrlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 00:42:56 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/05 02:18:35 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "kernel.h"

unsigned long kstrlen(const char *s) {
	unsigned long len = 0;
	
	while (s && s[len])
		len++;
	return len;
}