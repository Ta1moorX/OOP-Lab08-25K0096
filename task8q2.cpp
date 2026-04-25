#include <iostream>
using namespace std;

class BallsFaced;

class Runs {
    int runs;
public:
    Runs(int r) : runs(r) {}
    friend float calculateStrikeRate(Runs r, BallsFaced b);
};

class BallsFaced {
    int balls;
public:
    BallsFaced(int b) : balls(b) {}
    friend float calculateStrikeRate(Runs r, BallsFaced b);
};

float calculateStrikeRate(Runs r, BallsFaced b) {
    return ((float)r.runs / b.balls) * 100;
}

int main() {
    Runs r(85);
    BallsFaced b(60);
    cout << "Strike Rate: " << calculateStrikeRate(r, b) << endl;
    return 0;
}