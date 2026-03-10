#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception> // std::exception
#include <iostream>

class Form;

class Bureaucrat
{
private:
  const std::string _name;
  size_t _grade;

public:
  Bureaucrat();
  Bureaucrat(std::string name, size_t grade);
  Bureaucrat(const Bureaucrat &src);
  ~Bureaucrat();

  Bureaucrat &operator=(const Bureaucrat &rhs);
  Bureaucrat &operator++();
  Bureaucrat &operator--();

  std::string const &getName(void) const;
  size_t const &getGrade(void) const;

  void signForm(Form &f);

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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
