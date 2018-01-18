/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 05:51:01 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>

# define	LS_L	(1 << 1)
# define	LS_REC	(1 << 2)
# define	LS_A	(1 << 3)
# define	LS_R	(1 << 4)
# define	LS_T	(1 << 5)

typedef struct		s_file
{
	struct s_arg	*prev;
	struct s_arg	*next;
	int		ID;
	char		name[256];
	DIR		*dirstream;
	unsigned char	mode;
	nlink_t		nlink;
	uid_t		uid;
	gid_t		gid;
	off_t		size;
	time_t		mtime;
}			t_file;

t_file		*new_file(t_file *nxt, char *name);
void		ft_unlink(t_file *elem);
void		ft_link_list(t_file *file);
void		ft_insert(t_file *elem, t_file *dest, char option);
t_file		*ft_place_first(t_file *elem);
t_file		*ft_place_last(t_file *elem);
void	ft_ls(DIR *dir, unsigned char options);
t_file		*ft_ascii(t_file *first);
char		ft_check_open(t_file *dir);
t_file		*ft_parse(t_file *small, t_file *big);
void				ft_error(void);
void				ft_print_n_free(t_file *arg_tmp);
void				ft_print(t_file *arg_tmp);
void				no_option(char chr);
unsigned char		set_options(char **av);

#endif