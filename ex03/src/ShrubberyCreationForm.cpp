#include "ShrubberyCreationForm.hpp"
#include <fstream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("home") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
  if (this != &rhs)
    this->_target = rhs._target;
  return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
  AForm::execute(executor);
  std::ofstream outfile((this->_target + "_shrubbery").c_str());
  outfile << "            .        +          .      .          ." << std::endl;
  outfile << "     .            _        .                    .  " << std::endl;
  outfile << ",              /;-._,-.____        ,-----.__       " << std::endl;
  outfile << "((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
  outfile << "`                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
  outfile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
  outfile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
  outfile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
  outfile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
  outfile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
  outfile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
  outfile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
  outfile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
  outfile << "                    \\::.  :\\/:'  /              +" << std::endl;
  outfile << "   .                 `.:.  /:'  }      ." << std::endl;
  outfile << "           .           ):_(:;   \\           ." << std::endl;
  outfile << "                      /:. _/ ,  |" << std::endl;
  outfile << "                   . (|::.     ,`                  ." << std::endl;
  outfile << "     .                |::.    {\\" << std::endl;
  outfile << "                      |::.\\  \\ `." << std::endl;
  outfile << "                     |:::(\\    |" << std::endl;
  outfile << "              O       |:::/{ }  |                  (o" << std::endl;
  outfile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
  outfile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
  outfile << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
  outfile << "            .        +          .      .          ." << std::endl;
  outfile << "     .            _        .                    .  " << std::endl;
  outfile << ",              /;-._,-.____        ,-----.__       " << std::endl;
  outfile << "((        .    (_:#::_.:::. `-._   /:, /-._, `._," << std::endl;
  outfile << "`                 \\   _|`\"=:_::.`.);  \\ __/ /" << std::endl;
  outfile << "                      ,    `./  \\:. `.   )==-'  ." << std::endl;
  outfile << "    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           ." << std::endl;
  outfile << ".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o" << std::endl;
  outfile << "       .    /:+- - + +- : :- + + -:'  /(o-) \\)     ." << std::endl;
  outfile << "  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7" << std::endl;
  outfile << "   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/" << std::endl;
  outfile << "              \\:  `  X` _| _,\\/'   .-'" << std::endl;
  outfile << ".               \":._:`\\____  /:'  /      .           ." << std::endl;
  outfile << "                    \\::.  :\\/:'  /              +" << std::endl;
  outfile << "   .                 `.:.  /:'  }      ." << std::endl;
  outfile << "           .           ):_(:;   \\           ." << std::endl;
  outfile << "                      /:. _/ ,  |" << std::endl;
  outfile << "                   . (|::.     ,`                  ." << std::endl;
  outfile << "     .                |::.    {\\" << std::endl;
  outfile << "                      |::.\\  \\ `." << std::endl;
  outfile << "                     |:::(\\    |" << std::endl;
  outfile << "              O       |:::/{ }  |                  (o" << std::endl;
  outfile << "               )  ___/#\\::`/ (O \"==._____   O, (O  /`" << std::endl;
  outfile << "          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~" << std::endl;
  outfile << "      ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~" << std::endl;
}
