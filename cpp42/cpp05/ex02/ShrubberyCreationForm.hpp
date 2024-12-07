/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cejin <cejin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:42:41 by cejin             #+#    #+#             */
/*   Updated: 2024/12/06 17:18:45 by cejin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

#define ASCII_TREE \
"            .        +          .      .          .\n" \
"     .            _        .                    .\n" \
"  ,              /;-._,-.____        ,-----.__\n" \
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n" \
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n" \
"                      ,    `./  \\:. `.   )==-'  .\n" \
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n" \
".           \\:/`-' , ,\\ '` ` `   ): , /_  -o\n" \
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n" \
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".--\"---._/`7\n" \
"   `.   (    \\: \\,-._` ` + '\\, ,\"   _,--._,---\":.__/\n" \
"              \\:  `  X` _| _,\\/'   .-'\n" \
".               \":._:`\\____  /:'  /      .           .\n" \
"                    \\::.  :\\/:/'  /              +\n" \
"   .                 `.:.  /:'  }      .\n" \
"           .           ):_(:;   \\           .\n" \
"                      /:. _/ ,  |\n" \
"                   . (|::.     ,`                  .\n" \
"     .                |::.    {\\\n" \
"                      |::.:\\  \\ `.\n" \
"                      |:::(\\    |\n" \
"              O       |:::/{ }  |                  (o\n" \
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n" \
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n" \
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~\n"


/*
Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory,
and writes ASCII trees inside it.
*/

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm const &src);
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
    virtual ~ShrubberyCreationForm();

    virtual void		execute(Bureaucrat const &executor) const;
    std::string const	&getTarget() const;
    
};
