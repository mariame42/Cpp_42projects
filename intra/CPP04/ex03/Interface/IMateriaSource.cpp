/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:10:06 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 18:07:31 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include <cstdlib>

IMateriaSource::IMateriaSource()
{
    ;
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
    (void)other;
}

IMateriaSource& IMateriaSource::operator=(const IMateriaSource& other)
{
    (void)other;
    return *this;
}