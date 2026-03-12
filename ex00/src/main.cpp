#include "Bureaucrat.hpp"

int main(void)
{
  try
  {
    Bureaucrat a;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  try
  {
    Bureaucrat b("r1", 150);
    std::cout << b << std::endl;
    std::cout << ++b << std::endl;
    std::cout << --b << std::endl;
    std::cout << --b << std::endl;
    std::cout << --b << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  try
  {
    Bureaucrat c("r2", 151);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "\n====================================================\n"
            << std::endl;
  try
  {
    Bureaucrat d("r3", 0);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
