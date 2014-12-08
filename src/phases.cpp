#include "phases.h"
#include <iostream>

Phase::Phase(unsigned char t)
{
    type_ = TRAFFIC_JUNCTION;
    state_ = PHASE_RED;
    phase_change_ = PHASE_CHANGE_NONE;
    time_on_green_milliseconds_ = 0;
    time_since_green_milliseconds_ = 0;
    time_on_current_state_milliseconds_ = 0;
    type_ = t;
    // Load default mintime for this phase type
    //              mintime are stored at OUTPUT_PER_PHASE-1
    for (int n=0; n<PHASE_STEPS; n++)
    {
        min_times_[n] = phase_types_a[type_][n][OUTPUT_PER_PHASE-1];
    }
}

Phase::~Phase()
{
    //dtor
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

void Phase::intergreen_add(Phase* phase, unsigned char seconds)
{
    Intergreen intergreen(phase, seconds);
    intergreens_.push_back(intergreen);
}

void Phase::debug_set_time_since_green_milliseconds(unsigned long m)
{
    time_since_green_milliseconds_ = m;
}

void Phase::debug_cout_all_intergreen_remaining()
{
// for ( auto i = v.begin(); i != v.end(); i++ ) {
//    std::cout << *i << std::endl;
    for(vector<Intergreen>::iterator i = intergreens_.begin(); i != intergreens_.end(); i++ )
    {
        cout << int(i->remaining_seconds()) << endl;
    }
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
        return(seconds_ - phase_->time_since_green_seconds());
    }
    else
    {
        return( 0);
    }
}

