#include "pseudoInterrupt.h"

PseudoInterrupt::PseudoInterrupt(double tick_in_microseconds)
{
    // REF: http://www.cplusplus.com/reference/chrono/high_resolution_clock/now/
    tick_in_microseconds_ = tick_in_microseconds;
    start_of_tick_ = std::chrono::high_resolution_clock::now();
}

PseudoInterrupt::~PseudoInterrupt()
{
    //dtor
}

bool PseudoInterrupt::wait_tick_or_return_true()
{
    end_of_tick_ = std::chrono::high_resolution_clock::now();
    auto time_span_micros = std::chrono::duration_cast<std::chrono::microseconds>(end_of_tick_ - start_of_tick_).count();

    if ( time_span_micros > tick_in_microseconds_)
    {
        return (true);
    }
    else
    {
        std::this_thread::sleep_for(std::chrono::microseconds(int(tick_in_microseconds_)-time_span_micros));
        start_of_tick_ = end_of_tick_ + std::chrono::microseconds(int(tick_in_microseconds_));
        return (false);
    }
}
