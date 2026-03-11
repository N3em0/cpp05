#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class ShrubberyCreationForm : public AForm
{
private:
  std::string _target;

public:
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm(std::string target);
  ~ShrubberyCreationForm();

ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

void execute(Bureaucrat const &executor) const;
};

#endif
