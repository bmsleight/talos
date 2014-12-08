#include <iostream>
#include <vector>
#include "phases.h"

using namespace std;


void simple_test()
{
    vector<Phase> phases;
    Phase phaseA(TRAFFIC_JUNCTION);
    Phase phaseB(TRAFFIC_JUNCTION);
    phaseA.intergreen_add(&phaseB, 5);
    phaseB.intergreen_add(&phaseA, 5);
    phaseA.debug_set_time_since_green_milliseconds(5100);
//    cout << int(phaseB.) << endl;
    phaseA.debug_cout_all_intergreen_remaining();
    phaseB.debug_cout_all_intergreen_remaining();
    phases.push_back(phaseA);
    phases.push_back(phaseB);

}


int main()
{
    cout << "TALOS - Traffic And Lights Open Source \n" << endl;
    cout << "Automatons were crafted out of metal and made animate in order to perform " << endl;
    cout << "various tasks. They were created by the divine smith, Hephaestus. " << endl;
    cout << " - http://en.wikipedia.org/wiki/List_of_Greek_mythological_creatures " << endl;

    simple_test();
/*
    size_t size = 10;
    vector<int> array;
    for(int i=0; i<size; ++i)
    {
        array.push_back(i*i);
        cout << array[i] << endl;
    }
*/
    return 0;
}
