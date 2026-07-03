/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:53:09 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 15:39:02 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
#define MAIN_H

#include "libraries_micro.hpp"
#include "PhoneBook.hpp"


void displayc_ten_char(const std::string& str);
bool containsOnlySpaces(const std::string& str);
bool is_number(const std::string& str);
std::string check_for_eof_and_print(const std::string& prompt, const std::string& color);
int name_check(const std::string& name);

#endif