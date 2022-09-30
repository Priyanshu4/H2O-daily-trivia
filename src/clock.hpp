#include "pico/stdlib.h"

namespace pico_trivia 
{
	class DayTime
	{
		public:
			int day;
			int hour;
			int minute;
			int second;
			DayTime(int day=0, int hour=0, int minute=0, int second=0);
	};
	
	class Clock 
	{
		private:
			// Time since boot which clock was set
			absolute_time_t absolute_set_time;
			
			// The time clock was set too
			DayTime time_set = DayTime();
			
		public:
			void set_time(DayTime time);
			DayTime get_time();
	};
}
