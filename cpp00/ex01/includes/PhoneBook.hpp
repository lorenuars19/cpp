/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorenuar <lorenuar@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:55:58 by lorenuar          #+#    #+#             */
/*   Updated: 2022/03/28 13:49:03 by lorenuar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>

# define N_CONTACTS 8

class PhoneBook
{
	public:
		Contact	contacts[N_CONTACTS];
		int		cont_index;
// ----------------------------- Constructors ------------------------------ //
		PhoneBook( void );	// Default Constructor
		// PhoneBook( int var );	// Fields Constructor
		PhoneBook( const PhoneBook &copy );	// Copy Constructor

// ------------------------------ Destructor ------------------------------- //
		~PhoneBook( void );	// Destructor

// ------------------------------- Operators ------------------------------- //
		PhoneBook & operator=( const PhoneBook &assign );
		// Copy Assignement Operator

// --------------------------- Getters && Setters -------------------------- //

// --------------------------------- Methods ------------------------------- //
		int			add_contact( void );
		void		show_contacts( void ) const;
		int			search_contact( void ) const;

private:


};

#endif
