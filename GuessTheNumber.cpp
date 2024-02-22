#include <iostream>
#include <cstdlib> 

int main(){
    int randomNum;
    int chosen;
    randomNum = rand() % 11;

    std::cout << "Choose a number between 1-10\n>";
    std::cin >> chosen;

    while (true)
    {
        if (chosen > randomNum)
        {
            std::cout << "Choose a lower num\n>";
            std::cin >> chosen;
        }else if (chosen < randomNum)
        {
            std::cout << "Choose a higher num\n>";
            std::cin >> chosen;
        }else{
            std::cout << "BINGOOO DING DING DIGN";
            break;
        }
        
        
    }
    
    return 0;
}

