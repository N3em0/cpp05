#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
  try
  {
    Bureaucrat b("r1", 1);
    ShrubberyCreationForm fa("janette");
    RobotomyRequestForm fb("jean");
    PresidentialPardonForm fc("jacques");
    b.signForm(fa);
    b.executeForm(fa);
    std::cout << "\n====================================================\n"
              << std::endl;
    b.signForm(fb);
    b.executeForm(fb);
    std::cout << "\n====================================================\n"
              << std::endl;
    b.signForm(fc);
    b.executeForm(fc);
  }
  catch (std::exception &e)
  {
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  try
  {
    Bureaucrat ba("r1", 137);
    ShrubberyCreationForm fa("target");
    ba.signForm(fa);
    ba.executeForm(fa);
    std::cout << "----------------------------------------------------"
              << std::endl;
    Bureaucrat bb("r2", 145);
    ShrubberyCreationForm fb("target");
    bb.signForm(fb);
    bb.executeForm(fb);
  }
  catch (std::exception &e)
  {
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  try
  {
    Bureaucrat ba("r1", 150);
    PresidentialPardonForm fa("President");
    ba.signForm(fa);
    ba.executeForm(fa);
  }
  catch (std::exception &e)
  {
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  return 0;
}
