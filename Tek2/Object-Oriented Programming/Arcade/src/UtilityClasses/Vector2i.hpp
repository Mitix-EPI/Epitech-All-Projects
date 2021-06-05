/*
** EPITECH PROJECT, 2021
** B-OOP-400-MPL-4-1-arcade-richard.habimana
** File description:
** Vector2i
*/

#ifndef VECTOR2I_HPP_
#define VECTOR2I_HPP_

class Vector2i {
    public:

        //Constructor
        Vector2i();
        Vector2i(int x, int y);

        //Destructor
        ~Vector2i();

        //Getters
        int getX() { return this->_x;};
        int getY() { return this->_y;};

        //Setters
        void setX(int x);
        void setY(int y);
        void addX(int x);
        void addY(int y);
        void set(int x, int y);
        void set(Vector2i vec);
        bool operator==(Vector2i vec);
        bool operator!=(Vector2i vec);

    protected:
        int _x = 0;
        int _y = 0;
    private:
};

#endif /* !VECTOR2I_HPP_ */
