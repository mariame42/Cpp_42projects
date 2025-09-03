/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer_Lifecycle.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:24:55 by meid              #+#    #+#             */
/*   Updated: 2025/07/16 22:25:31 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "FileReplacer.hpp"

FileReplacer::FileReplacer(std::string fileName, std::string toFind, std::string  toReplace)
		: _fileName(fileName), _toFind(toFind), _toReplace(toReplace),  _outFile(fileName + ".replace") {}

FileReplacer::~FileReplacer() {}