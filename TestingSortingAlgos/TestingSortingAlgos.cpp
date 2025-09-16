// TestingSortingAlgos.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector> 

namespace MySpace
{
    void printThings(const std::vector<std::string>& things)
    {
        for (const auto& thing : things)
        {
            std::cout << thing << " ";
        }
    }
    //void mySwap(); //come back to me next class? 

    void naiveSort(std::vector<std::string>& things)
    {
        for (int leftIndex = 0; leftIndex < things.size() - 1; ++leftIndex)
        {
            for (int rightIndex = leftIndex + 1; rightIndex < things.size(); ++rightIndex)
            {
                if (things[leftIndex] > things[rightIndex])
                {
                    std::swap(things[leftIndex], things[rightIndex]);

                    std::cout << "Swapped things " << things[leftIndex] <<
                        " and " << things[rightIndex] << "\n";
                    printThings(things); 

                    std::system("pause"); 

                    
                }
            }
        }
    }

}


int main()
{
    
    std::vector <std::string> words =
    {
        "delta",
        "epsilon",
        "alpha",
        "beta",
        "charlie"
    };
    
    //std::swap(words[0], words[1]); //just a simple demo that std::swap works as expected

    std::cout << "Address of words in main: " << &words << "\n";

    MySpace::naiveSort(words); 

    //MySpace::printThings(words);

}

