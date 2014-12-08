#ifndef PSEUDOINTERRUPT_H
#define PSEUDOINTERRUPT_H

#include <thread>
#include <chrono>


class PseudoInterrupt
{
    public:
        PseudoInterrupt(double tick_in_microseconds);
        virtual ~PseudoInterrupt();
        bool wait_tick_or_return_true();
    protected:
    private:
        double tick_in_microseconds_;
        std::chrono::high_resolution_clock::time_point start_of_tick_;
        std::chrono::high_resolution_clock::time_point end_of_tick_;
};

#endif // PSEUDOINTERRUPT_H
