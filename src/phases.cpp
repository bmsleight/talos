#include "phases.h"
#include <iostream>

Phase::Phase()
{
    type_ = TRAFFIC_JUNCTION;
    state_ = PHASE_RED;
    phase_change_ = PHASE_CHANGE_NONE;
    time_on_green_milliseconds_ = 0;
    time_since_green_milliseconds_ = 0;
    time_on_current_state_milliseconds_ = 0;
    for (int n=0; n<MAX_NUMBER_PHASES; n++)
    {
        intergreen_from_[n] = 0;
    }

}

Phase::~Phase()
{
    //dtor
}

void Phase::type_set(unsigned char t)
{
    type_ = t;
    for (int n=0; n<PHASE_STEPS; n++)
    {
        min_times_[n] = phase_types_a[type_][PHASE_STEPS-1][OUTPUT_PER_PHASE-1];
        std::cout << min_times_ << std::endl;
    }
}

void Phase::min_time_set(unsigned char phase_step, unsigned char min_time)
{
    min_times_[phase_step] = min_time;
}

unsigned char Phase::time_since_green_seconds()
{
    // Will the convert correctly ?
    return (time_since_green_milliseconds_/1000);
}


Intergreen::Intergreen(Phase* phase, unsigned char seconds)
{
    phase_ = phase;
    seconds_ = seconds;
}

Intergreen::~Intergreen()
{
    //dtor
}

unsigned char Intergreen::remaining_seconds()
{
    if (seconds_ > phase_->time_since_green_seconds() )
    {
        return(0);
    }
    else
    {
        return( phase_->time_since_green_seconds() );
    }
}

