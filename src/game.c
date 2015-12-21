/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:40:19 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 14:57:15 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int		cpu_turn(void)
{
	int		nb_match;
	int		answer;

	nb_match = remaining_matches();
	if (nb_match % 4 == 0)
		answer = 3;
	else if (nb_match % 4 == 3)
		answer = 2;
	else
		answer = 1;
	ft_putstr("\n\033[1;33mCPU picked \033[1;31m");
	ft_putnbr(answer);
	ft_putendl("\033[1;33m match(es)\033[00m");
	pick_up(answer);
	return (PLAYER);
}

static int		player_turn(void)
{
	int		nb_match;
	char	*line;
	int		pick;

	nb_match = remaining_matches();
	if (get_next_line(0, &line) == -1 || !ft_strcmp(line, "stop"))
		return (ERR);
	pick = ft_atoi(line);
	free(line);
	if ((pick <= nb_match) && (pick == 1 || pick == 2 || pick == 3))
		pick_up(pick);
	else
	{
		ft_putendl("\n\033[2;31mWrong entry, please retry !\033[00m");
		return (PLAYER);
	}
	return (CPU);
}

static int		game_turn(int turn)
{
	t_list	*lst;

	lst = singleton();
	while (lst->next->nb_match != 0)
	{
		if (turn == ERR)
			return (ERR);
		else if (turn == CPU)
		{
			turn = cpu_turn();
		}
		else if (turn == PLAYER)
		{
			ft_putendl("\n\033[1;36mPick 1, 2 or 3 match(es) :\033[00m");
			turn = player_turn();
		}
	}
	return (turn);
}

static int		start_game(char *line)
{
	if (!ft_strcmp(line, "stop"))
		return (ERR);
	else if (!ft_strcmp(line, "1"))
	{
		ft_putendl("\n\033[1;4;36mYou play first !\033[00m\n");
		return (game_turn(PLAYER));
	}
	else if (!ft_strcmp(line, "2"))
	{
		ft_putendl("\n\033[1;4;33mCPU plays first !\033[00m\n");
		return (game_turn(CPU));
	}
	else
	{
		ft_putendl("\n\033[2;31mWrong entry, please retry !\033[00m");
		return (IND);
	}
}

void			game(void)
{
	int		status;
	char	*line;

	status = IND;
	ft_putstr("\n\033[1;37mChoose first player (\033[2;36m1 : you\033[1;37m");
	ft_putendl(" ; \033[2;33m2 : CPU\033[1;37m) :\033[00m");
	while (status == IND)
	{
		if (get_next_line(0, &line) == ERR)
			status = ERR;
		else
			status = start_game(line);
		free(line);
	}
	if (status == ERR)
		return (ft_putendl("Exit !"));
	else if (status == CPU)
		return (ft_putendl("\n\033[1;31mYou lose ! =(\033[00m\n"));
	else if (status == PLAYER)
		return (ft_putendl("\n\033[2;32mYou win ! =D\033[00m\n"));
}
