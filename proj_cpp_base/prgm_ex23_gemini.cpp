#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        counts[val]++;
    }

    int maxCount = 0;
    int mostFrequent = -1; // Initialize with a value that won't be a valid key

    for (auto const& [key, count] : counts) {
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = key;
        }
    }

    cout << mostFrequent << " " << maxCount << endl;

    return 0;
}