/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector2f
*/

#ifndef VECTOR2F_HPP_
#define VECTOR2F_HPP_

class Vector2f {
    public:

        //Constructor
        Vector2f();
        Vector2f(float x, float y);

        //Destructor
        ~Vector2f();

        //Getters
        float getX() { return this->_x;};
        float getY() { return this->_y;};

        //Setters
        void setX(float x);
        void setY(float y);
        void set(float x, float y);

    protected:
        float _x = 0;
        float _y = 0;
    private:
};

#endif /* !VECTOR2I_HPP_ */
