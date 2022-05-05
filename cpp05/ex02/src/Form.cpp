#include "Form.hpp"

// ----------------------------- Constructors ------------------------------ //
Form::Form() : name(""), form_signed(false), sign_grade(1), exec_grade(1)
{
	_FORM_AUTO(32, "Default Constructor");
}

Form::Form(const Form &c)
	: name(c.get_name()),
	  form_signed(c.get_form_signed()),
	  sign_grade(c.get_sign_grade()),
	  exec_grade(c.get_exec_grade())
{
	_FORM_AUTO(32, "Copy Constructor");
	form_signed = c.get_form_signed();
}

Form::Form(const std::string in_name, int in_sign_grade, int in_exec_grade)
	: name(in_name),
	  form_signed(false),
	  sign_grade(in_sign_grade),
	  exec_grade(in_exec_grade)
{
	_FORM_AUTO(32, "Fields Constructor");
	check_grade(sign_grade);
	check_grade(exec_grade);
}

// ------------------------------ Destructor ------------------------------- //
Form::~Form()
{
	_FORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

Form &Form::operator=(const Form &c)
{
	form_signed = c.get_form_signed();

	return *this;
}
std::ostream &operator<<(std::ostream &o, const Form &inp)
{
	return o << inp.get_name()
			 << ", form_signed " << inp.get_form_signed()
			 << ", form sign grade " << inp.get_sign_grade()
			 << ", form exec grade" << inp.get_exec_grade();
}

// --------------------------- Getters && Setters -------------------------- //
const std::string Form::get_name() const { return name; }
bool Form::get_form_signed() const { return form_signed; }
int Form::get_sign_grade() const { return sign_grade; }
int Form::get_exec_grade() const { return exec_grade; }

// --------------------------------- Methods ------------------------------- //

void Form::check_grade(int grade)
{
	if (grade < MIN_GRADE)
	{
		throw Form::GradeTooHighException();
	}
	if (grade > MAX_GRADE)
	{
		throw Form::GradeTooLowException();
	}
}

void Form::beSigned(Bureaucrat &inp)
{

	if (inp.get_grade() <= sign_grade)
	{
		form_signed = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}
