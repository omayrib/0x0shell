/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youchenn <youchenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 10:52:25 by youchenn          #+#    #+#             */
/*   Updated: 2022/08/24 14:19:02 by youchenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"



void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}