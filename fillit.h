/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:10 by adenis            #+#    #+#             */
/*   Updated: 2016/11/29 11:50:43 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

void					fillit(char *str);
int						ft_check(char *s);
int						ft_check_str(char *str);
int						check_in(char *str);
void					ft_check_tetri(t_list *lst);

char					*ft_get_ret(char *dest, char *src);
char					*get_str(char *str, char *tab);
void					ft_getox(t_list *lst);
void					lstsub(t_list *lst);
t_list					*get_lst(char **tab);

int						ft_get_i(t_list *lst);
void					ft_cpytab(int	*dst, int	*tab);
void					printparams(t_list *lst);
void					printtetri(t_list *lst, int	i);

#endif
