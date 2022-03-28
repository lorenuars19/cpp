/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:56:04 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/28 16:31:37 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	public:
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string phone_number;
		std::string darkest_secret;
		int			index;

// ----------------------------- Constructors ------------------------------ //
		Contact( void );	// Default Constructor
		Contact(std::string fname, std::string lname, std::string nick,
				std::string phone, std::string secret);

		Contact( const Contact& copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~Contact( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		Contact & operator=( const Contact& assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //


// --------------------------------- Methods ------------------------------- //
		std::string	truncate(std::string str, size_t maxlen ) const;
		std::string	get_oneline( void ) const;
		std::string	get_full( int index ) const;

private:

};

# define NO_DEBUG

# ifndef NO_DEBUG
#  define _AUTO(COLOR_CODE, TEXT) std::cout << "\e[" << COLOR_CODE << ";1m" \
	<< "< " << TEXT << " " << __PRETTY_FUNCTION__ << " > " \
	<< "\e[0m" << std::endl
# else
#  define _AUTO(x, y) ;
# endif

#endif
