#ifndef STRING_PERMUTATION_H
#define STRING_PERMUTATION_H

#include <iostream>
#include <vector>
using namespace std;

/*
* Time Complexity: O(n * n!)
* Auxiliary Space: O(n!)
 */
void string_permutation_recursion(string s, const int idx, vector<string> &cases) {
    if (idx == s.size()) return cases.push_back(s);

    for (int i = idx; i < s.size(); i++) {
        char temp_c = s[idx];
        s[idx] = s[i];
        s[i] = temp_c;

        string_permutation_recursion(s, idx + 1, cases);

        temp_c = s[i];
        s[i] = s[idx];
        s[idx] = temp_c;
    }
}

void string_permutation_solution(string s) {
    vector<string> cases;
    string_permutation_recursion(s, 0, cases);

    const auto caseNumber = cases.size();
    cout << "Case number: " << caseNumber << endl;
    for (auto &a: cases) {
        cout << a << endl;
    }
}

#endif //STRING_PERMUTATION_H
