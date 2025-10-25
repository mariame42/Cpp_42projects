#ifndef Form_hpp
# define Form_hpp

#include "Bureaucrat.hpp"

class Form
{
    private :
        const std::string _name;
        bool _is_signed;
        size_t _sign_required;
        size_t _execute_required;

    public :
        Form(std::string name, 
            size_t sign_required,
            size_t execute_required);
        ~Form();
        // Form(const Form& other);
        // Form& operator=(const Form& other);

        std::string get_name();
        bool get_is_signed();
        size_t get_sign_required();
        size_t get_execute_required();

        class GradeTooHighException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return "Grade is too high";
            }
        };
        
        class GradeTooLowException : public std::exception
        {
            public:
            virtual const char* what() const throw()
            {
                return "Grade is too low";
            }
        };

        void beSigned(Bureaucrat bureaucrat);

};

// std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

#endif