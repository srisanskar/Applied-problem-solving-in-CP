#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> people;
    for (int i = 1; i <= n; i++) {
        people.push_back(i);
    }

    int index = 0;
    while (!people.empty()) {
        index = (index + k) % people.size();
        cout << people[index] << " ";
        people.erase(people.begin() + index);
    }
    cout << endl;
}