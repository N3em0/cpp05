#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
  Intern Intern;
  AForm *formA;
  AForm *formB;
  AForm *formC;

  formA = Intern.makeForm("robotomy request", "Jack");
  formB = Intern.makeForm("shrubbery creation", "Jack");
  formC = Intern.makeForm("presidential pardon", "Jack");
  if (formA && formB && formC)
  {
    try
    {
      Bureaucrat a("r1", 1);
      a.signForm(*formA);
      a.executeForm(*formA);
      std::cout << "----------------------------------------------------"
                << std::endl;
      a.signForm(*formB);
      a.executeForm(*formB);
      std::cout << "----------------------------------------------------"
                << std::endl;
      a.signForm(*formC);
      a.executeForm(*formC);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  delete formA;
  delete formB;
  delete formC;
  std::cout << "\n====================================================\n"
            << std::endl;

  AForm *formD;
  formD = Intern.makeForm("rabatamy request", "Jack");
  if (formD)
  {
    try
    {
      Bureaucrat b("r2", 150);
      b.signForm(*formD);
      b.executeForm(*formD);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  delete formD;
  std::cout << "\n====================================================\n"
            << std::endl;

  AForm *formE;
  formE = Intern.makeForm("robotomy request", "");
  if (formE)
  {
    try
    {
      Bureaucrat c("r3", 151);
      --c;
      c.signForm(*formE);
      c.executeForm(*formE);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  }
  delete formE;
  std::cout << "\n===================================================="
            << std::endl;
  return 0;
}
