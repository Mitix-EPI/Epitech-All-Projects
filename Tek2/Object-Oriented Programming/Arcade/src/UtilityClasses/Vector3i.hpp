/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector3i
*/

#ifndef VECTOR3I_HPP_
#define VECTOR3I_HPP_

class Vector3i {
    public:

        //Constructor
        Vector3i();
        Vector3i(int x, int y, int z);

        //Destructor
        ~Vector3i();

        //Getters
        int getX() { return this->_x;};
        int getY() { return this->_y;};
        int getZ() { return this->_z;};

        //Setters
        void setX(int x);
        void setY(int y);
        void setZ(int z);
        void set(int x, int y, int z);

    protected:
        int _x = 0;
        int _y = 0;
        int _z = 0;
    private:
};

#endif /* !VECTOR3I_HPP_ */
