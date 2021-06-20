
#include <iostream>
#include "Errors.hpp"
#include "Oxygenator.hpp"

Oxygenator::Oxygenator()
    : _quantity(0)
{
}

void
Oxygenator::generateOxygen()
{
    _quantity += 10;
}

void
Oxygenator::useOxygen(int quantity)
{
    if (_quantity - quantity == 10)
        throw MissionCriticalError("Not enough oxygen to continue the mission.", "Oxygenator");
    if (_quantity - quantity < 10)
        throw LifeCriticalError("Not enough oxygen to live.", "Oxygenator");
    _quantity -= quantity;
}
