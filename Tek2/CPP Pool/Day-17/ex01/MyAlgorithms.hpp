#ifndef _MY_ALGORITHMS_HPP__
# define _MY_ALGORITHMS_HPP__

#include <algorithm>
#include <iostream>
#include <iomanip>

template<typename T>
void vPrint(T const& container, void (*showFuncPtr)(int))
{
        std::cout << "Dump (" << std::setw(2) << container.size() << ')' << ' ';
        std::for_each(container.begin(), container.end(), showFuncPtr);
        std::cout << std::endl;
}

template<typename T>
size_t vHowMany(T const& container, int value)
{
        return std::count(container.begin(), container.end(), value);
}

template<typename T>
bool vIsSimilar(T const& container, int* values)
{
        return std::equal(container.begin(), container.end(), values);
}

template<typename T>
void vAssign(T itFrom, T itTo, int value)
{
        std::fill(itFrom, itTo, value);
}

template<typename T>
void vFindAndModify(T& container, int oldValue, int newValue)
{
          std::replace(container.begin(), container.end(), oldValue, newValue);
}

template<typename T>
typename T::iterator vFindAndKill(T& container, int value)
{
          return std::remove(container.begin(), container.end(), value);
}

template<typename T>
void vShift(T& container, int nbShift)
{
        std::rotate(container.begin(), container.begin() + nbShift, container.end());
}

template<typename T, typename U>
void vApply(T itFrom, T itTo, U funcPtr)
{
        std::for_each(itFrom, itTo, funcPtr);
}

template<typename T>
void vFlip(T& container)
{
        std::reverse(container.begin(), container.end());
}

template<typename T>
void vToAscOrder(T& container)
{
        std::sort(container.begin(), container.end());
}

template<typename T>
void vToSpecificOrder(T& container, bool (*cmpFuncPtr)(int, int))
{
        std::sort(container.begin(), container.end(), cmpFuncPtr);
}

template<typename T>
typename T::iterator vGiveMeTheFirst(T& container, int value)
{
        return std::find(container.begin(), container.end(), value);
}

template<typename T>
typename T::iterator vRemoveDuplicate(T& container)
{
        return std::unique(container.begin(), container.end());
}

template<typename T>
void vFusionOrderedLists(T const & container1, T const & container2, T& containerToFill)
{
        std::merge(container1.begin(), container1.end(), container2.begin(), container2.end(), containerToFill.begin());
}

#endif
