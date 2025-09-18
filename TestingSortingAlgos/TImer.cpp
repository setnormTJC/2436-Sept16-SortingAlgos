#include "Timer.h"

#include<fstream>
#include<iomanip>
#include <iostream>


void Timer::start()
{
	startTimePoint = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
	endTimePoint = std::chrono::high_resolution_clock::now();

	executionTimeInNanoseconds = (endTimePoint - startTimePoint).count();

	//std::cout << std::setprecision(2) << std::scientific  //requires double arg
	//			<< "Whatever ya just did took this many nanoseconds: " 
	//	<< (double)executionTimeInNanoseconds << "\n";
}

void Timer::writeNAndExecutionTimeToFile(const int N, const std::string& filename)
{
	std::ofstream outfile(filename, std::ios::app); //note the append 

	//MIGHT? want to check if writing to an empty file (as a sort of safety) 

	outfile << N << "," << executionTimeInNanoseconds << "\n";

	outfile.close(); //Be a good boy or girl and don't leave files open! 

	std::cout << "Wrote 'N' and 't' to filename " << filename << "\n";
}


