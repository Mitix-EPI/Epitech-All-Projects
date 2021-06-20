
#ifndef REF_PTR_HPP_
#define REF_PTR_HPP_

#include <cstddef>
#include "BaseComponent.hpp"
#include <iostream>

class RefPtr
{
    public:
        RefPtr(void);
        RefPtr(BaseComponent *rawPtr);
        RefPtr(RefPtr const &other);
        RefPtr &operator=(RefPtr const &other);
        RefPtr &operator=(BaseComponent *rawPtr);
        ~RefPtr();

        void clone(RefPtr const &other);

        BaseComponent *get() const { return this->_rawPtr; };

    private:
        BaseComponent *_rawPtr;
};

#endif // REF_PTR_HPP_
