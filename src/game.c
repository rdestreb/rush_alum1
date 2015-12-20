/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 16:40:19 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 16:40:30 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

static int	cpu_turn()
{
	int		nb_match;
	char	*line;
//	int		pick;

	nb_match = remaining_matches();
	if (get_next_line(0, &line) == -1 || !ft_strcmp(line, "stop"))
		return (ERR);
	free(line);
	disp_list();
	return (PLAYER);
}

static int	player_turn()
{
	int	nb_match;
	char	*line;
	int		pick;

	nb_match = remaining_matches();
	if (get_next_line(0, &line) == -1 || !ft_strcmp(line, "stop"))
		return (ERR);
	pick = ft_atoi(line);
	free (line);
	if ((pick <= nb_match) && (pick == 1 || pick == 2 || pick == 3) )
		pick_up(pick);
	else
	{
		ft_putendl("\n\033[2;31mWrong entry, please retry !\033[00m");
		return (PLAYER);
	}
	return (CPU);
}

static int	game_turn(int turn)
{
	t_list	*lst;

	lst = singleton();
	while (lst->next->nb_match != 0)
	{
		if (turn == ERR)
			return (ERR);
		else if (turn == CPU)
		{
			ft_putendl("\nCPU playing");
			turn = cpu_turn();
		}
		else if (turn == PLAYER)
		{
			ft_putendl("\nPick 1, 2 or 3 match(es) :");
			turn = player_turn();
		}
	}
	return (turn);
}

static int	start_game(char *line)
{

	if (!ft_strcmp(line, "stop"))
		return (ERR);
	else if (!ft_strcmp(line, "1"))
	{
		ft_putendl("\n\033[36;1mYou play first !\033[00m\n");
		return (game_turn(PLAYER));
	}
	else if (!ft_strcmp(line, "2"))
	{
		ft_putendl("\n\033[2;33mCPU plays first !\033[00m\n");
		return (game_turn(CPU));
	}
	else
	{
		ft_putendl("\n\033[2;31mWrong entry, please retry !\033[00m");
		return (IND);
	}
}

void		game()
{
	int		status;
	char	*line;

	status = IND;
	ft_putendl("\nChoose first player (1 : you ; 2 : CPU) :");
	while (status == IND)
	{
		if (get_next_line(0, &line) == ERR)
			status = ERR;
		else
			status = start_game(line);
		free(line);
	}
	if (status == ERR)
		return(ft_putendl("Exit !"));
	else if (status == CPU)
		return (ft_putendl("\033[1;31mYou lose ! =(\033[00m\n"));
	else if (status == PLAYER)
		return (ft_putendl("\033[2;32mYou win ! =D\033[00m\n"));
}
