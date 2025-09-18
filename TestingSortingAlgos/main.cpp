// TestingSortingAlgos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector> 

#include"RNGWrapper.h"
#include"sortingAlgos.h"
#include"Timer.h"
#include"utils.h"

//namespace MySpace
//{
//
//    /*O(N^2) complexity*/
//    void naiveAscendingSort(std::vector<std::string>& things)
//    {
//        int comparsionCount = 0; //these two counters provide a measure of algorithm complexity 
//        int swapCount = 0;
//
//        for (int leftIndex = 0; leftIndex < things.size() - 1; ++leftIndex)
//        {
//            for (int rightIndex = leftIndex + 1; rightIndex < things.size(); ++rightIndex)
//            {
//                comparsionCount++;
//                if (things[leftIndex] > things[rightIndex])
//                {
//                    swapCount++; 
//                    //std::swap(things[leftIndex], things[rightIndex]);
//                    std::string temp = things[leftIndex]; //these 3 lines are effectively a swap algo:
//                    things[leftIndex] = things[rightIndex];
//                    things[rightIndex] = temp; 
//
//                  
//                    // std::cout << "Swapped things " << things[leftIndex] <<
//                    //    " and " << things[rightIndex] << "\n";
//                    ////printThings(things); 
//                    ////std::cout << "\n";
//                    ////std::system("pause"); 
//                    ////std::cout << "\n";
//                    ////std::cout << "\n";
//                    
//                }
//            }
//        }
//        std::cout << "Total comparisons required: " << comparsionCount << "\n";
//        std::cout << "Total SWAPS required: " << swapCount << "\n";
//    }
//}


int main()
{
    std::vector <std::string> randomCase =
    {
        "delta",
        "epsilon",
        "alpha",
        "beta",
        "charlie"
    };

    MySpace::monkeySort(randomCase); 


    
}

