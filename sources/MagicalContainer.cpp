#include "MagicalContainer.hpp"
using namespace ariel;

// ***************************************//
// MagicalContainer                       //
// ***************************************//

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int element)
{
    elements.emplace_back(element);
}

void MagicalContainer::removeElement(int element)
{
    for (auto it = elements.begin(); it != elements.end(); ++it)
    {
        if (*it == element)
        {
            elements.erase(it);
            break;
        }
    }
}

int MagicalContainer::size()
{
    return elements.size();
}

// ***************************************//
// AscendingIterator                      //
// ***************************************//

MagicalContainer::AscendingIterator::AscendingIterator() {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &other) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer &other) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return false;
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return false;
}

int MagicalContainer::AscendingIterator::operator*()
{
    return 0;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::operator++()
{
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return *this;
}

// ***************************************//
// SideCrossIterator                      //
// ***************************************//

MagicalContainer::SideCrossIterator::SideCrossIterator() {}

ariel::MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &other) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer &other) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return false;
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return false;
}

int MagicalContainer::SideCrossIterator::operator*()
{
    return 0;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::operator++()
{
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return *this;
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return *this;
}

// ***************************************//
// PrimeIterator                          //
// ***************************************//

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i * i <= num; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

MagicalContainer::PrimeIterator::PrimeIterator() {}

ariel::MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &other) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer &other) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return false;
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return false;
}

int MagicalContainer::PrimeIterator::operator*()
{
    return 0;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::operator++()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return *this;
}
