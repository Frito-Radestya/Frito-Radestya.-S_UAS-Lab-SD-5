#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--; 
    }

    vector<int> dp(n, 0);
    int max_depth = 0;

    for (int i = 0; i < n; ++i) {
        int current_depth = 1;
        int current_employee = i;
        while (p[current_employee] != -2) { 
            if (p[current_employee] == -1) {
                break;
            }
            current_employee = p[current_employee];
            current_depth++;
        }
        dp[i] = current_depth;
        max_depth = max(max_depth, dp[i]);
    }

    cout << "jumlah grup minimal nya " << max_depth << endl;

    return 0;
}