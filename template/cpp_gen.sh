#!/bin/bash
# bash script to generate C++ canonical class files

SRC_DIR=./src
INC_DIR=./includes

CLASS_EXT=".cpp"
HEADER_EXT=".hpp"

function check_overwrite {
	if [[ -f $1 ]]; then
		printf "\033[31;1mFile $1 already exists\nOverwrite ? [y/N]\033[0m\n"
		read ans
		if [ "$ans" == "n" ] || [ "$ans" == "N" ] || [ -z "$ans" ]; then
			return 1
		fi
	fi
	return 0
}

function gen_class_header {
	CLASS_NAME=$1
	HEADER_FILENAME="${INC_DIR}/${CLASS_NAME}${HEADER_EXT}"

	check_overwrite $HEADER_FILENAME
	if [[ $? -eq 1 ]]; then
		return 1
	fi

	printf "\e[32;1m+++ Generating ${CLASS_NAME} Header -- $HEADER_FILENAME\e[0m\n"
	mkdir -p $INC_DIR
	UP_CLASS_NAME=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')

	cat >$HEADER_FILENAME <<EOF
#ifndef ${UP_CLASS_NAME}_HPP
# define ${UP_CLASS_NAME}_HPP

# include <iostream>

class ${CLASS_NAME}
{
	public:

		${ATTS_PUBLIC}
// ----------------------------- Constructors ------------------------------ //
		${CLASS_NAME}( );	// Default Constructor
		${CLASS_NAME}( ${ATTS_FIELD_CONST} );	// Fields Constructor
		${CLASS_NAME}( const ${CLASS_NAME}& c );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~${CLASS_NAME}( );	// Destructor

// ------------------------------- Operators ------------------------------- //
		${CLASS_NAME} & operator=( const t& a );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //
		${ATTS_GETTER_SETTER}

// --------------------------------- Methods ------------------------------- //
		int		is_equal( const ${CLASS_NAME} comp );

private:
	int	var;
	${ATTS_PUBLIC}

};

# ifndef NO_DEBUG

#  ifndef _ARG
#   define _ARG(arg) #arg << "(" << arg << ") "
#  endif /* _ARG */

#  define _${UP_CLASS_NAME}_ARGS _ARG(var)
#  define _${UP_CLASS_NAME}_AUTO(COLOR_CODE, TEXT) \\
	std::cout << "{ \e[" << COLOR_CODE << ";1m"                 \\
			  << TEXT << " " << __PRETTY_FUNCTION__ << "\e[0m " \\
			  << "[\033[34;47m" << this                         \\
			  << "\033[0m]\033[0m: " << _${UP_CLASS_NAME}_ARGS  \\
			  << "}" << std::endl;
# else

#  define _${UP_CLASS_NAME}_AUTO(x, y) ;
#  define _${UP_CLASS_NAME}_ARGS ""
#  define _ARG ""

# endif /* NO_DEBUG */

#endif /* ${UP_CLASS_NAME}_HPP */
EOF
}

function gen_class_file {
	CLASS_NAME=$1
	class_filename=${SRC_DIR}/${CLASS_NAME}${CLASS_EXT}

	check_overwrite $class_filename
	if [[ $? -eq 1 ]]; then
		return 1
	fi

	printf "\e[32;1m+++ Generating $CLASS_NAME Class -- $class_filename\e[0m\n"
	mkdir -p $SRC_DIR
	UP_CLASS_NAME=$(echo "${CLASS_NAME}" | tr '[:lower:]' '[:upper:]')

	cat >$class_filename <<EOF
#include "${CLASS_NAME}.hpp"

// ----------------------------- Constructors ------------------------------ //
${CLASS_NAME}::${CLASS_NAME}( )
{
	var = 0;
	_${UP_CLASS_NAME}_AUTO(32, "Default Constructor");
}

${CLASS_NAME}::${CLASS_NAME}( const ${CLASS_NAME}& c )
{
	var = c.get_var();
	_${UP_CLASS_NAME}_AUTO(32, "Copy Constructor");
}

${CLASS_NAME}::${CLASS_NAME}( ${FIELD_CONSTRUCTOR_PARAMS} ) : var(input)
{
	_${UP_CLASS_NAME}_AUTO(32, "Fields Constructor");
}

// ------------------------------ Destructor ------------------------------- //
${CLASS_NAME}::~${CLASS_NAME}( )
{
	_${UP_CLASS_NAME}_AUTO(31, "Destructor called");
}
// ------------------------------- Operators ------------------------------- //

${CLASS_NAME} & ${CLASS_NAME}::operator=( const ${CLASS_NAME}& c )
{
	var = c.get_var();
	return *this;
}

// --------------------------- Getters && Setters -------------------------- //
int	${CLASS_NAME}::get_var( ) const
{
	_${UP_CLASS_NAME}_AUTO(33, "Getter");
	return var;
}

void	${CLASS_NAME}::set_var( int input )
{
	_${UP_CLASS_NAME}_AUTO(34, "Setter");
#ifndef NO_DEBUG
	std::cout << "\033[1D";
#endif
	std::cout <<" old(" << var << ") new(" << input << ") "<< std::endl;
	var = input;
}

${ATTS_GETTER_SETTER}

// --------------------------------- Methods ------------------------------- //

EOF
}

printf "\e[33;1m--- Class files Boiler Plate Generator ---\e[0m\n\n"
ARG=$1
shift

declare -a ATTS_TYP
declare -a ATTS_NAM
declare -a PR_ATTS_TYP
declare -a PR_ATTS_NAM
declare -a ATTRIB
declare -a ATTS

while [[ -z "$ARG" ]]; do
	read -p "Enter class name : " ARG
done
ARG=$(tr '[:lower:]' '[:upper:]' <<<${ARG:0:1})${ARG:1}

printf "\e[33;1m--- Attributes Definitions : \e[0m\n"
ATT_CNT=0
while [[ -z "$ANS" ]]; do
	IFS=' '
	ATTRIB=()
	ATT_TYP=
	ATT_NAM=
	printf "Enter Attribute [${ATT_CNT}] :\n"
	printf " Common types : (b)ool (c)har (i)nt (ui)nt (l)ong (ul)ong (s)tring (f)loat (d)ouble \n"
	while [[ -z "$ATT_TYP" ]]; do
		read -p " Type : " ATT_TYP
	done

	if [[ "$ATT_TYP" == 'b' ]]; then
		ATT_TYP='bool'
	fi
	if [[ "$ATT_TYP" == 'c' ]]; then
		ATT_TYP='char'
	fi
	if [[ "$ATT_TYP" == 'i' ]]; then
		ATT_TYP='int'
	fi
	if [[ "$ATT_TYP" == 'ui' ]]; then
		ATT_TYP='unsigned int'
	fi
	if [[ "$ATT_TYP" == 'l' ]]; then
		ATT_TYP='long'
	fi
	if [[ "$ATT_TYP" == 'ul' ]]; then
		ATT_TYP='unsigned long'
	fi
	if [[ "$ATT_TYP" == 's' ]]; then
		ATT_TYP='std::string'
	fi
	if [[ "$ATT_TYP" == 'f' ]]; then
		ATT_TYP='float'
	fi
	if [[ "$ATT_TYP" == 'd' ]]; then
		ATT_TYP='double'
	fi

	ATTRIB+=("${ATT_TYP}")

	while [[ -z "${ATT_NAM}" ]]; do
		read -p " Name : " ATT_NAM
	done
	ATTRIB+=("${ATT_NAM}")

	read -p " Type 'p' to make public or press enter for private attribute : " PRIVATE
	if [[ -z "${PRIVATE}" ]]; then
		ATTRIB+=("PRIVATE")
	else
		ATTRIB+=("PUBLIC")
	fi

	printf "\nATTRIB :\n [ Type '${ATTRIB[0]}' ] [ Name '${ATTRIB[1]}' ] [ Public/Private : '${ATTRIB[2]}' ] [ FULL : '${ATTRIB[*]}' ]\n\n"

	ATTS+=("${ATTRIB[@]}")
	read -p "Type 'end' or press enter to add another attribute : " ANS
	ATT_CNT=$((ATT_CNT + 1))
done

echo "ATTS '${ATTS[@]}' ATT_CNT ${ATT_CNT} >> $((${ATT_CNT} * 3))"

i=0
ATT_CNT_RAW=$((${ATT_CNT} * 3))
while [[ i -lt ${ATT_CNT_RAW} ]]; do
	echo i $i
	ATTS_FIELD_CONST+="${ATTS[$((i + 0))]} ${ATTS[$((i + 1))]}"
	if [[ i -lt $((${ATT_CNT_RAW} - 3)) ]]; then
		ATTS_FIELD_CONST+=", "
	fi
	i=$((i + 3))
done

printf "\nATTS_FIELD_CONST '${ATTS_FIELD_CONST}'\n"

exit 0

gen_class_header $ARG
gen_class_file $ARG
