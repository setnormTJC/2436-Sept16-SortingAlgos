#pragma once

#include<chrono> 
#include <string>

class Timer
{
private: 
	std::chrono::steady_clock::time_point startTimePoint{};
	std::chrono::steady_clock::time_point endTimePoint{};

	/*If an algo takes longer than 2 seconds (2 billion ns), the integer will overflow!*/
	long long executionTimeInNanoseconds{}; //brace syntax initializes to 0 ("similar" action above) 

public: 
	Timer() = default;

	void start(); 

	void stop();

	void writeNAndExecutionTimeToFile(const int N, const std::string& filename);

};

//class AlgoTimer : public Timer //probably a better way to go about it 
//{
//	void writeNAndExecutionTimeToFile(const int N, const std::string& filename);
//};


