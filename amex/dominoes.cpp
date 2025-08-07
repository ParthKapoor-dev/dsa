#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <utility>

using namespace std;


int Solution(vector<int>& arr){

    int c1 = -1, c2 = -1, a = -1, b = -1;

    vector<pair<int,int>> doms;
    unordered_map<int,int> m;

    int i = 0;
    while(i < 12){
        doms.push_back({arr[i], arr[i+1]});
        i += 2;
    }

    for(auto k:arr) m[k]++;

    for(auto p:doms){
        if(m[p.first] == 3 && m[p.second] == 3){
            c1 = min(p.first, p.second);
            c2 = max(p.first, p.second);
        }
    }

   for(auto p:doms){
        if((p.first == c1 || p.first == c2) && m[p.second] == 2){
            a = p.second;
        }else if((p.second == c1 || p.second == c2) && m[p.first] == 2){
            b = p.first;
        }
   }

   vector<int> result = { a, b, c1, c2 };
   for(auto x:result) if(x == -1) return false;

   return true;
}

int main(){

    vector<vector<int>> questions = {
        { 4, 3, 3, 4, 1, 2, 2, 3, 6, 5, 4, 5 }, // Should be YES
        { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4 }, // Should be NO (wrong counts)
    };

    vector<bool> answers = {
        true,
        false,
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
