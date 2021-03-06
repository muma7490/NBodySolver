//
// Created by marco on 05.12.17.
//

#ifndef NBODYSOLVER_BODY_H
#define NBODYSOLVER_BODY_H

#include "support/ibody.h"
using namespace std;

class EulerBody : public IBody
{
public:
    EulerBody(MVector initial_position, MVector initial_velocity, double mass);
    void computeNextStep(vector<EulerBody> bodies);
private:
    EulerBody() = default;

    MVector computeNextVelocity() override;
    MVector computeNextPosition() override;

};

#endif //NBODYSOLVER_BODY_H
