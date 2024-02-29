#include <iostream>
#include <sstream>
#include <vector>

enum switches 
{ 
    LIGHTS_INSIDE = 1, 
    LIGHTS_OUTSIDE = 2, 
    HEATERS = 4, 
    WATER_PIPE_HEATING = 8, 
    CONDITIONER = 16 
};

std::vector<std::string> userStatesInput() {

    std::cout << "Temperature inside, temperature outside, movement, lights:\n";
    std::string buffer, word;
    std::vector<std::string> words;

    std::getline(std::cin, buffer);
    std::stringstream ss(buffer);
    while(ss >> word) words.push_back(word);

    return words;
}

bool check_int(std::string str){
    
    for (int i = 0; i < str.length(); i++){
        if(i == 0 && str[i] == '-') i++;
        if (isdigit(str[i]) == false) return false;
    }
    return true;
}

bool isInputCorrect(std::vector<std::string> words){
    if(words.size() != 4){
        std::cout << "You only have to input 4 values\n";
        return false;
    }
    if(!(check_int(words[0]))){
        std::cout << "Temperature inside should be a number\n";
        return false;
    }
    if(!(check_int(words[1]))){
        std::cout << "Temperature outside should be a number\n";
        return false;
    }
    if(!((words[2] == "yes") || (words[2] == "no"))){
        std::cout << "Movement can only be yes/no\n";
        return false;
    }
    if(!((words[3] == "on") || (words[3] == "off"))){
        std::cout << "Lights can only be on/off\n";
        return false;
    }

    return true;
}

int main() 
{ 
    //std::cout << "test #2\n";
    int timeHours = 0, switches_state = 0;
    std::vector<std::string> actualStates;

    while(timeHours <= 1){ // The loop will run 2 times, if you want 2 days of simulation as in the task description, write 47
        
        std::cout << "----------\n";
        std::cout << "Time: " << timeHours % 24 << ":00\n";

        // users input and checking
        bool checkInput = true;
        while(checkInput){
            actualStates = userStatesInput();
            if (isInputCorrect(actualStates)) checkInput = false;
        };

        // 1 condition: Water pipe heating and temperature outside
        if(std::stoi(actualStates[1]) < 0){ 
            if(!(switches_state & WATER_PIPE_HEATING)){
                std::cout << "Water pipe heating ON\n";
                switches_state |= WATER_PIPE_HEATING;
            }
        } else if (std::stoi(actualStates[1]) > 5){
            if(switches_state & WATER_PIPE_HEATING){
                std::cout << "Water pipe heating OFF\n";
                switches_state &= ~WATER_PIPE_HEATING;
            }
        }

        // 2 condition: Movement and Lights outside
        if ((timeHours % 24 > 16 || timeHours % 24 < 5) && actualStates[2] == "yes"){
            if(!(switches_state & LIGHTS_OUTSIDE)){
                std::cout << "Lights outside ON\n";
                switches_state |= LIGHTS_OUTSIDE;
            }
        } else {
            if(switches_state & LIGHTS_OUTSIDE){
                std::cout << "Lights outside OFF\n";
                switches_state &= ~LIGHTS_OUTSIDE;
            }
        }

        // 3 condition: Temperature inside and Heaters
        if(std::stoi(actualStates[0]) < 22){ 
            if(!(switches_state & HEATERS)){
                std::cout << "Heaters ON\n";
                switches_state |= HEATERS;
            }
        } else if (std::stoi(actualStates[0]) > 25){
            if(switches_state & HEATERS){
                std::cout << "Heaters OFF\n";
                switches_state &= ~HEATERS;
            }
        }

        // 4 condition: Temperature inside and Conditioner 
        if(std::stoi(actualStates[0]) >= 30){ 
            if(!(switches_state & CONDITIONER )){
                std::cout << "Conditioner ON\n";
                switches_state |= CONDITIONER ;
            }
        } else if (std::stoi(actualStates[0]) <= 25){
            if(switches_state & CONDITIONER ){
                std::cout << "Conditioner OFF\n";
                switches_state &= ~CONDITIONER ;
            }
        }

        // 5 condition: light inside and light temperature
        if ((timeHours % 24 >= 16 && timeHours % 24 <= 20) && actualStates[3] == "on"){
            if(!(switches_state & LIGHTS_INSIDE )){
                std::cout << "Lights inside ON\n";
                std::cout << "Color temperature: " << 2700 + (575 * (20 - (timeHours % 24))) <<"K\n"; // каждый час с 16:00 до 20:00 температура света падает на 575К
                switches_state |= LIGHTS_INSIDE;
            }
        } else if ((timeHours % 24 > 20 && timeHours % 24 <= 23) && actualStates[3] == "on"){
            if(!(switches_state & LIGHTS_INSIDE )){
                std::cout << "Lights inside ON\n";
                std::cout << "Color temperature: " << 2700 <<"K\n"; // после 20:00 температура света 2700К
                switches_state |= LIGHTS_INSIDE;
            }
        } else if ((timeHours % 24 >= 0 && timeHours % 24 < 16) && actualStates[3] == "on"){
            if(!(switches_state & LIGHTS_INSIDE )){
                std::cout << "Lights inside ON\n";
                std::cout << "Color temperature: " << 5000 <<"K\n"; //после 00:00 температура света 5000К
                switches_state |= LIGHTS_INSIDE;
            }
        } else {
            if(switches_state & LIGHTS_INSIDE ){
                std::cout << "Lights inside OFF\n";
                switches_state &= ~LIGHTS_INSIDE;
            }
        }
        timeHours++;
    }
} 
