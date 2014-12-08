#ifndef PHASES_H
#define PHASES_H

#include <vector>
using namespace std;

/* Define some Globals use for a phase */

/* Phase Types */
/* Each phase type will go in the order .... */

#define PHASE_GREEN 0
#define PHASE_POST_GREEN 1
#define PHASE_BLACKOUT 1 // Same as POST_GREEN - but easier for reading
#define PHASE_PRE_RED 2
#define PHASE_RED 3
#define PHASE_POST_RED 4
#define PHASE_PRE_GREEN 5
#define PHASE_STEPS 6

//Maximum nunebr of phases can handle
// needed for maxing inter
#define MAX_NUMBER_PHASES 16

//#define OUTPUT_PER_PHASE 3
#define OUTPUT_PER_PHASE 4 // As going to store min time at end

/* Phase_Change */
#define PHASE_CHANGE_NONE 0
#define PHASE_CHANGE_TO_GREEN 1
#define PHASE_CHANGE_TO_RED 2

#define A_OFF__ 0
#define A_ON___ 1
#define A_FLASH 2
#define A_POLARITY 0

/* Phase types */
#define PHASE_TYPES 4
/* which of type ... */
#define TRAFFIC_PELICAN 0
#define PED_PELICAN 1
#define TRAFFIC_JUNCTION 2
#define PED_JUNCTION 3

static unsigned char phase_types_a[PHASE_TYPES][PHASE_STEPS][OUTPUT_PER_PHASE]=
{
  // Type of signal
  // State, State, State, Min time
  // e.g. When at green for Traffic Phase at Pelican
  // Red Aspect off, Amber off, Green On, Minimum 7 Seconds

  { // TRAFFIC_PELICAN
    // Red      AMBER   GREEN
    {A_OFF__, A_OFF__, A_ON___, 7}, // PHASE_GREEN
    {A_OFF__, A_OFF__, A_ON___, 0}, // PHASE_POST_GREEN
    {A_OFF__, A_ON___, A_OFF__, 3}, // PHASE_PRE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_RED
    {A_OFF__, A_FLASH, A_OFF__, 0}, // PHASE_POST_RED
    {A_OFF__, A_FLASH, A_OFF__, 0}  // PHASE_PRE_GREEN
  },
  { // PED_PELICAN
    //Red Fig    -      Green Fig
    {A_OFF__, A_OFF__, A_ON___, 5}, // PHASE_GREEN
    {A_OFF__, A_OFF__, A_FLASH, 0}, // PHASE_POST_GREEN
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_PRE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_POST_RED
    {A_ON___, A_OFF__, A_OFF__, 0}  // PHASE_PRE_GREEN
  },
  { // TRAFFIC_JUNCTION
    // Red      AMBER   GREEN
    {A_OFF__, A_OFF__, A_ON___, 7}, // PHASE_GREEN
    {A_OFF__, A_OFF__, A_ON___, 0}, // PHASE_POST_GREEN
    {A_OFF__, A_ON___, A_OFF__, 3}, // PHASE_PRE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_POST_RED
    {A_ON___, A_ON___, A_OFF__, 2}  // PHASE_PRE_GREEN
  },
  { // PED_JUNCTION
    //Red Fig    -      Green Fig
    {A_OFF__, A_OFF__, A_ON___, 5}, // PHASE_GREEN
    {A_OFF__, A_OFF__, A_OFF__, 5}, // PHASE_POST_GREEN
    {A_OFF__, A_OFF__, A_OFF__, 0}, // PHASE_PRE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_RED
    {A_ON___, A_OFF__, A_OFF__, 0}, // PHASE_POST_RED
    {A_ON___, A_OFF__, A_OFF__, 0}  // PHASE_PRE_GREEN
  }
};

// Get me with my forward declaration of a class
class Intergreen;

class Phase
{
    public:
        Phase(unsigned char t);
        virtual ~Phase();
        void min_time_set(unsigned char phase_step, unsigned char min_time);
        unsigned char time_since_green_seconds();
        void intergreen_add(Phase* phase, unsigned char seconds);
        void debug_set_time_since_green_milliseconds(unsigned long m);
        void debug_cout_all_intergreen_remaining();
    protected:
    private:
        /* Status of phase */
        unsigned char type_;
        unsigned char state_; // PHASE_GREEN 0, PHASE_RED 3 etc....
        unsigned char phase_change_; // PHASE_CHANGE_NONE 0, PHASE_CHANGE_TO_GREEN 1, PHASE_CHANGE_TO_GREEN_RED 2
        unsigned long time_on_green_milliseconds_;
        unsigned long time_since_green_milliseconds_;
        unsigned long time_on_current_state_milliseconds_;
        unsigned char min_times_[PHASE_STEPS];
        vector<Intergreen> intergreens_;
};

class Intergreen
{
    public:
        Intergreen(Phase* phase, unsigned char seconds);
        virtual ~Intergreen();
        unsigned char remaining_seconds();
    protected:
    private:
        Phase* phase_;
        unsigned char seconds_;
};


#endif // PHASES_H
