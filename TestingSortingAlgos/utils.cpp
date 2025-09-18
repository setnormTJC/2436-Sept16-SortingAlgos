#include <algorithm> //for std::replace()
#include<iostream>

#include "utils.h"


const std::string getFilenameWithTimestamp()
{
	std::string timeString = std::string(__TIME__); //__TIME__ is a convenient, built-in "macro"  
	std::replace(timeString.begin(), timeString.end(), ':', '-'); 
	const std::string filename = "timingResults" + timeString + ".csv";

	return filename; 

}
