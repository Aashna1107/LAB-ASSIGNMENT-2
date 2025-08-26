#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string &s1, const string &s2) {
    return s2.find(s1) != string::npos;
}

bool canSplit(const string &s) {
    int n = s.length();
    
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, j - i);
            string c = s.substr(j + 1);

            if ((isSubstring(a, b) && isSubstring(a, c)) ||
                (isSubstring(b, a) && isSubstring(b, c)) ||
                (isSubstring(c, a) && isSubstring(c, b))) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    if (canSplit(s))
        cout << "YES, possible\n";
    else
        cout << "NO, not possible\n";

    return 0;
}

