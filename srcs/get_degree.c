/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_degree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:25:22 by ravernhe          #+#    #+#             */
/*   Updated: 2020/03/09 12:30:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/computerv1.h"

int get_degree(t_poly *poly_reduced)
{
  if (poly_reduced->exp2 != 0)
  {
    ft_putstr("Polynomial degree: 2\n");
    return (2);
  }
  else if (poly_reduced->exp1 != 0)
  {
    ft_putstr("Polynomial degree: 1\n");
    return (1);
  }
  else
  {
    ft_putstr("Polynomial degree: 0\n");
    return (0);
  }
}
