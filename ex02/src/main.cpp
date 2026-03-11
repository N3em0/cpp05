#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
  try
  {
    Bureaucrat b("r1", 1);
    ShrubberyCreationForm fa("janette");
    RobotomyRequestForm fb("jean");
    PresidentialPardonForm fc("jacques");
    b.executeForm(fa);
    b.signForm(fa);
    b.signForm(fb);
    b.signForm(fc);
    b.executeForm(fa);
    b.executeForm(fb);
    b.executeForm(fc);
  }
  catch (std::exception &e)
  {
  }
  std::cout << "====================================================" << std::endl;
  // try
  // {
  //   Bureaucrat c("r2", 150);
  //   Form fc("b", 151, 151);
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << "Error Form Grade too low" << std::endl;
  // }
  // std::cout << "====================================================" << std::endl;
  // try
  // {
  //   Bureaucrat c("r2", 150);
  //   Form fd("b", 0, 0);
  // }
  // catch (std::exception &e)
  // {
  //   std::cout << "Error Form Grade too high" << std::endl;
  // }
  // std::cout << "====================================================" << std::endl;
  return 0;
}
