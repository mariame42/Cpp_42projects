/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:09:56 by meid              #+#    #+#             */
/*   Updated: 2025/10/06 18:34:48 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "../main.hpp"


Character::Character() : _name("Default")
{
    for (int i = 0; i < _maxSlots; i++)
        _backpack_slot[i] = NULL;
    if (OCCF)
        std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < _maxSlots; i++)
        _backpack_slot[i] = NULL;
    if (OCCF)
        std::cout << "Character constructor called for " << _name << std::endl;
}

Character::Character(const Character& other) : ICharacter(other), _name(other._name)
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (other._backpack_slot[i])
            _backpack_slot[i] = other._backpack_slot[i]->clone();
        else
            _backpack_slot[i] = NULL;
    }
    if (OCCF)
        std::cout << "Character copy constructor called for " << _name << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        // Clean up existing backpack_slot
        for (int i = 0; i < _maxSlots; i++)
        {
            if (_backpack_slot[i])
            {
                delete _backpack_slot[i];
                _backpack_slot[i] = NULL;
            }
        }
        // Copy backpack_slot
        for (int i = 0; i < _maxSlots; i++)
        {
            if (other._backpack_slot[i])
                _backpack_slot[i] = other._backpack_slot[i]->clone();
            else
                _backpack_slot[i] = NULL;
        }
    }
    if (OCCF)
        std::cout << "Character copy assignment operator called for " << _name << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (_backpack_slot[i])
        {
            delete _backpack_slot[i];
            _backpack_slot[i] = NULL;
        }
    }
    if (OCCF)
        std::cout << "Character destructor called for " << _name << std::endl;
}

std::string const & Character::getName() const
{
    return (_name);
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
    
    for (int i = 0; i < _maxSlots; i++)
    {
        if (!_backpack_slot[i])
        {
            _backpack_slot[i] = m;
            if (FUNCTION_CALL)
                std::cout << _name << " equips " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    if (FUNCTION_CALL)
        std::cout << _name << " cannot equip " << m->getType() << " - backpack_slot is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _maxSlots)
    {
        if (FUNCTION_CALL)
            std::cout << _name << " cannot unequip slot " << idx << " - invalid index!" << std::endl;
        return;
    }
    
    if (_backpack_slot[idx])
    {
        if (FUNCTION_CALL)
            std::cout << _name << " unequips " << _backpack_slot[idx]->getType() << " from slot " << idx << std::endl;
        _backpack_slot[idx] = NULL;
    }
    else
    {
        if (FUNCTION_CALL)
            std::cout << _name << " cannot unequip slot " << idx << " - slot is empty!" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= _maxSlots)
    {
        if (FUNCTION_CALL)
            std::cout << _name << " cannot use slot " << idx << " - invalid index!" << std::endl;
        return;
    }
    
    if (_backpack_slot[idx])
    {
        if (FUNCTION_CALL)
            std::cout << _name << " uses " << _backpack_slot[idx]->getType() << " on " << target.getName() << std::endl;
        _backpack_slot[idx]->use(target);
    }
    else
    {
        if (FUNCTION_CALL)
            std::cout << _name << " cannot use slot " << idx << " - slot is empty!" << std::endl;
    }
}