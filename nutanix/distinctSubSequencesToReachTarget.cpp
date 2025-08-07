#include <bits/stdc++.h>

using namespace std;

int x = 0, y = 0, n = 0, l = 0;
vector<vector<int>> dp;
int ans = 0;

void solve(string &s, int index, int curr) {

  if (curr == y)
    ans++;
  if (curr >= n || curr < 0 || index >= l)
    return;
  if (dp[index][curr] != -1) {
    ans += dp[index][curr];
    return;
  }

  // include
  if (s[index] == 'l') {
    solve(s, index + 1, curr - 1);
  } else {
    solve(s, index + 1, curr + 1);
  }

  // exclude
  int idx = index;
  while (idx < l - 1 && s[idx] == s[idx + 1])
    idx++;
  solve(s, idx + 1, curr);

  dp[index][curr] = ans;
}

int distinctMoves(string s, int N, int X, int Y) {
  // x --> Starting Postion
  // y --> Target Position
  // n --> Max Length on the number line

  // index --> Instruction Iterator;
  // curr --> Current Position on the number line

  x = X;
  y = Y;
  n = N;
  l = s.size();
  dp.resize(l, vector<int>(n + 1, -1));

  solve(s, 0, x);
  return ans;
}

int main() {

  int tests = 1;

  string instructions[] = {"rrlrlr"};

  int warehouses[] = {6};

  int starts[] = {1};

  int end[] = {4};

  int solutions[] = {3};

  for (int i = 0; i < tests; i++) {

    int output =
        distinctMoves(instructions[i], warehouses[i], starts[i], end[i]);
    cout << "----TEST-CASE---: " << i << endl << endl;

    if (output == solutions[i])
      cout << "PASSED";
    else
      cout << "FAILED";
    cout << endl;

    cout << "Instructions: " << instructions[i] << endl;
    cout << "Start: " << starts[i] << endl;
    cout << "End: " << end[i] << endl;

    cout << "Your Distinct Moves: " << output << endl;
    cout << "Correct Solution: " << solutions[i];
  }
}
