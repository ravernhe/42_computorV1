/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_member.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"

void apply_sign2(t_poly *poly2, char *equation, int i, int val)
{
  if (equation[i] == '+' || equation[i] == '*')
  {
    i = skip(equation, i);
    get_term2(poly2, equation, i, 1, val);
  }
  else if (equation[i] == '-')
  {
    i = skip(equation, i);
    get_term2(poly2, equation, i, -1, val);
  }
}

void get_expose2(int expose, t_poly *poly2, int val)
{
  if (expose > 2)
    exit(1); //Print Error exposant
  if (expose == 0)
    poly2->exp0 += val;
  if (expose == 1)
    poly2->exp1 += val;
  if (expose == 2)
    poly2->exp2 += val;
}

void get_term2(t_poly *poly2, char *equation, int i, int sign, int val)
{
  int expose;

  expose = -1;
  if (equation + i == '\0')
    return ;
  if (equation[i] == 'X')
  {
    i += 2;
    expose = ft_atoi(equation + i);
    get_expose2(expose, poly2, val);
  }
  else if (expose == -1 && (equation[i + 2] == '+' ||\
    equation[i + 2] == '-' || equation[i + 1] == '\0'))
    poly2->c += (ft_atoi(equation + i) * sign);
  else
    val = ft_atoi(equation + i);
  i = skip(equation, i);
  apply_sign2(poly2, equation, i, val * sign);
}
