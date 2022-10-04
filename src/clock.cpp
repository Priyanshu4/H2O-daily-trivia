#include "clock.hpp"

using namespace pico_trivia;

DayTime::DayTime(int day, int hour, int minute, int second)
{
	if (second >= 60)
	{
		minute += second / 60;
		second = second % 60;
	}
	if (minute >= 60)
	{
		hour += minute / 60;
		minute = minute % 60;
	}
	if (hour >= 24)
	{
		day += hour / 24;
		hour = hour % 24;
	}
	this->second = second;
	this->minute = minute;
	this->hour = hour;
	this->day = day;
}

int DayTime::get_12_normalized_hour()
{
	if (this->hour == 0)
		return 12;
	if (this->hour > 12)
		return this->hour-12;
	return hour;
}

void Clock::set_time(DayTime time)
{
	this->absolute_set_time = get_absolute_time();
	this->time_set = time;
}

DayTime Clock::get_time()
{
	absolute_time_t now = get_absolute_time();
	int64_t microseconds_diff = absolute_time_diff_us(this->absolute_set_time, now);
	int seconds_diff = microseconds_diff / (1000 * 1000);
	return DayTime(time_set.day, time_set.hour, time_set.minute, time_set.second+seconds_diff);
}
