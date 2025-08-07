#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;

// Helper to create a canonical pair (sorted)
pair<int, int> make_sorted_pair(int a, int b) {
    if (a > b) swap(a, b);
    return {a, b};
}

// Helper to check if the input dominoes match a required configuration
bool check(const multiset<pair<int, int>>& input_dominoes,
           int c1, int c2, int x, int y, int a, int b) {
    
    multiset<pair<int, int>> required_dominoes;
    required_dominoes.insert(make_sorted_pair(c1, c2));
    required_dominoes.insert(make_sorted_pair(c1, c2));
    required_dominoes.insert(make_sorted_pair(c1, x));
    required_dominoes.insert(make_sorted_pair(c2, y));
    required_dominoes.insert(make_sorted_pair(x, a));
    required_dominoes.insert(make_sorted_pair(y, b));

    return input_dominoes == required_dominoes;
}

bool Solution(vector<int>& arr) {
    // 1. Count frequencies of each number
    unordered_map<int, int> counts;
    for (int val : arr) {
        counts[val]++;
    }

    // 2. Group numbers by their frequency
    vector<int> threes, twos, ones;
    for (auto const& [val, count] : counts) {
        if (count == 3) {
            threes.push_back(val);
        } else if (count == 2) {
            twos.push_back(val);
        } else if (count == 1) {
            ones.push_back(val);
        } else {
            // Any other frequency means it's impossible
            return false;
        }
    }

    // 3. A valid pyramid structure requires exactly two numbers of each frequency group (3, 2, 1)
    if (threes.size() != 2 || twos.size() != 2 || ones.size() != 2) {
        return false;
    }

    // 4. Create a multiset of the input dominoes for easy comparison.
    // We use sorted pairs to treat (a,b) and (b,a) as the same domino.
    multiset<pair<int, int>> input_dominoes;
    for (size_t i = 0; i < arr.size(); i += 2) {
        input_dominoes.insert(make_sorted_pair(arr[i], arr[i + 1]));
    }

    // 5. Define the groups of numbers based on frequency.
    // c1, c2 are the central "spine" numbers.
    int c1 = threes[0], c2 = threes[1];
    // x1, x2 are the intermediate link numbers.
    int x1 = twos[0], x2 = twos[1];
    // o1, o2 are the outer "leaf" numbers.
    int o1 = ones[0], o2 = ones[1];

    // 6. Check all valid permutations of pairings against the input dominoes.
    // The spine is fixed with {c1, c2}. We need to check the pairings for the
    // intermediate (twos) and leaf (ones) numbers.
    
    // Case 1: x1 is paired with c1, x2 with c2.
    // Then we check both possibilities for pairing the 'ones'.
    if (check(input_dominoes, c1, c2, x1, x2, o1, o2)) return true;
    if (check(input_dominoes, c1, c2, x1, x2, o2, o1)) return true;

    // Case 2: x2 is paired with c1, x1 with c2.
    // Again, check both possibilities for pairing the 'ones'.
    if (check(input_dominoes, c1, c2, x2, x1, o1, o2)) return true;
    if (check(input_dominoes, c1, c2, x2, x1, o2, o1)) return true;

    // If none of the valid configurations match the input, it's not possible.
    return false;
}


int main(){

    vector<vector<int>> questions = {
        { 4, 3, 3, 4, 1, 2, 2, 3, 6, 5, 4, 5 },
    };

    vector<bool> answers = {
        true
    };

    for(int index = 0; index < questions.size(); index++) {
        cout << "----TEST-CASE---: " << index << endl;
        bool ans = Solution(questions[index]);
        cout << "Answer: " << ans << endl;
        if( ans == answers[index]) cout << "Correct answer";
        else cout << "FAILED";
        cout << endl;
        cout << endl;
    }

}
