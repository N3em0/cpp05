#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
  try
  {
    Bureaucrat b("r1", 150);
    Form fa("A", 150, 150);
    Form fb("b", 149, 149);
    std::cout << b << fa << fb << std::endl;
    b.signForm(fa);
    b.signForm(fb);
    ++b;
    b.signForm(fb);
    std::cout << b << fa << fb << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "===================================================="
            << std::endl;
  try
  {
    Bureaucrat c("r2", 150);
    Form fc("b", 151, 151);
  }
  catch (std::exception &e)
  {
    std::cout << "Form " << e.what() << std::endl;
  }
  std::cout << "===================================================="
            << std::endl;
  try
  {
    Bureaucrat c("r2", 150);
    Form fd("b", 0, 0);
  }
  catch (std::exception &e)
  {
    std::cout << "Form " << e.what() << std::endl;
  }
  std::cout << "===================================================="
            << std::endl;
  return 0;
}
