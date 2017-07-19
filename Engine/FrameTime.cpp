#include "FrameTime.h"

using namespace std::chrono;

FrameTime::FrameTime()
{
	last = steady_clock::now();
}

float FrameTime::Mark()
{
	const auto old = last;
	last = steady_clock::now();
	const duration<float> dt = last - old;

	return dt.count();
}


