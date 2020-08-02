/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computerv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:15:28 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTERV1_H
# define COMPUTERV1_H

# include "../libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_poly
{
	int c;
	int exp0;
	int exp1;
	int exp2;
}								t_poly;

void	get_term(t_poly *poly, t_poly *poly2, char *equation, int i, int sign, int val);
void	get_term2(t_poly *poly2, char *equation, int i, int sign, int val);
void	apply_sign(t_poly *poly, t_poly *poly2, char *equation, int i, int val);
void	apply_sign2(t_poly *poly2, char *equation, int i, int val);
void	compute_equation(char *equation);
void	reduce_equation(t_poly *poly, t_poly *poly2, t_poly *poly_reduced);
void	get_degree(t_poly *poly_reduced);
void	get_solution(t_poly *poly_reduced, int degree);
int		skip(char *str, int i);

#endif
