#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1e4;
int n, m, k, a[maxn + 3], u[maxn + 3], v[maxn + 3], fa[maxn + 3], dep[maxn + 3], Co, Ce, So[maxn + 3], Se[maxn + 3];
bool vis[maxn + 3];
vector<int> G[maxn + 3];

void dfs(int u) {
    vis[u] = true;
    for (int i = 0, v; i < G[u].size(); i++) {
        v = G[u][i];
        if (!vis[v]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dfs(v);
        } else if (v != fa[u] && dep[u] > dep[v]) {//改边为返祖边
            int len = dep[u] - dep[v] + 1;//判断环的长度
            if (len & 1) {//如果是奇数环 奇数环+1差分奇数环
                Co++;
                So[u]++, So[v]--;
            } else {//偶数环就就用
                Ce++;
                Se[u]++, Se[v]--;
            }
        }
    }
}

void dfs_sum(int u) {
    vis[u] = true;
    for (int i = 0, v; i < G[u].size(); i++) {
        v = G[u][i];
        if (!vis[v]) {
            dfs_sum(v);
            So[u] += So[v];
            Se[u] += Se[v];
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &u[i], &v[i]);
        G[u[i]].push_back(v[i]), G[v[i]].push_back(u[i]);
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) {
        dfs(i);
    }
    fill(vis + 1, vis + n + 1, false);
    for (int i = 1; i <= n; i++) if (!vis[i]) {//计算差分链
        dfs_sum(i);
    }
    for (int i = 1; i <= m; i++) {  
        if (dep[u[i]] < dep[v[i]]) { //保证u更深
            swap(u[i], v[i]);
        }
        if (Co == 0 || (Co == 1 && dep[u[i]] != dep[v[i]] + 1 && (dep[u[i]] - dep[v[i]] + 1) & 1) || (dep[u[i]] == dep[v[i]] + 1 && So[u[i]] == Co && Se[u[i]] == 0)) {
            a[++k] = i;//不存在奇数环  返祖边  存在奇数环且不存在偶数环
        } 
    }
    printf("%d\n", k);
    for (int i = 1; i <= k; i++) {
        printf("%d%c", a[i], " \n"[i == k]);
    }
    return 0;
}