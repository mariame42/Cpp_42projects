/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 18:08:14 by meid              #+#    #+#             */
/*   Updated: 2025/10/30 08:16:59 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(std::string *target);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
};

std::ostream& operator<<(std::ostream& out, const RobotomyRequestForm& obj);