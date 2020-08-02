/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"


void get_solution(t_poly *poly_reduced, int degree)
{
  if (degree == 0)
    solve_degree_0(poly_reduced);
  if (degree == 1)
    solve_degree_1(poly_reduced);
  if (degree == 2)
    solve_degree_2(poly_reduced);
}
