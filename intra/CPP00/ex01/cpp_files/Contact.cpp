/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:01:31 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 15:38:47 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hpp_files/Contact.hpp"

void Contact::setFirstName(std::string fName) { _firstName = fName; }
void Contact::setLastName(std::string lName) { _lastName = lName; }
void Contact::setNickname(std::string nName) { _nickName = nName; }
void Contact::setPhoneNumber(std::string pNumber) { _phoneNumber = pNumber; }
void Contact::setDarkestSecret(std::string dSecret) { _darkestSecret = dSecret; }

// getters
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickName; }
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }