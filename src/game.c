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
		return (-1);
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
		return (-1);
	pick = ft_atoi(line);
	free (line);
	if ((pick <= nb_match) && (pick == 1 || pick == 2 || pick == 3) )
		pick_up(pick);
	else
	{
		ft_putendl("wrong entry, please retry !");
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
		if (turn == -1)
			return (-1);
		else if (turn == CPU)
		{
			ft_putendl("CPU playing");
			turn = cpu_turn();
		}
		else if (turn == PLAYER)
		{
			ft_putendl("Pick 1, 2 or 3 match(es) :");
			turn = player_turn();
		}
	}
	return (1);
}

static int	start_game(char *line)
{

	if (!ft_strcmp(line, "stop"))
		return (-1);
	else if (!ft_strcmp(line, "1"))
	{
		ft_putendl("You play first !");
		return (game_turn(PLAYER));
	}
	else if (!ft_strcmp(line, "2"))
	{
		ft_putendl("CPU plays first !");
		return (game_turn(CPU));
	}
	else
	{
		ft_putendl("wrong entry, please retry !");
		return (0);
	}
}

void		game()
{
	int		status;
	char	*line;

	status = 0;
	ft_putendl("\nChoose first player (1 : you ; 2 : CPU) :");
	while (status != -1 && status != 1)
	{
		if (get_next_line(0, &line) == -1)
			status = -1;
		else
			status = start_game(line);
		free(line);
	}
	if (status == -1)
		return(ft_putendl("exit !"));
}
