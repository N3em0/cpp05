#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class RobotomyRequestForm : public AForm
{
private:
  std::string _target;

public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm(std::string target);
  ~RobotomyRequestForm();

RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

void execute(Bureaucrat const &executor) const;
};

#endif
