#include <iostream>
using namespace std;

class TrafficSystem {
    int count;
public:
    TrafficSystem(int c) : count(c) {}

    TrafficSystem operator+(const TrafficSystem& t) {
        return TrafficSystem(count + t.count);
    }
    TrafficSystem operator-(const TrafficSystem& t) {
        return TrafficSystem(count - t.count);
    }
    TrafficSystem operator*(const TrafficSystem& t) {
        return TrafficSystem(count * t.count);
    }
    bool operator==(const TrafficSystem& t) {
        return count == t.count;
    }

    void display() {
        cout << count << " cars" << endl;
    }
};

int main() {
    TrafficSystem t1(50), t2(20);
    TrafficSystem t3(70), t4(15);
    TrafficSystem t5(5),  t6(2);
    TrafficSystem t7(100),t8(100);

    cout << "Addition (50+20):       "; (t1 + t2).display();
    cout << "Subtraction (70-15):    "; (t3 - t4).display();
    cout << "Multiplication (5*2):   "; (t5 * t6).display();
    cout << "Equality (100==100):    " << (t7 == t8 ? "Gridlock! Roads are equal." : "Not equal.") << endl;

    return 0;
}