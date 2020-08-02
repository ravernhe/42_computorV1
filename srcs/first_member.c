/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_member.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"

void apply_sign(t_poly *poly, t_poly *poly2, char *equation, int i, int val)
{
  if (equation[i] == '+' || equation[i] == '*')
  {
    i = skip(equation, i);
    get_term(poly, poly2, equation, i, 1, val);
  }
  else if (equation[i] == '-')
  {
    i = skip(equation, i);
    get_term(poly, poly2, equation, i, -1, val);
  }
  else if (equation[i] == '=')
  {
    i = skip(equation, i);
    if (poly->exp0 == poly->exp1 == poly->exp2 == 0)
      poly->c = val;
    get_term2(poly2, equation, i, 1, val);
  }
}

void get_expose(int expose, t_poly *poly, int val)
{
  if (expose > 2)
  {
    ft_putstr("Polynomian degree strictly greater than 2.\n");
    exit(1);
  }
  if (expose == 0)
    poly->exp0 += val;
  if (expose == 1)
    poly->exp1 += val;
  if (expose == 2)
    poly->exp2 += val;
}

void get_term(t_poly *poly, t_poly *poly2, char *equation, int i, int sign, int val)
{
  int expose;

  expose = -1;
  if (equation + i == '\0')
    return ;
  if (equation[i] == 'X')
  {
    i += 2;
    expose = ft_atoi(equation + i);
    if (equation[i - 1] != '^')
      expose = 1;
    get_expose(expose, poly, val);
  }
  else if (expose == -1 && (equation[i + 2] == '+' ||\
    equation[i + 2] == '-' || equation[i + 1] == '\0'))
    poly->c += (ft_atoi(equation + i) * sign);
  else
    val = ft_atoi(equation + i);
  i = skip(equation, i);
  apply_sign(poly, poly2, equation, i, val * sign);
}
