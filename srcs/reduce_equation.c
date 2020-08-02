/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_equation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"

void print_reduced(t_poly *poly_reduced)
{
  if (poly_reduced->c)
  {
    ft_putnbr(poly_reduced->c);
    ft_putstr(" + ");
  }
  if (poly_reduced->exp0)
  {
    ft_putnbr(poly_reduced->exp0);
    ft_putstr("* X^0 + ");
  }
  if (poly_reduced->exp1)
  {
    ft_putnbr(poly_reduced->exp1);
    ft_putstr("* X^1 + ");
  }
  if (poly_reduced->exp2)
  {
    ft_putnbr(poly_reduced->exp2);
    ft_putstr("* X^2 ");
  }
  ft_putstr("= 0\n");
}

void put_in_one(t_poly *poly, t_poly *poly2, t_poly *poly_reduced)
{
  poly_reduced->c = poly->c - poly2->c;
  poly_reduced->exp0 = poly->exp0 - poly2->exp0;
  poly_reduced->exp1 = poly->exp1 - poly2->exp1;
  poly_reduced->exp2 = poly->exp2 - poly2->exp2;
  print_reduced(poly_reduced);
}

void reduce_equation2(t_poly *poly, t_poly *poly2)
{
  if (poly->exp2 < poly2->exp2)
  {
    poly2->exp2 -= poly->exp2;
    poly->exp2 -= poly->exp2;
  }
  if (poly->exp1 < poly2->exp1)
  {
    poly2->exp1 -= poly->exp1;
    poly->exp1 -= poly->exp1;
  }
  if (poly->exp0 < poly2->exp0)
  {
    poly2->exp0 -= poly->exp0;
    poly->exp0 -= poly->exp0;
  }
}

void reduce_equation(t_poly *poly, t_poly *poly2, t_poly *poly_reduced)
{
  if (poly->exp2 >= poly2->exp2)
  {
    poly->exp2 -= poly2->exp2;
    poly2->exp2 -= poly2->exp2;
  }
  if (poly->exp1 >= poly2->exp1)
  {
    poly->exp1 -= poly2->exp1;
    poly2->exp1 -= poly2->exp1;
  }
  if (poly->exp0 >= poly2->exp0)
  {
    poly->exp0 -= poly2->exp0;
    poly2->exp0 -= poly2->exp0;
  }
  reduce_equation2(poly, poly2);
  put_in_one(poly, poly2, poly_reduced);
}
