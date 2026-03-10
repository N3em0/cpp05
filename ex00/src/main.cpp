#include "Bureaucrat.hpp"

int main(void)
{
  try
  {
    Bureaucrat a;
  }
  catch (std::exception &e)
  {
    std::cout << "wtf 1" << std::endl;
  }
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
    std::cout << "wtf 2" << std::endl;
  }
  try
  {
    Bureaucrat c("r2", 151);
  }
  catch (std::exception &e)
  {
    std::cout << "wtf 3" << std::endl;
  }
  try
  {
    Bureaucrat d("r3", 0);
  }
  catch (std::exception &e)
  {
    std::cout << "wtf 4" << std::endl;
  }
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
