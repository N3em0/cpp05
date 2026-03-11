#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Me") {}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
  if (this != &rhs)
    this->_target = rhs._target;
  return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
  AForm::execute(executor);
  std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
