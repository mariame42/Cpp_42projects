/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 15:56:09 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 20:02:27 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_hpp
# define Form_hpp

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
    private :
        const std::string _name;
        bool _is_signed;
        const size_t _gradeToSign;
        const size_t _gradeToExecute;

    public :
        Form(std::string name, 
            size_t gradeToSign,
            size_t gradeToExecute);
        Form(std::string *name, 
            size_t gradeToSign,
            size_t gradeToExecute);
        ~Form();
        Form(const Form& other);
        Form& operator=(const Form& other);

        std::string get_name() const;
        bool get_is_signed() const;
        size_t get_gradeToSign() const;
        size_t get_gradeToExecute() const;

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

        void beSigned(Bureaucrat bureaucrat);

};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif