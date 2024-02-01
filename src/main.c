/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:03:50 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/02/01 13:23:15 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_code;

static t_prompt	*start_program(int argc, char **argv, char **env)
{
	t_prompt	*prompt;

	if (argc > 1)
	{
		ft_printf("No arguments, please!\n");
		exit(1);
	}
	prompt = init_prompt(argv, env);
	set_sign();
	execute_signal(0, prompt);
	return (prompt);
}

static char	*handle_input(t_prompt *prompt, char *input)
{
	if (input == NULL)
	{
		free(input);
		printf("exit\n");
		ms_exit(prompt, NULL);
	}
	if (input[0] && !is_only_whitespaces(input))
		add_history(input);
	if (input || input[0])
		input = expand_input(prompt, input);
	return (input);
}

int	main(int argc, char **argv, char **env)
{
	t_prompt	*prompt;
	char		*input;

	prompt = start_program(argc, argv, env);
	while (prompt)
	{
		prompt->interact = true;
		input = readline("\001\e[1;35m\002minishell$ \001\e[0m\002");
		prompt->interact = false;
		input = handle_input(prompt, input);
		prompt->lexer = lexer(input);
		if (!prompt->lexer)
		{
			reset_prompt(prompt, argv, env);
			continue ;
		}
		if (prompt->lexer && !check_redirections(prompt))
		{
			parser(prompt);
			if (prompt->simple_cmds && !init_pid(prompt))
				execute(prompt);
		}
		reset_prompt(prompt, argv, env);
	}
}
