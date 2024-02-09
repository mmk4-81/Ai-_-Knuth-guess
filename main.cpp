#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <iomanip>
#include <memory>
#include <stack>

using namespace std;

void knuthGuess(float goal);

class Node {
public:
    float num;
    shared_ptr<Node> parent;
    string action;
    int level;

    Node(float num, shared_ptr<Node> parent, string action, int level) : num(num), parent(parent), action(action), level(level) {}
};


int main(){

    float target;
    cout << "Enter the target number:\n >>";
    cin >> target;

    knuthGuess(target);

    return 0;
}

void knuthGuess(float goal) {

}