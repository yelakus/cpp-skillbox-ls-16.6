#include <iostream>

enum note { 
        DO = 1, 
        RE = 2, 
        MI = 4, 
        FA = 8, 
        SOL = 16, 
        LA = 32, 
        SI = 64 
    };

void printNote(int notes){
    if (notes & DO) std::cout << "DO ";
    if (notes & RE) std::cout << "RE ";
    if (notes & MI) std::cout << "MI ";
    if (notes & FA) std::cout << "FA ";
    if (notes & SOL) std::cout << "SOL ";
    if (notes & LA) std::cout << "LA ";
    if (notes & SI) std::cout << "SI ";
}

int main(){
    
    int notes = 0;
    std::string chords;

    std::cout << "Input notes: " << std::endl;
    std::cin >> chords;

    for (auto num : chords){  
        notes |= 1 << ((num - '0')-1);
    }

    printNote(notes);
}