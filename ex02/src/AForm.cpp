#include "AForm.hpp"

AForm::AForm()
    : _name("GenericAForm"), _signed(false), _signGrade(150), _exeGrade(150)
{
}

AForm::AForm(const AForm &src)
    : _name(src._name), _signed(src._signed), _signGrade(src._signGrade),
      _exeGrade(src._exeGrade)
{
}

AForm::AForm(std::string name, size_t signGrade, size_t exeGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _exeGrade(exeGrade)
{
  if (this->_signGrade > 150 || this->_exeGrade > 150)
    throw AForm::GradeTooLowException();
  else if (this->_signGrade < 1 || this->_exeGrade < 1)
    throw AForm::GradeTooHighException();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &rhs)
{
  if (this != &rhs)
    this->_signed = rhs._signed;
  return (*this);
}

std::string const &AForm::getName() const { return (this->_name); }

size_t const &AForm::getSignGrade() const { return (this->_signGrade); }

size_t const &AForm::getExeGrade() const { return (this->_exeGrade); }

bool const &AForm::getSignedState() const { return (this->_signed); }

void AForm::beSigned(Bureaucrat &b)
{
  if (b.getGrade() <= this->_signGrade)
    this->_signed = true;
  else
    throw AForm::GradeTooLowException();
  return;
}

void AForm::execute(Bureaucrat const &executor) const
{
  if (executor.getGrade() > this->getExeGrade())
    throw Bureaucrat::GradeTooLowException();
  else if (this->getSignedState() == false)
    throw AForm::FormNotSignedException();
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs)
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

AForm::GradeTooHighException::GradeTooHighException() {}

AForm::GradeTooLowException::GradeTooLowException() {}

AForm::FormNotSignedException::FormNotSignedException() {}
