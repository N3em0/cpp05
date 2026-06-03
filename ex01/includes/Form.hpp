#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>

class Form
{
private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _exeGrade;

public:
  Form();
  Form(const Form &src);
  Form(std::string name, int signGrade, int exeGrade);
  ~Form();

  Form &operator=(const Form &rhs);

  std::string const &getName(void) const;
  int const &getSignGrade(void) const;
  int const &getExeGrade(void) const;
  bool const &getSignedState(void) const;

  void beSigned(Bureaucrat &b);

  class GradeTooHighException : public std::exception
  {
  public:
    GradeTooHighException();
    virtual const char *what() const throw() { return ("Grade is too high"); }
  };

  class GradeTooLowException : public std::exception
  {
  public:
    GradeTooLowException();
    virtual const char *what() const throw() { return ("Grade is too low"); }
  };
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
