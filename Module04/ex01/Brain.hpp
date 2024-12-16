/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 08:39:11 by saroca-f          #+#    #+#             */
/*   Updated: 2024/10/25 14:44:28 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

class Brain
{
    private:
        std::string _ideas[100];

    public:
        Brain();
        Brain(Brain const &copy);
        ~Brain(void);
        Brain const &operator=(Brain const &copy);
        std::string const getIdea(int const &index) const;
        void    setIdea(std::string const &idea, int const index);
};