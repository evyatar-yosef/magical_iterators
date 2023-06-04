#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace ariel;

TEST_CASE("Test MagicalContainer")
{
    MagicalContainer container;

    SUBCASE("Test addElement and size")
    {
        container.addElement(1);
        CHECK(container.size() == 1);

        container.addElement(2);
        container.addElement(3);
        CHECK(container.size() == 3);
    }

    SUBCASE("Test removeElement and size")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        container.removeElement(2);
        CHECK(container.size() == 2);

        container.removeElement(1);
        container.removeElement(3);
        CHECK(container.size() == 0);
    }
    SUBCASE("Test size after removing non-existent element")
    {
        container.addElement(1);
        CHECK(container.size() == 1);

        container.removeElement(2); // Trying to remove a non-existent element
        CHECK(container.size() == 1); // Size should remain unchanged
    }

    SUBCASE("Test addElement and removeElement with duplicates")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(1); // Adding duplicate element

        CHECK(container.size() == 3);

        container.removeElement(1); // Removing one occurrence of duplicate element
        CHECK(container.size() == 2);
    }
}

TEST_CASE("Test AscendingIterator")
{
    MagicalContainer container;

    SUBCASE("Test iterator on empty container")
    {
        MagicalContainer::AscendingIterator it;

        CHECK(it == MagicalContainer::AscendingIterator());
        CHECK_FALSE(it != MagicalContainer::AscendingIterator());
        CHECK(*it == 0);
    }

    SUBCASE("Test iterator on non-empty container")
    {
        container.addElement(3);
        container.addElement(1);
        container.addElement(2);

        MagicalContainer::AscendingIterator it;

        CHECK_FALSE(it == MagicalContainer::AscendingIterator());
        CHECK(it != MagicalContainer::AscendingIterator());
        CHECK(*it == 1);

        ++it;
        CHECK_FALSE(it == MagicalContainer::AscendingIterator());
        CHECK(it != MagicalContainer::AscendingIterator());
        CHECK(*it == 2);

        ++it;
        CHECK_FALSE(it == MagicalContainer::AscendingIterator());
        CHECK(it != MagicalContainer::AscendingIterator());
        CHECK(*it == 3);

        ++it;
        CHECK(it == MagicalContainer::AscendingIterator());
        CHECK_FALSE(it != MagicalContainer::AscendingIterator());
        CHECK(*it == 0);
    }
}

TEST_CASE("Test SideCrossIterator")
{
    MagicalContainer container;

    SUBCASE("Test iterator on empty container")
    {
        MagicalContainer::SideCrossIterator it;

        CHECK(it == MagicalContainer::SideCrossIterator());
        CHECK_FALSE(it != MagicalContainer::SideCrossIterator());
        CHECK(*it == 0);
    }

    SUBCASE("Test iterator on non-empty container")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        MagicalContainer::SideCrossIterator it;

        CHECK_FALSE(it == MagicalContainer::SideCrossIterator());
        CHECK(it != MagicalContainer::SideCrossIterator());
        CHECK(*it == 1);

        ++it;
        CHECK_FALSE(it == MagicalContainer::SideCrossIterator());
        CHECK(it != MagicalContainer::SideCrossIterator());
        CHECK(*it == 3);

        ++it;
        CHECK_FALSE(it == MagicalContainer::SideCrossIterator());
        CHECK(it != MagicalContainer::SideCrossIterator());
        CHECK(*it == 2);

        ++it;
        CHECK(it == MagicalContainer::SideCrossIterator());
        CHECK_FALSE(it != MagicalContainer::SideCrossIterator());
        CHECK(*it == 0);
    }
}



TEST_CASE("Test PrimeIterator")
{
    MagicalContainer container;

    SUBCASE("Test iterator on empty container")
    {
        MagicalContainer::PrimeIterator it;

        CHECK(it == MagicalContainer::PrimeIterator());
        CHECK_FALSE(it != MagicalContainer::PrimeIterator());
        CHECK(*it == 0);
    }

    SUBCASE("Test iterator on non-empty container")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);
        container.addElement(4);
        container.addElement(5);

        MagicalContainer::PrimeIterator it;

        CHECK_FALSE(it == MagicalContainer::PrimeIterator());
        CHECK(it != MagicalContainer::PrimeIterator());
        CHECK(*it == 2);

        ++it;
        CHECK_FALSE(it == MagicalContainer::PrimeIterator());
        CHECK(it != MagicalContainer::PrimeIterator());
        CHECK(*it == 3);

        ++it;
        CHECK_FALSE(it == MagicalContainer::PrimeIterator());
        CHECK(it != MagicalContainer::PrimeIterator());
        CHECK(*it == 5);

        ++it;
        CHECK(it == MagicalContainer::PrimeIterator());
        CHECK_FALSE(it != MagicalContainer::PrimeIterator());
        CHECK(*it == 0);
    }
    
}
TEST_CASE("Test size()")
{
    MagicalContainer container;

    SUBCASE("Test size of an empty container")
    {
        CHECK(container.size() == 0);
    }

    SUBCASE("Test size after adding elements")
    {
        container.addElement(1);
        CHECK(container.size() == 1);

        container.addElement(2);
        container.addElement(3);
        CHECK(container.size() == 3);
    }

    SUBCASE("Test size after removing elements")
    {
        container.addElement(1);
        container.addElement(2);
        container.addElement(3);

        container.removeElement(2);
        CHECK(container.size() == 2);

        container.removeElement(1);
        container.removeElement(3);
        CHECK(container.size() == 0);
    }
}
TEST_CASE("Test AscendingIterator operators")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::AscendingIterator it1;
    MagicalContainer::AscendingIterator it2;
    MagicalContainer::AscendingIterator it3(container);

    SUBCASE("Test equality operator")
    {
        CHECK(it1 == it2);
        CHECK_FALSE(it1 == it3);
        CHECK_FALSE(it2 == it3);
    }

    SUBCASE("Test inequality operator")
    {
        CHECK_FALSE(it1 != it2);
        CHECK(it1 != it3);
        CHECK(it2 != it3);
    }

    SUBCASE("Test less than operator")
    {
        CHECK_FALSE(it1 < it2);
        CHECK(it1 < it3);
        CHECK_FALSE(it3 < it1);
    }

    SUBCASE("Test greater than operator")
    {
        CHECK_FALSE(it1 > it2);
        CHECK_FALSE(it1 > it3);
        CHECK(it3 > it1);
    }

    SUBCASE("Test dereference operator")
    {
        CHECK(*it1 == 1);
        CHECK(*it3 == 1);
    }

    SUBCASE("Test pre-increment operator")
    {
        ++it1;
        CHECK(*it1 == 2);

        ++it3;
        CHECK(*it3 == 2);
    }

   
}

TEST_CASE("Test SideCrossIterator operators")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::SideCrossIterator it1;
    MagicalContainer::SideCrossIterator it2;
    MagicalContainer::SideCrossIterator it3(container);

    SUBCASE("Test equality operator")
    {
        CHECK(it1 == it2);
        CHECK_FALSE(it1 == it3);
        CHECK_FALSE(it2 == it3);
    }

    SUBCASE("Test inequality operator")
    {
        CHECK_FALSE(it1 != it2);
        CHECK(it1 != it3);
        CHECK(it2 != it3);
    }

    SUBCASE("Test less than operator")
    {
        CHECK_FALSE(it1 < it2);
        CHECK(it1 < it3);
        CHECK_FALSE(it3 < it1);
    }

    SUBCASE("Test greater than operator")
    {
        CHECK_FALSE(it1 > it2);
        CHECK_FALSE(it1 > it3);
        CHECK(it3 > it1);
    }

    SUBCASE("Test dereference operator")
    {
        CHECK(*it1 == 1);
        CHECK(*it3 == 1);
    }

    SUBCASE("Test pre-increment operator")
    {
        ++it1;
        CHECK(*it1 == 2);

        ++it3;
        CHECK(*it3 == 2);
    }

  
}

TEST_CASE("Test PrimeIterator operators")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator it1;
    MagicalContainer::PrimeIterator it2;
    MagicalContainer::PrimeIterator it3(container);

    SUBCASE("Test equality operator")
    {
        CHECK(it1 == it2);
        CHECK_FALSE(it1 == it3);
        CHECK_FALSE(it2 == it3);
    }

    SUBCASE("Test inequality operator")
    {
        CHECK_FALSE(it1 != it2);
        CHECK(it1 != it3);
        CHECK(it2 != it3);
    }

    SUBCASE("Test less than operator")
    {
        CHECK_FALSE(it1 < it2);
        CHECK(it1 < it3);
        CHECK_FALSE(it3 < it1);
    }

    SUBCASE("Test greater than operator")
    {
        CHECK_FALSE(it1 > it2);
        CHECK_FALSE(it1 > it3);
        CHECK(it3 > it1);
    }

    SUBCASE("Test dereference operator")
    {
        CHECK(*it1 == 2);
        CHECK(*it3 == 2);
    }

    SUBCASE("Test pre-increment operator")
    {
        ++it1;
        CHECK(*it1 == 3);

        ++it3;
        CHECK(*it3 == 3);
    }

   
}

TEST_CASE("Test AscendingIterator begin() and end() methods")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::AscendingIterator it;

    CHECK(*it.begin() == 1);
    CHECK(*it.end() == 0);
}

TEST_CASE("Test SideCrossIterator begin() and end() methods")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);

    MagicalContainer::SideCrossIterator it;

    CHECK(*it.begin() == 1);
    CHECK(*it.end() == 0);
}

TEST_CASE("Test PrimeIterator begin() and end() methods")
{
    MagicalContainer container;
    container.addElement(1);
    container.addElement(2);
    container.addElement(3);
    container.addElement(4);
    container.addElement(5);

    MagicalContainer::PrimeIterator it;

    CHECK(*it.begin() == 2);
    CHECK(*it.end() == 0);
}
