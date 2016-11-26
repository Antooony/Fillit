/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenis <adenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:16:10 by adenis            #+#    #+#             */
/*   Updated: 2016/11/26 15:05:25 by adenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "./libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	fillit(char *str);
void	ft_lstadd_end(t_list *alst, t_list *new);
char	*ft_get_ret(char *dest, char *src);
char	*get_str(char *str, char *tab);
int		ft_checkc(char *s);
int		ft_len(char **tab);
int		check_in(char *str);
t_list	*get_tab(char **tab);
void	fillit(char *str);

#endif