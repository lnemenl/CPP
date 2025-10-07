#include "AForm.hpp"

AForm::AForm() : _name("unnamed"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
    //Setting values to 1 and only grade 1 bureaucrats can sign/execute (valid, but restrictive).
    // 150 is the most permissive (lowest grade), so any bureaucrat can sign/execute.
}

AForm::~AForm() {}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1) throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150) throw GradeTooLowException();
}

//Getter for name: returns a const reference to the name (no copy, not modifiable)
const std::string& AForm::getName() const
{
    return _name;
}

int AForm::getGradeToSign() const
{
    return _gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return _gradeToExecute;
}

bool AForm::isSigned() const
{
    return _isSigned;
}

// C++ Rule: Pass by const reference for efficiency and safety (no copy, not modified)
void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecution(const Bureaucrat& executor) const
{
    if (!_isSigned) throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "Grade too low";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
    return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Form '" << f.getName() << "', signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute();
    return os;
}


/*
namespace std {
  class exception {
  public:
    exception() noexcept;
    exception(const exception&) noexcept;
    exception& operator=(const exception&) noexcept;
    virtual ~exception();

    virtual const char* what() const noexcept; //this function will never throw an exception.
  };
}
*/