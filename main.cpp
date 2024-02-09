#include <iostream>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <iomanip>
#include <memory>
#include <stack>

using namespace std;

void knuthGuess(float goal);

class Node
{
public:
    float num;
    shared_ptr<Node> parent;
    string action;
    int level;

    Node(float num, shared_ptr<Node> parent, string action, int level) : num(num), parent(parent), action(action), level(level) {}
};

int main()
{

    float target;
    cout << "Enter the target number:\n >>";
    cin >> target;

    knuthGuess(target);

    return 0;
}

void knuthGuess(float goal)
{
    queue<shared_ptr<Node>> frontier;
    unordered_set<float> explored;

    frontier.push(make_shared<Node>(4, nullptr, "root", 0));

     while (!frontier.empty()) {

        shared_ptr<Node> current = frontier.front();
        frontier.pop();


        float current_num = current->num;
        float num_times_5 = current_num * 5;
        if (explored.find(num_times_5) == explored.end()) {
            shared_ptr<Node> state = make_shared<Node>(num_times_5, current, "*5", current->level + 1);
            frontier.push(state);
            explored.insert(num_times_5);
        }


        float sqrt_num = sqrt(current_num);
        if (explored.find(sqrt_num) == explored.end()) {
            shared_ptr<Node> state = make_shared<Node>(sqrt_num, current, "sqrt", current->level + 1);
            frontier.push(state);
            explored.insert(sqrt_num);
        }

        float floor_num = floor(current_num);
        if (explored.find(floor_num) == explored.end()) {
            shared_ptr<Node> state = make_shared<Node>(floor_num, current, "floor", current->level + 1);
            frontier.push(state);
            explored.insert(floor_num);
        }
    }


    cout << "No solution found!" << endl;
}