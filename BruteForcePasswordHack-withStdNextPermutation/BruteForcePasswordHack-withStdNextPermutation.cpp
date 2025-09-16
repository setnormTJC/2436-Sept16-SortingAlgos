// BruteForcePasswordHack-withStdNextPermutation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<algorithm>
#include <iostream>
#include<string> 
#include <vector>

template<typename Type> 
void printVector(const std::vector<Type>& things, const std::string& separator)
{
    for (const auto& thing : things)
    {
        std::cout << thing << separator;
    }
}

int main()
{
    std::cout << "Enter password of length 5 - use only a through e:\n";
    std::string enteredPassword; 
    std::getline(std::cin, enteredPassword);

    std::vector<char> allowedPasswordLetters =
    {
        'a',
        'b',
        'c', 
        'd', 
        'e'
    };

    const std::string separator = "";

    bool foundPassword = false; 

    while (std::next_permutation(allowedPasswordLetters.begin(), allowedPasswordLetters.end())
        && 
        !foundPassword)
    {
        printVector(allowedPasswordLetters, separator);
        std::cout << "\n";
        std::system("pause"); 

        //foundPassword = ...compare enteredPassword to guessedPassword
    }
    

}

