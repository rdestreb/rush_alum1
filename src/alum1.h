/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:14:27 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/21 14:52:03 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# define ERR -1
# define IND 0
# define PLAYER 1
# define CPU 2

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_list	t_list;

struct		s_list
{
	int		nb_match;
	int		init;
	t_list	*next;
};

int			read_board(int fd);
int			print_error(void);
int			verif_board(char *line);
void		disp_board(int *board);
int			*construct_board(int *board, unsigned int match);
t_list		*singleton(void);
t_list		*newnode(int match);
void		add_link(int match);
void		disp_list(int picked);
void		disp_match(int match, int picked);
void		game(void);
int			remaining_matches(void);
int			pick_up(int pick);

#endif
