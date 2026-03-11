#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Form
{
private:
  const std::string _name;
  bool _signed;
  const size_t _signGrade;
  const size_t _exeGrade;

public:
  Form();
  Form(const Form &src);
  Form(std::string name, size_t signGrade, size_t exeGrade);
  ~Form();

  Form &operator=(const Form &rhs);

  std::string const &getName(void) const;
  size_t const &getSignGrade(void) const;
  size_t const &getExeGrade(void) const;
  bool const &getSignedState(void) const;

  void beSigned(Bureaucrat &b);

  class GradeTooHighException : public std::exception
  {
  public:
    GradeTooHighException();
    virtual const char *what() const throw() { return ("Grade is too high\n"); }
  };

  class GradeTooLowException : public std::exception
  {
  public:
    GradeTooLowException();
    virtual const char *what() const throw() { return ("Grade is too low\n"); }
  };
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
