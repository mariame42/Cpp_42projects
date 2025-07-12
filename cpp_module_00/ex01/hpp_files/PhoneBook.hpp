/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:52:31 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 15:54:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "libraries_micro.hpp"
#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contact[8];
        int _pos;
        int _count;

        int getCount() const;
        int get_pos() const;
        Contact getContact(int index) const;

        void add_function();
        void search_function();

        void addContact(const Contact& newContact);
        int check_phonenumber(const std::string& phone_number);
    
    public:
        PhoneBook();
        void startYourPhonebookApp();
};

#endif

// void add_function(PhoneBook& phoneBook);
// void search_function(PhoneBook& phoneBook);