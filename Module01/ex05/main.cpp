/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:07:23 by saroca-f          #+#    #+#             */
/*   Updated: 2024/08/15 15:59:15 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "harl.hpp"

int main(void)
{
    harl manolo;

	manolo.complain("DEBUG");
	manolo.complain("INFO");
	manolo.complain("WARNING");
	manolo.complain("ERROR");
    return (0);
}