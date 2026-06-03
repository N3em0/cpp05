#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception> // std::exception
#include <iostream>

class AForm;

class Bureaucrat
{
private:
  const std::string _name;
  int _grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &rhs);
  Bureaucrat &operator++();
  Bureaucrat &operator--();

  std::string const &getName(void) const;
  int const &getGrade(void) const;

  void signForm(AForm &f);
  void executeForm(AForm const &form) const;

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
