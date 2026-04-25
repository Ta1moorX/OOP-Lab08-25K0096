#include <iostream>
using namespace std;

class Time;

class Speed {
    float kmh;
public:
    Speed(float s) : kmh(s) {}
    friend float calculateDistance(Speed s, Time t);
};

class Time {
    float hours;
public:
    Time(float t) : hours(t) {}
    friend float calculateDistance(Speed s, Time t);
};

float calculateDistance(Speed s, Time t) {
    return s.kmh * t.hours;
}

int main() {
    Speed s(60);
    Time t(2);
    cout << "Distance traveled: " << calculateDistance(s, t) << " km" << endl;
    return 0;
}