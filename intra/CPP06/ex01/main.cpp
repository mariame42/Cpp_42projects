/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:25:35 by meid              #+#    #+#             */
/*   Updated: 2025/11/07 17:25:36 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"


int main(void)
{
    Data* data = new Data;
    data->id = 0;
    data->name = "serialized";

    uintptr_t raw = Serialization::serialize(data);
    Data* back = Serialization::deserialize(raw);

    std::cout << "original: " << data << "\n";
    std::cout << "decoded : " << back << "\n";
    std::cout << (back == data ? "OK: pointers equal" : "ERROR: pointers differ") << std::endl;

    delete data;
    return 0;
}