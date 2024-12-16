/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:27:38 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 11:14:42 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <string>
# include <iostream>

class	Weapon
{
	public:

		typedef	Weapon	t;

		Weapon( std::string weapon );
		~Weapon( void );

		const std::string&			getType( void );
		void				setType( std::string newType );

	private:
		std::string	_type;
};

#endif