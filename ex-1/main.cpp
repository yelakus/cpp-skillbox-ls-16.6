#include <iostream>

bool compare(float value, float reference, float epsilon)
{
    return (value >= reference - epsilon) && (value <= reference + epsilon);
}

int main() {
    float speed = 0, delta;
    char speed_str[4];

    do {
        std::cout << "Speed delta: ";
        std::cin >> delta;

        speed += delta;
        if (speed < 0 || compare(speed, 0, 0.01)) break;

        if (speed > 150.0) speed = 150.0;
        std::sprintf(speed_str, "%.1f", speed);
        std::cout << "Speed: " << speed_str << std::endl;

    } while(true);

    std::cout << "Speed: 0" << std::endl;
}
