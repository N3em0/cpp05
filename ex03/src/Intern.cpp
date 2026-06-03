#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

Intern::Intern() {}

Intern::Intern(Intern const &src) { (void)src; }

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
  (void)rhs;
  return (*this);
}

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

AForm *Intern::makeForm(std::string name, std::string target)
{
  std::string names[3] = {"shrubbery creation", "robotomy request",
                          "presidential pardon"};
  AForm *(*ft_ptrFunctions[3])(std::string target) = {
      &makeShrubbery, &makeRobotomy, &makePresident};

  for (size_t i = 0; i < 3; i++)
  {
    if (names[i] == name)
    {
      std::cout << "Intern creates " << names[i] << " form" << std::endl;
      return ((*ft_ptrFunctions[i])(target));
    }
  }
  throw std::invalid_argument("Warning: " + name + " is an invalid name");
  return (0);
}
