#include "Form.hpp"

Form::Form()
    : _name("GenericForm"), _signed(false), _signGrade(150), _exeGrade(150)
{
}

Form::Form(const Form &src)
    : _name(src._name), _signed(src._signed), _signGrade(src._signGrade),
      _exeGrade(src._exeGrade)
{
}

Form::Form(std::string name, size_t signGrade, size_t exeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
  if (this->_signGrade > 150 || this->_exeGrade > 150)
    throw Form::GradeTooLowException();
  else if (this->_signGrade < 1 || this->_exeGrade < 1)
    throw Form::GradeTooHighException();
}

Form::~Form() {}

Form &Form::operator=(const Form &rhs)
{
  if (this != &rhs)
    this->_signed = rhs._signed;
  return (*this);
}

std::string const &Form::getName() const { return (this->_name); }

size_t const &Form::getSignGrade() const { return (this->_signGrade); }

size_t const &Form::getExeGrade() const { return (this->_exeGrade); }

bool const &Form::getSignedState() const { return (this->_signed); }

void Form::beSigned(Bureaucrat &b)
{
  if (b.getGrade() <= this->_signGrade)
    this->_signed = true;
  else
    throw Form::GradeTooLowException();
  return;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs)
{
  o << rhs.getName()
    << ", grade needed to sign the form : " << rhs.getSignGrade()
    << ", grade needed to execute the form : " << rhs.getExeGrade() << ". ";
  if (rhs.getSignedState() == true)
    o << "The form is already signed." << std::endl;
  else
    o << "The form isn't signed yet." << std::endl;
  return (o);
}

Form::GradeTooHighException::GradeTooHighException() {}

Form::GradeTooLowException::GradeTooLowException() {}
