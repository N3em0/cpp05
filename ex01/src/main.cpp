#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
  try
  {
    Bureaucrat b("r1", 150);
    Form fa("A", 150, 150);
    Form fb("b", 149, 149);
    std::cout << b << fa << fb << std::endl;
    b.signForm(fa);
    std::cout << b << fa << fb << std::endl;
    b.signForm(fb);
    ++b;
    b.signForm(fb);
  }
  catch (std::exception &e)
  {
    std::cout << "Error no error (i hope so)" << std::endl;
  }
  std::cout << "====================================================" << std::endl;
  try
  {
    Bureaucrat c("r2", 150);
    Form fc("b", 151, 151);
  }
  catch (std::exception &e)
  {
    std::cout << "Error Form Grade too low" << std::endl;
  }
  std::cout << "====================================================" << std::endl;
  try
  {
    Bureaucrat c("r2", 150);
    Form fd("b", 0, 0);
  }
  catch (std::exception &e)
  {
    std::cout << "Error Form Grade too high" << std::endl;
  }
  std::cout << "====================================================" << std::endl;
  return 0;
}

// int main()
//{
//  try
//  {
//    Bureaucrat a;
//    Bureaucrat b("r1", 100);
//    Bureaucrat c("r2", 151);
//    Bureaucrat d("r3", 0);
//
//  }
//  catch (std::exception &e)
//  {
//    std::cout << "wtf 1" << std::endl;
//  }
//  return 0;
//  }
