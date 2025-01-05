#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    vector<tuple<int, int> > intervals(n);
    for (tuple<int, int>& interval: intervals) {
        cin >> get<0>(interval) >> get<1>(interval);
    }

    std::sort(begin(intervals), end(intervals), [](auto const &t1, auto const &t2) {
        return get<0>(t1) < get<0>(t2); // or use a custom compare function
    });

    int max_intervals = 0;
    int chain_end = -1;
    for (auto interval: intervals) {
        cerr << get<0>(interval) << get<1>(interval) << "\n";
        if (get<0>(interval) > chain_end) {
            chain_end = get<1>(interval);
            max_intervals++;
        }
    }

    cout << max_intervals;
}