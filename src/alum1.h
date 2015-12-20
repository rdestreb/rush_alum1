/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alum1.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestreb <rdestreb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 09:14:27 by rdestreb          #+#    #+#             */
/*   Updated: 2015/12/20 09:15:04 by rdestreb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef struct s_list	t_list;

struct s_list
{
	int		nb_match;
	t_list	*next;
};

int	read_board(int fd);
int print_error(void);
int	verif_board(char *line);
void disp_board(int *board);
int	*construct_board(int *board, unsigned int match);
t_list	*singleton(void);
t_list	*newnode(int match);
void add_link(int match);
void disp_list(void);
void disp_match(int match);

#endif
