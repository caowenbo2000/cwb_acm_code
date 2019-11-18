#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <stack>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  vector<int> visit(n, -1);
  queue<int> q;
  for (int i = 0; i < n; i++) {
    int left = (i + n - 1) % n;
    int right = (i + 1) % n;
    if (s[i] != s[left] && s[i] != s[right]) {
      continue;
    }
    else {
      visit[i] = 0;
      q.push(i);
    }
  }
  while (q.empty() == false) {
    int idx = q.front();
    q.pop();
    int left = (idx + n - 1) % n;
    int right = (idx + 1) % n;
    if (visit[left] == -1) {
      visit[left] = visit[idx] + 1;
      q.push(left);
    }
    if (visit[right] == -1) {
      visit[right] = visit[idx] + 1;
      q.push(right);
    }
  }
  for (int i = 0; i < n; i++) {
    if (visit[i] == -1 || visit[i] > k) {
      if (k % 2 == 1) {
        s[i] = 'B' + 'W' - s[i];
      }
    }
    else {
      if (visit[i] % 2 == 1) {
        s[i] = 'B' + 'W' - s[i];
      }
    }
  }
  cout << s << endl;
  return 0;
}
