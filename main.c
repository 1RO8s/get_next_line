/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnagasak <hnagasak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:33:18 by hnagasak          #+#    #+#             */
/*   Updated: 2023/06/04 21:54:44 by hnagasak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

int	main(void)
{
	unsigned int ui = 4294967295;
	printf("UINT16_MAX %d\n",UINT16_MAX);
	printf("SIZE_MAX %lu\n",SIZE_MAX);
	printf("unsigned int %u\n",ui);

}
