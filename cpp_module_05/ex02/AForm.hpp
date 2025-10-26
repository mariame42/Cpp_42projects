/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 17:26:27 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 20:24:56 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_hpp
# define AForm_hpp

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
    private :
        const std::string _name;
        bool _is_signed;
        const size_t _sign_required;
        const size_t _execute_required;

    public :
        AForm(std::string name, 
            size_t sign_required,
            size_t execute_required);
        AForm(std::string *name, 
            size_t sign_required,
            size_t execute_required);
        ~AForm();
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        std::string get_name() const;
        bool get_is_signed() const;
        size_t get_sign_required() const;
        size_t get_execute_required() const;

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        virtual void beSigned(Bureaucrat bureaucrat) = 0;
        virtual void execute(Bureaucrat const & executor) = 0;

};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif