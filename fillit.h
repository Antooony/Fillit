/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:10 by adenis            #+#    #+#             */
/*   Updated: 2016/12/02 16:26:04 by adenis           ###   ########.fr       */
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
t_list					*get_lst(char **tab);

int						ft_get_i(t_list *lst);
void					ft_cpytab(int	*dst, int	*tab);
void					printtetri(t_list *lst, int	i);

void					lstsub(t_list *lst);
void					lst_display(t_list *lst);

int						ft_checkneg(int	*tab);
char					**ft_creategrid(int i);
char					**fillgrid(t_list **lst, int	x, int	y, char **tab);
int						testfig(t_list *lst, int	x, int	y, char **tab);
int						ft_check_and_fill(t_list *lst, char ***tab, int len);

void					ft_return(char **tab);
int						ft_sqrtt(int nb);
void					ft_solve_it(t_list *lst, int len);

#endif
