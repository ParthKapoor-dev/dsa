#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// NOT WORKING FOR NOW

bool Solution(vector<int>& arr){

    vector<pair<int,int>> doms;
    bool flag = true;

    int i = 0;
    while(i < 12){
        doms.push_back({arr[i++], arr[i++]});
    }

    // counting repetitions
    unordered_map<int,pair<int,vector<int>>> m;

    for(int i = 0; i < 12; i++){
        m[arr[i]].first++; //
        m[arr[i]].second.push_back(i);
    }

    vector<vector<int>> centers;

    for(auto x:m){
        if(x.second.first >= 3){
           centers.push_back(x.second.second);
           x.second.first = x.second.first - 3;
        }
    }

    if(centers.size() < 2) return false;

    for(auto x:centers){
        for(auto y:x){
            arr[y] = -1;
        }
    }

    for(int i = 0; i < centers[0].size(); i++){
        int y = centers[0][i] % 2 == 0 ? centers[0][i] + 1: centers[0][i] - 1;

        for(int j = 0; j < centers[1].size(); j++){
            if(y == centers[1][j]){
                centers[1].erase( centers[1].begin() + j);
                centers[0].erase(centers[0].begin() + i);
                break;
            }
        }
    }

    for(auto x:centers){
        if(m[arr[x[0]]].first >= 2){
           m[arr[x[0]]].first =  m[arr[x[0]]].first - 2;
        }else flag = false;
    }

    return flag;
};


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
