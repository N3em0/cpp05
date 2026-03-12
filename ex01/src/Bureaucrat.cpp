#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

Bureaucrat::Bureaucrat() : _name("John"), _grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::Bureaucrat(std::string name, size_t grade)
    : _name(name), _grade(grade)
{
  if (this->_grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (this->_grade < 1)
    throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
  if (this != &rhs)
    this->_grade = rhs._grade;
  return (*this);
}

Bureaucrat &Bureaucrat::operator++()
{
  if (this->_grade - 1 < 1)
    throw Bureaucrat::GradeTooHighException();
  else
    this->_grade--;
  return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
  if (this->_grade + 1 > 150)
    throw Bureaucrat::GradeTooLowException();
  else
    this->_grade++;
  return (*this);
}

std::string const &Bureaucrat::getName() const { return (this->_name); }

size_t const &Bureaucrat::getGrade() const { return (this->_grade); }

void Bureaucrat::signForm(Form &f)
{
  try
  {
    f.beSigned(*this);
    std::cout << this->_name << " signed " << f.getName() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cout << this->_name << " couldn't sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."
    << std::endl;
  return (o);
}

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}
