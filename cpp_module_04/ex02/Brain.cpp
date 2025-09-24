/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:13:42 by meid              #+#    #+#             */
/*   Updated: 2025/09/24 13:13:43 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

static std::string create_idea(std::string type, int idea_num)
{
    std::stringstream ss;
    ss << idea_num;
    return(type + " " + ss.str());
}

Brain::Brain()
{
    int i = 0;
    while(i < 100)
    {
        _ideas[i] = create_idea("generic animal", i + 1);
        i++;  // Add this line!
    }
    std::cout << GREEN << "Brain constructor called" << RESET << std::endl;
}

Brain::Brain(std::string type)
{
    int i = 0;
    while(i < 100)
    {
        _ideas[i] = create_idea(type, i + 1);
        i++;  // Add this line!
    }
    std::cout << GREEN << "Brain constructor called" << RESET << std::endl;
}
Brain::Brain(const Brain& other)
{
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = other._ideas[i];
    std::cout << BLUE << "Brain Copy constructor called" << RESET << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->_ideas[i] = other._ideas[i];
    }
    std::cout << YELLOW << "Brain Copy assignment operator called" << RESET << std::endl;
    return (*this);
}

Brain::~Brain()
{
    std::cout << RED << "Brain destructor called" << RESET << std::endl;
}

std::string Brain::getIdea(int index) const
{
    if (index >= 0 && index < 100)
        return _ideas[index];
    return "Invalid index";
}

