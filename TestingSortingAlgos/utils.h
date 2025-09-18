#pragma once

#include<algorithm> //for std::swap
#include<string>
#include<vector> 

#include"RNGWrapper.h" //for `myShuffle`'s use

template<typename T> 
void printThings(const std::vector<T>& things)
{
    for (const auto& thing : things)
    {
        std::cout << thing << " ";
    }
}

template<typename T>
void myShuffle(std::vector<T>& things)
{
    RNGWrapper rng;
    
    for (int i = 0; i < things.size(); ++i) //N swaps should? be sufficiently "shuffled"
    {
        int randomIndex = rng.randRange(0, things.size() - 1);  //randRange is INCLUSIVE, so subtract 1 from size

        std::swap(things[i], things[randomIndex]);
    }

}

const std::string getFilenameWithTimestamp(); 