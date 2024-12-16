/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saroca-f <saroca-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:51:27 by saroca-f          #+#    #+#             */
/*   Updated: 2024/11/21 18:48:04 by saroca-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//Convert a pointer to a Data object into an unsigned integer (uintptr_t)
uintptr_t Serializer::serialize(Data *ptr)
{
    // reinterpret_cast is used to convert the pointer to a value of type uintptr_t
    return (reinterpret_cast<uintptr_t>(ptr));
}

// Converts an unsigned integer (uintptr_t) into a pointer to a Data object
Data *Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}