/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:20 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 08:16:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(std::string *target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const PresidentialPardonForm& obj);