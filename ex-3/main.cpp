#include <iostream>
#include <sstream>

int main() {
    double res;
    std::string buffer, a, b ,operation;
    std::cout << "Input command:";
    std::cin >> buffer;

    for(int i = 0; i < buffer.size(); ++i){

        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/'){
            operation = buffer[i];
            for (int j = i+1; j < buffer.size(); ++j){
                b += buffer[j];
            }
            break;
        }
        a += buffer[i];
    }

    if (operation == "+"){
        res = std::stod(a) + std::stod(b);
        std::cout << a << " + " << b << " = " << res << std::endl;
    } else if (operation == "-"){
        res = std::stod(a) - std::stod(b);
        std::cout << a << " - " << b << " = " << res << std::endl;
    } else if (operation == "/"){
        res = std::stod(a) / std::stod(b);
        std::cout << a << " / " << b << " = " << res << std::endl;
    } else if (operation == "*"){
        res = std::stod(a) * std::stod(b);
        std::cout << a << " * " << b << " = " << res << std::endl;
    }
}
