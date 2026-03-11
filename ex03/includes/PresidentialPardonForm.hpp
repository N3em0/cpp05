#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm
{
private:
  std::string _target;

public:
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm(std::string target);
  ~PresidentialPardonForm();

PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

void execute(Bureaucrat const &executor) const;
};

#endif
