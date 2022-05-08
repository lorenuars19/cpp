#include "ShrubberyCreationForm.hpp"

// ----------------------------- Constructors ------------------------------ //
ShrubberyCreationForm::ShrubberyCreationForm()
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Default Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &c)
	: Form(c.get_name(), c.get_sign_grade(), c.get_exec_grade()), target(c.get_target())

{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Copy Constructor");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string in_target)
	: Form("ShrubberyCreationForm", 145, 137), target(in_target)
{
	_SHRUBBERYCREATIONFORM_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	_SHRUBBERYCREATIONFORM_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &c)
{
	target = c.get_target();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
std::string ShrubberyCreationForm::get_target() const { return target; }
void ShrubberyCreationForm::set_target(std::string input) { target = input; }

// --------------------------------- Methods ------------------------------- //

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename;
	std::ofstream file;

	if (this->get_form_signed() == false)
	{
		throw FormNotSignedExeption();
	}

	if (this->get_exec_grade() < executor.get_grade())
	{
		throw GradeTooLowException();
	}
	filename = target + "_shrubbery";
	file.open(filename.c_str(), std::ofstream::out | std::ofstream::trunc);

	file << ""
		 << "                 * *              " << '\n'
		 << "             *    *  *            " << '\n'
		 << "        *  *    *     *  *        " << '\n'
		 << "       *     *    *  *    *       " << '\n'
		 << "   * *   *    *    *    *   *     " << '\n'
		 << "   *     *  *    * * .#  *   *    " << '\n'
		 << "   *   *     * #.  .# *   *       " << '\n'
		 << "    *     ' #.# : #' * *    *     " << '\n'
		 << "   *   * * ' #.##'       *        " << '\n'
		 << "     *       '## #'               " << '\n'
		 << "               '##                " << '\n'
		 << "                ##.               " << '\n'
		 << "                .##:              " << '\n'
		 << "                :###              " << '\n'
		 << "                ;###              " << '\n'
		 << "              ,####.              " << '\n'
		 << "            .######.              " << '\n'
		 << std::endl;
	file.close();
}
