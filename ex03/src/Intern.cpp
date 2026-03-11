#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src) {}

Intern::~Intern() {}

AForm *makeShrubbery(std::string target)
{
  AForm *form = new ShrubberyCreationForm(target);
  return (form);
}

AForm *makeRobotomy(std::string target)
{
  AForm *form = new RobotomyRequestForm(target);
  return (form);
}

AForm *makePresident(std::string target)
{
  AForm *form = new PresidentialPardonForm(target);
  return (form);
}

AForm *Intern::makeForm(std::string target)
{
  std::string levels[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm *(Intern::*ft_ptrFunctions[3])(std::string target) = { &makeShrubbery, &makeRobotomy, &makePresident};

  for (size_t i = 0; i < 3; i++)
  {
    if (levels[i] == level)
    {
       std::cout << "Intern creates " << levels[i];
      return ((this->*ft_ptrFunctions[i])(target));
    }
    std::cout << "Error form name doesn't exists" << std::endl;
  }
  // switch (name) {
  // case 1:
  //     AForm *form = new ShrubberyCreationForm();
  //     return (form);
  //     break;
  // case 2:
  //     AForm *form = new RobotomyRequestForm();
  //     return (form);
  //     break;
  // case 3:
  //     AForm *form = new PresidentialPardonForm();
  //     return (form);
  //     break;
  // default:
  //     std::cout << "This form type doesn't exists" << std::endl;
  //     break;
  // }
}

