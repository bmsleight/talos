#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout << "TALOS - Traffic And Lights Open Source \n" << endl;
    cout << "Automatons were crafted out of metal and made animate in order to perform " << endl;
    cout << "various tasks. They were created by the divine smith, Hephaestus. " << endl;
    cout << " - http://en.wikipedia.org/wiki/List_of_Greek_mythological_creatures " << endl;

    size_t size = 10;
    vector<int> array;
    for(int i=0; i<size; ++i)
    {
        array.push_back(i*i);
        cout << array[i] << endl;
    }

    return 0;
}
/*
#include <vector>
//...
size_t size = 10;
std::vector<int> array(size)
*/
