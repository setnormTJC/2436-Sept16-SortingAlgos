#include "demos.h"
#include <vector>

#include"sortingAlgos.h"

void demoStringSorting()
{
    //std::vector <std::string> randomCase =
//{
//    "delta",
//    "epsilon",
//    "alpha",
//    "beta",
//    "charlie"
//};

    std::vector<std::string> bestCase =
    {
        "alpha",
        "bravo",
        "charlie",
        "delta",
        "epsilon"
    };

    std::reverse(bestCase.begin(), bestCase.end()); //now "best" has become "worst"!

    MySpace::naiveAscendingSort(bestCase);

}

void demoNumberSorting()
{
    RNGWrapper rng;
    auto oneHundredThousandRandomNums = rng.randList(0, 100'000, 100'000);
    MySpace::naiveAscendingSort(oneHundredThousandRandomNums);

    //std::sort(oneHundredThousandRandomNums.begin(), oneHundredThousandRandomNums.end());
    std::cout << "..Done with naive sort\n";
    //RNGWrapper rng; 
    //auto oneHundredRandomNumbers = rng.randList(0, 100, 100); //between 0 and 100 

    //printThings(oneHundredRandomNumbers);
    //std::cout << "\n";
    //MySpace::naiveAscendingSort(oneHundredRandomNumbers);

    //printThings(oneHundredRandomNumbers);
    //std::cout << "\n";


    ////array is now in ascending order - let's reverse it (for a worst case input): 
    //std::reverse(oneHundredRandomNumbers.begin(), oneHundredRandomNumbers.end());

    //std::cout << "\n\n\nNow in REVERSE order:\n";
    //printThings(oneHundredRandomNumbers);

    //MySpace::naiveAscendingSort(oneHundredRandomNumbers);

}
