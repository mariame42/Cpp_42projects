/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:08 by meid              #+#    #+#             */
/*   Updated: 2025/10/26 20:25:47 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    // private:
    //     /* data */
    public:
        ShrubberyCreationForm(std::string target);
        ~ShrubberyCreationForm();
        void beSigned(Bureaucrat bureaucrat);
        void execute(Bureaucrat const & executor);
};

std::ostream& operator<<(std::ostream& out, const ShrubberyCreationForm& obj);