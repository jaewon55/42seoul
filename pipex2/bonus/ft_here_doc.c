/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 03:11:38 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/15 03:51:35 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
int	ft_here_doc(int ac, char **av, char **envp)
{
	ac++;
	av++;
	envp++;
	return 1;
}
