#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class AForm
{
private:
  const std::string _name;
  bool _signed;
  const size_t _signGrade;
  const size_t _exeGrade;

public:
  AForm();
  AForm(const AForm &src);
  AForm(std::string name, size_t signGrade, size_t exeGrade);
  virtual ~AForm();

  AForm &operator=(const AForm &rhs);

  std::string const &getName(void) const;
  size_t const &getSignGrade(void) const;
  size_t const &getExeGrade(void) const;
  bool const &getSignedState(void) const;

  void beSigned(Bureaucrat &b);
  virtual void execute(Bureaucrat const &executor) const = 0;

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

  class FormNotSignedException : public std::exception
  {
  public:
    FormNotSignedException();
    virtual const char *what() const throw() { return ("Form isn't signed"); }
  };
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
