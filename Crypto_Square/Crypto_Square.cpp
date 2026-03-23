#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

string normalize(const string& text) {
    string result;
    for (char c : text) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    return result;
}

int main() {
    string input;

    cout << "Ingrese el texto: ";
    getline(cin, input);

    string s = normalize(input);
    int n = s.size();

    int c = ceil(sqrt(n));
    int r = floor(sqrt(n));
    if (r * c < n) r++;

    vector<string> grid(r, string(c, ' '));

    int idx = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (idx < n) {
                grid[i][j] = s[idx++];
            }
        }
    }

    cout << "Resultado: ";

    for (int j = 0; j < c; j++) {
        for (int i = 0; i < r; i++) {
            cout << grid[i][j];
        }
        cout << " ";
    }

    cout << endl;

    return 0;
}
