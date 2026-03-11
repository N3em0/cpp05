#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Me") {}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
  if (this != &rhs)
    this->_target = rhs._target;
  return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
  static size_t success = 0;
  AForm::execute(executor);
  std::cout << "--- VRRRRRrrrrRRRrrRrrRRRRRRRR ---" << std::endl;
  if (success % 2 == 0)
    std::cout << this->_target << " has been robotomized successfully" << std::endl;
  else
    std::cout << "Robotomy failed" << std::endl;
  success++;
}
