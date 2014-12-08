#include <chrono>
#include <iostream>
#include <thread>
#include <vector>
#include "phases.h"
#include "pseudoInterrupt.h"

using namespace std;


vector<Phase> simple_setup()
{
    vector<Phase> phases;
    Phase phaseA("A", TRAFFIC_JUNCTION);
    Phase phaseB("B", TRAFFIC_JUNCTION);
    Phase phaseC("C", PED_JUNCTION);
    phaseA.intergreen_add(&phaseB, 5);
    phaseA.intergreen_add(&phaseC, 10);
    phaseB.intergreen_add(&phaseA, 5);
    phaseB.intergreen_add(&phaseC, 10);
    phaseC.intergreen_add(&phaseA, 5);
    phaseC.intergreen_add(&phaseB, 5);

    phaseA.debug_set_time_since_green_milliseconds(20000);
    phaseC.debug_set_time_since_green_milliseconds(10000);
//    cout << int(phaseB.) << endl;
    phaseA.debug_cout_all_intergreen_remaining();
    phaseB.debug_cout_all_intergreen_remaining();
    phaseC.debug_cout_all_intergreen_remaining();

    phases.push_back(phaseA);
    phases.push_back(phaseB);
    phases.push_back(phaseC);
    return phases;
}


int main()
{
    cout << "TALOS - Traffic And Lights Open Source \n" << endl;
    cout << "Automatons were crafted out of metal and made animate in order to perform " << endl;
    cout << "various tasks. They were created by the divine smith, Hephaestus. " << endl;
    cout << " - http://en.wikipedia.org/wiki/List_of_Greek_mythological_creatures " << endl;

    int abort = false; // Lots of ways to trigger.

    vector<Phase> phases = simple_setup();

    PseudoInterrupt tick(TICK_MICROSECONDS);
    while(!abort)
    {
        abort += tick.wait_tick_or_return_true();
    }

    return 0;
}
