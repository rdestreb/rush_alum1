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

int	read_board(int fd);
int print_error(void);
int	verif_board(char *line);

#endif