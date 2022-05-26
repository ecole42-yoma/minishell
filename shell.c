/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkong <jkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:34:05 by jkong             #+#    #+#             */
/*   Updated: 2022/05/26 18:06:51 by jkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "libft.h"

int	main(int argc, char *argv[])
{
	t_parse_state	pst;
	char			*rl;
	int				exit_status;

	(void)&argc;
	(void)&argv;
	exit_status = 0;
	while (1)
	{
		rl = readline("$ ");
		if (!rl)
		{
			printf("exit\n");
			break ;
		}
		ft_memset(&pst, 0, sizeof(pst));
		pst.str = rl;
		pst.begin = pst.str;
		pst.stack_ptr = pst.initial_stack;
		lex(&pst);
		add_history(rl);
		free(rl);
	}
	return (exit_status);
}
