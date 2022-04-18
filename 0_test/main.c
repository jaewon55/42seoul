/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewchoi <jaewchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:22:13 by jaewchoi          #+#    #+#             */
/*   Updated: 2022/04/18 16:03:06 by jaewchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int	main(int ac, char **av, char **envp)
{
	printf("%s\n", av[1]);
//	char *args[2] = {"test", NULL};
//	execve("./test", args, envp);
//	perror(NULL);
	return (0);
}
