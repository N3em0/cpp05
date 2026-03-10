#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("John"), _grade(150)
{
  std::cout << "coucou a tous\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
    : _name(src._name), _grade(src._grade)
{
}

Bureaucrat::Bureaucrat(std::string name, size_t grade)
try : _name(name), _grade(grade)
{
  if (this->_grade > 150)
    throw Bureaucrat::GradeTooLowException();
  else if (this->_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else
    std::cout << "Bureaucrat is good" << std::endl;
}
catch (Bureaucrat::GradeTooLowException &e)
{
  std::cout << e.what();
  // throw;
}
catch (Bureaucrat::GradeTooHighException &e)
{
  std::cout << e.what();
  // throw;
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
  try
  {
    if (this->_grade - 1 < 1)
      throw Bureaucrat::GradeTooHighException();
    else
      this->_grade--;
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << e.what();
  }
  return (*this);
}

Bureaucrat &Bureaucrat::operator--()
{
  try
  {
    if (this->_grade + 1 > 150)
      throw Bureaucrat::GradeTooLowException();
    else
      this->_grade++;
  }
  catch (Bureaucrat::GradeTooHighException &e)
  {
    std::cout << e.what();
  }
  return (*this);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."
    << std::endl;
  return o;
}

std::string const &Bureaucrat::getName() const { return (this->_name); }

size_t const &Bureaucrat::getGrade() const { return (this->_grade); }

Bureaucrat::GradeTooHighException::GradeTooHighException() {}

Bureaucrat::GradeTooLowException::GradeTooLowException() {}

void Bureaucrat::signForm(Form &f)
{
  if (f.beSigned(*this) == true)
      std::cout << this->_name << " signed " << f.getName() << std::endl;
  else
      std::cout << this->_name << " couldn't sign " << f.getName() << " because grade is too low" << std::endl;
}
