/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 10:45:07 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/12 11:37:28 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

# include <string>
# include <iostream>


class Zombie
{

public:

	Zombie( std::string name );
	~Zombie( void );

	void	announce( void );

private:
	std::string name;

};

void	randomChump(std::string name);
Zombie 	*newZombie(std::string name);

#endif