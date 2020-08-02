/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"

int		skip(char *str, int i)
{
	while (str[i] && str[i] > 32 && str[i] != 'X')
		i++;
	while (str[i] && str[i] <= 32 && str[i] != 'X')
		i++;
	return (i);
}

void init_poly(t_poly *poly)
{
  poly->c = 0;
  poly->exp0 = 0;
  poly->exp1 = 0;
  poly->exp2 = 0;
}

void compute_equation(char *equation)
{
  t_poly  poly;
  t_poly  poly2;
	t_poly  poly_reduced;
	int			degree;

  init_poly(&poly);
  init_poly(&poly2);
	init_poly(&poly_reduced);
  get_term(&poly, &poly2, equation, 0, 1, 0);
	reduce_equation(&poly, &poly2, &poly_reduced);
	degree = get_degree(&poly_reduced);
	get_solution(&poly_reduced);
}
