#include "RNGWrapper.h"
#include <cassert>

RNGWrapper::RNGWrapper()
	:rng(rd.operator()())
{
}

int RNGWrapper::randRange(const int min, const int max)
{
	std::uniform_int_distribution<int> distribution(min, max);

	int randomNumber = distribution.operator()(rng);

	return randomNumber;
}

std::vector<int> RNGWrapper::randList(const int min, const int max, const int N)
{
	std::vector<int> nRandomNumbers;
	
	nRandomNumbers.reserve(N); //allocates space for N values 

	std::uniform_int_distribution<int> distribution(min, max);

	//for (auto& num : nRandomNumbers)
	while(nRandomNumbers.size() < N)
	{
		int randomNumber = randRange(min, max);

		nRandomNumbers.push_back(randomNumber);
	}

	return nRandomNumbers; 
}


std::vector<std::string> RNGWrapper::getRandomStringsOfLengthN(const int N)
{
	assert(N > 0 && N <= 26);//replace with exception throwing, if desired
	
	std::vector<std::string> randomStringsOfLengthN; 

	std::vector <char> poolOfCharacters; 
	for (char currentLetter = 'a'; currentLetter <= 'z'; ++currentLetter)
	{
		poolOfCharacters.push_back(currentLetter);
	}

	/*select 'N' random indices*/
	std::vector<int> nRandomIndices = randList(0, N, N); 
	
	std::string startingString{}; //will get "piped"/fed through std::permutation 
	for (const auto& randomIndex : nRandomIndices)
	{
		startingString += poolOfCharacters[randomIndex];
	}



	return randomStringsOfLengthN; 
}