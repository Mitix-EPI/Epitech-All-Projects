/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** Logical
*/

#ifndef LOGICAL_HPP_
#define LOGICAL_HPP_

template <typename T>
class Logical {
    public:
        Logical();
        ~Logical();

        T NOT(T val);
        T AND(T val1, T val2);
        T NAND(T val1, T val2);
        T OR(T val1, T val2);
        T NOR(T val1, T val2);
        T XOR(T val1, T val2);
        T NXOR(T val1, T val2);

    protected:
    private:
};

template <typename T>
Logical<T>::Logical()
{
}

template <typename T>
T Logical<T>::NOT(T val)
{
    return !val;
}

template <typename T>
T Logical<T>::AND(T val1, T val2)
{
    return val1 && val2;
}

template <typename T>
T Logical<T>::OR(T val1, T val2)
{
    return val1 || val2;
}

template <typename T>
T Logical<T>::NOR(T val1, T val2)
{
    return !(val1 || val2);
}

template <typename T>
T Logical<T>::NAND(T val1, T val2)
{
    return !(val1 && val2);
}

template <typename T>
T Logical<T>::XOR(T val1, T val2)
{
    return val1 ^ val2;
}

template <typename T>
T Logical<T>::NXOR(T val1, T val2)
{
    return !(val1 ^ val2);
}

template <typename T>
Logical<T>::~Logical()
{
}


#endif /* !LOGICAL_HPP_ */
