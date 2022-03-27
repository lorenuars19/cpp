#!/bin/bash
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ccp_gen.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/27 22:29:12 by lorenuar          #+#    #+#              #
#    Updated: 2022/03/27 22:29:13 by lorenuar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# bash script to generate C++ canonical class files

SRC_DIR=./src
INC_DIR=./includes

CLASS_EXT=".cpp"
HEADER_EXT=".hpp"

function gen_class_header()
{
	header_filename=${INC_DIR}/${name}${HEADER_EXT}
	printf "\e[32;1m+++ Generating $name Header -- $header_filename\e[0m\n"
	mkdir -p $INC_DIR

	cat > $header_filename << EOF
#ifndef ${name^^}_HPP
# define ${name^^}_HPP

class ${name}
{
	public:
// ----------------------------- Constructors ------------------------------ //
		${name}( void );	// Default Constructor
		${name}( int var );	// Fields Constructor
		${name}( const ${name} &copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~${name}( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		${name} & operator=( const ${name} &assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		int		get_var( void ) const;
		void	set_var( int input );

// --------------------------------- Methods ------------------------------- //
		int		is_equal( ${name} comp );

private:
	int	_var;

};
#endif
EOF
}

function gen_class_file()
{
	class_filename=${SRC_DIR}/${name}${CLASS_EXT}
	printf "\e[32;1m+++ Generating $name Class -- $class_filename\e[0m\n"
	mkdir -p $SRC_DIR

	cat > $class_filename << EOF

EOF
}

if [[ $# -eq 0 ]]
then
	cat << EOF
Usage :
	$0 --	Run without argument
			for interactive version

	$0 [Name of Class]
EOF

	exit 0
else
	name=$1
fi

gen_class_header
gen_class_file
