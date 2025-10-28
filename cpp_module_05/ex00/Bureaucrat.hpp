/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:55:42 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 17:08:58 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_hpp
# define Bureaucrat_hpp

#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[31m"
#define PURPLE "\033[35m"
#define RESET "\033[0m"
#define ORANGE "\033[38;2;255;165;0m"
#define Cyan "\033[36m"

#define Magenta "\033[35m"

static const bool OCCF =  0;

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        const std::string   _name;
        size_t              _grade;
        size_t              _max_gride;
        size_t              _min_gride;

    public:
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const std::string *name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();
        
        const std::string   get_name() const;
        size_t              get_grade() const;
        void                increment_grade();
        void                decrement_grade();
        
        class GradeTooHighException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "Grade is too high";
            }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
            const char* what() const throw()
            {
                return "Grade is too low";
            }
        };
    };
    
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);
#endif