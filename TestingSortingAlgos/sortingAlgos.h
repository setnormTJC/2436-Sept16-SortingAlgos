#pragma once

#include<algorithm>
#include<iostream> 
#include <string>
#include <vector>

#include"utils.h"




namespace MySpace
{
    /*O(N^2) complexity*/
    template<typename T> 
    void naiveAscendingSort(std::vector<T>& things)
    {
        int comparsionCount = 0; //these two counters provide a measure of algorithm complexity 
        int swapCount = 0;

        for (int leftIndex = 0; leftIndex < things.size() - 1; ++leftIndex)
        {
            for (int rightIndex = leftIndex + 1; rightIndex < things.size(); ++rightIndex)
            {
                comparsionCount++;
                if (things[leftIndex] > things[rightIndex])
                {
                    swapCount++;
                    //std::swap(things[leftIndex], things[rightIndex]);
                    T temp = things[leftIndex]; //these 3 lines are effectively a swap algo:
                    things[leftIndex] = things[rightIndex];
                    things[rightIndex] = temp;

                }
            }
        }
        std::cout << "Total comparisons required: " << comparsionCount << "\n";
        std::cout << "Total SWAPS required: " << swapCount << "\n";
    }

    /*Just a  joke, but it has O(N!) complexity*/
    template<typename T>
    void monkeySort(std::vector<T>& things)
    {
        while (!std::is_sorted(things.begin(), things.end()))
        {
            myShuffle(things); 
            printThings(things); 
            std::cout << "\n";
        }
    }
}