/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_chk_fail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jode-vri <jode-vri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 21:18:48 by jode-vri          #+#    #+#             */
/*   Updated: 2023/12/05 21:18:49 by jode-vri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void __stack_chk_fail_local(void) {
    // Implement your error-handling code here
    while (1) {} // For example, just loop indefinitely
}