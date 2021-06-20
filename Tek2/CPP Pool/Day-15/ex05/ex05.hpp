/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD15-alexandre.juan
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

template<typename T>
class array {
    public:
        array() { this->_arr = new T; }
        array(unsigned int n) {
            this->_arr = new [n]T;
            this->_size = n + 1;
        }
        array(const array &oldArray);
        T &operator[](unsigned int index)
        {
            if (index >= index) {
                // TODO reallox
            } else {
                return this->_arr[index];
            }
        }

        int size(void) const { int count = 0; for(; _arr && _arr[count]; count++); return count; }
        void dump(void) const { for (int i = 0; _arr && _arr[i]; i++) std::cout << _arr[i] << std::endl; }
        T *_arr;
        int _size;
};

template<typename T>
std::ostream &operator<<(std::ostream &s, const T &arr)
{
    s << arr
    return s;
}

#endif /* !EX05_HPP_ */
