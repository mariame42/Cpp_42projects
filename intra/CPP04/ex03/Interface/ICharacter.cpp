/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:09:56 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 18:07:40 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include <cstdlib>

ICharacter::ICharacter()
{
    ;
}

ICharacter::ICharacter(const ICharacter& other)
{
    (void)other;
}

ICharacter& ICharacter::operator=(const ICharacter& other)
{
    (void)other;
    return *this;
}