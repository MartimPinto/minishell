/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarneir <mcarneir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:31:37 by gabrrodr          #+#    #+#             */
/*   Updated: 2024/02/01 12:20:51 by mcarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_word(char *str)
{
	char		*val;
	int			i;
	int			j;
	int			start;

	i = 0;
	while (str[i] && str[i] != '$')
		i++;
	i++;
	start = i;
	while (str[i] && str[i] != ' ' && str[i] != '\'' && str[i] != '\"' 
		&& str[i] != '/' && str[i] != '$')
		i++;
	val = ft_calloc(i - start + 1, sizeof(char));
	j = 0;
	while (start < i)
		val[j++] = str[start++];
	return (val);
}

void	init_exit_codes(t_prompt *prompt, char *input)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (input[++i])
	{
		if (input[i] == '$')
			if (input[i + 1] && input[i + 1] == '?')
				count++;
	}
	prompt->exit_codes = malloc(count * sizeof(int));
	if (!prompt->exit_codes)
		return ;
	i = -1;
	while (++i < count)
		prompt->exit_codes[i] = 0;
}

bool	solo_doll_sign(const char *str)
{
	int	i;
	int	doll;

	doll = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '$' && (str[i + 1] == ' ' || str[i + 1] == '\0' 
				|| str[i + 1] == '\'' || str[i + 1] == '\"'))
			doll++;
	}
	if (doll > 0)
		return (true);
	return (false);
}
