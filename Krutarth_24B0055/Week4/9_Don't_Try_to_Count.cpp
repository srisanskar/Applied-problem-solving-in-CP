// Codeforces Problem 1881A
#include <iostream>
#include <string>
using namespace std;

int minOperationsToGetSubstring(string x, string s) {
    string current = x;
    int operations = 0;

    while (current.find(s) == string::npos) {
        current += current;  // simulate appending x to itself
        operations++;
        if (current.size() > 1000) break; // safety cap to avoid infinite loop
    }

    return (current.find(s) != string::npos) ? operations : -1;
}

int main() {
    string x = "ab", s = "ababab";
    int result = minOperationsToGetSubstring(x, s);

    if (result != -1) {
        cout << "Minimum operations: " << result << endl;
    } else {
        cout << "Substring can't be formed with given constraints." << endl;
    }

    return 0;
}
