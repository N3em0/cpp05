#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
  Intern Intern;
  AForm *formA = NULL;
  AForm *formB = NULL;
  AForm *formC = NULL;

  try
  {
    formA = Intern.makeForm("robotomy request", "Jack");
    formB = Intern.makeForm("shrubbery creation", "Jack");
    formC = Intern.makeForm("presidential pardon", "Jack");
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
    delete formA;
    formA = NULL;
    delete formB;
    formB = NULL;
    delete formC;
    formC = NULL;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    delete formA;
    formA = NULL;
    delete formB;
    formB = NULL;
    delete formC;
    formC = NULL;
  }
  std::cout << "\n====================================================\n"
            << std::endl;

  AForm *formD = NULL;
  try
  {
    formD = Intern.makeForm("rabatamy reques", "Jack");
    Bureaucrat b("r2", 150);
    b.signForm(*formD);
    b.executeForm(*formD);
    delete formD;
    formD = NULL;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    delete formD;
    formD = NULL;
  }
  std::cout << "\n====================================================\n"
            << std::endl;

  AForm *formE = NULL;
  try
  {
    formE = Intern.makeForm("robotomy request", "");
    Bureaucrat c("r3", 151);
    --c;
    c.signForm(*formE);
    c.executeForm(*formE);
    delete formE;
    formE = NULL;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    delete formE;
    formE = NULL;
  }
  std::cout << "\n===================================================="
            << std::endl;
  return 0;
}
