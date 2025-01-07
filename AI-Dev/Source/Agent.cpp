#include "Agent.h"

Agent::Agent() = default;

Agent::Agent(int x_, int y_)
{
    x = x_;
    y = y_;
}

void Agent::Update()
{
    x = 10;
}
