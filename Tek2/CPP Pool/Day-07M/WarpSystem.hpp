/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD07M-alexandre.juan
** File description:
** WarpSystem
*/

#ifndef WARPSYSTEM_HPP_
#define WARPSYSTEM_HPP_

namespace WarpSystem {
    class QuantumReactor;
    class Core;
}

class WarpSystem::QuantumReactor {
    public:
        QuantumReactor();
        ~QuantumReactor();
        bool isStable(void);
        void setStability(bool stability);

    protected:
        bool _stability;
    private:
};

class WarpSystem::Core {
    public:
        Core(QuantumReactor *coreReactor);
        ~Core();
        QuantumReactor *checkReactor(void);

    protected:
        QuantumReactor *_coreReactor;
    private:
};

#endif /* !WARPSYSTEM_HPP_ */
