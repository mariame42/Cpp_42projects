/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:01:52 by meid              #+#    #+#             */
/*   Updated: 2025/07/12 16:26:26 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <cctype>

int main(int ac, char **av) {
    if (ac == 1)
    {
        std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }
    int j = 1;
    while (av[j])
    {
        std::string firstarg = av[j];
        size_t i = 0;
        while (i < firstarg.length())
        {
            std::cout << static_cast<char>(toupper((firstarg[i])));
            i++;
        }
        j++;
    }
    std::cout << std::endl;
    return 0;
}