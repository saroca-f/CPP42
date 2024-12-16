/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:45:07 by saroca-f          #+#    #+#             */
/*   Updated: 2024/12/16 09:13:38 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <sstream>
# include <iostream>
# include <cctype>


class Zombie
{

public:

	Zombie( std::string name );
	Zombie( void );
	~Zombie( void );

	void	announce( void );
	void	setName(std::string name);

private:
	std::string _name;

};

Zombie *ZombieHorde( int N, std::string name );

#endif