#include "ETime.h"

void Time::Tick()
{
	clock::duration duration = clock::now() - m_startTime;
	m_time = duration.count() / (float)clock::duration::period::den;

	duration = clock::now() - m_frameTime;
	m_deltaTime = duration.count() / (float)clock::duration::period::den;

	m_frameTime = clock::now();
}
