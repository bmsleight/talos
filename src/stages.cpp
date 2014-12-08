#include "stages.h"

Stage::Stage()
{
    //ctor
}

Stage::~Stage()
{
    //dtor
}

void Stage::add_phase(Phase* phase)
{
    phases_.push_back(phase);
}
