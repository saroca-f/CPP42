/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:47:04 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/15 13:23:58 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H

# define DEFAULT "\001\033[0;39m\002"
# define RED "\001\033[1;91m\002"
# define YELLOW "\001\033[1;93m\002"
# define GRAY "\001\033[1;90m\002"

# include <iostream>

class harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );

	public:
		void	complain( std::string level );
};

#endif