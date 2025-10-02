/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meid <meid@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 22:09:56 by meid              #+#    #+#             */
/*   Updated: 2025/09/10 22:12:00 by meid             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default")
{
    for (int i = 0; i < _maxSlots; i++)
        _inventory[i] = NULL;
    std::cout << "Character default constructor called" << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{
    for (int i = 0; i < _maxSlots; i++)
        _inventory[i] = NULL;
    std::cout << "Character constructor called for " << _name << std::endl;
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (other._inventory[i])
            _inventory[i] = other._inventory[i]->clone();
        else
            _inventory[i] = NULL;
    }
    std::cout << "Character copy constructor called for " << _name << std::endl;
}

Character& Character::operator=(const Character& other)
{
    if (this != &other)
    {
        _name = other._name;
        // Clean up existing inventory
        for (int i = 0; i < _maxSlots; i++)
        {
            if (_inventory[i])
            {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        // Copy inventory
        for (int i = 0; i < _maxSlots; i++)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
        }
    }
    std::cout << "Character copy assignment operator called for " << _name << std::endl;
    return (*this);
}

Character::~Character()
{
    for (int i = 0; i < _maxSlots; i++)
    {
        if (_inventory[i])
        {
            delete _inventory[i];
            _inventory[i] = NULL;
        }
    }
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
        if (!_inventory[i])
        {
            _inventory[i] = m;
            std::cout << _name << " equips " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    std::cout << _name << " cannot equip " << m->getType() << " - inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= _maxSlots)
    {
        std::cout << _name << " cannot unequip slot " << idx << " - invalid index!" << std::endl;
        return;
    }
    
    if (_inventory[idx])
    {
        std::cout << _name << " unequips " << _inventory[idx]->getType() << " from slot " << idx << std::endl;
        _inventory[idx] = NULL; // Don't delete - just set to NULL
    }
    else
    {
        std::cout << _name << " cannot unequip slot " << idx << " - slot is empty!" << std::endl;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= _maxSlots)
    {
        std::cout << _name << " cannot use slot " << idx << " - invalid index!" << std::endl;
        return;
    }
    
    if (_inventory[idx])
    {
        std::cout << _name << " uses " << _inventory[idx]->getType() << " on " << target.getName() << std::endl;
        _inventory[idx]->use(target);
    }
    else
    {
        std::cout << _name << " cannot use slot " << idx << " - slot is empty!" << std::endl;
    }
}