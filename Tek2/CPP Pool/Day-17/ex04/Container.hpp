/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD17-alexandre.juan
** File description:
** Container
*/

#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_

template<typename T>
void aff(T b)
{
    if (b == 7)
        std::cout << "Value: 7";
}

template<typename T>
void add(T b)
{
    b++;
}

template<typename T>
class contain {
    public:
        contain();
        ~contain();

        void push(T const &data);
        void aff(void) { aff() }
        void add(void);

    protected:
    private:
};

#endif /* !CONTAINER_HPP_ */
