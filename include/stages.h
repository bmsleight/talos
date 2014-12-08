#ifndef STAGES_H
#define STAGES_H

#include "phases.h"


class Stage
{
    public:
        Stage();
        virtual ~Stage();
        void add_phase(Phase* phase);
    protected:
    private:
        vector<Phase*> phases_; //Vector of point
};

#endif // STAGES_H
