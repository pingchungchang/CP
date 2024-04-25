#include <bits/stdc++.h>
using namespace std;

struct Node{
    int depth;
    int father;
    vector<int> edges;
    int weight, weightAll;
};

int n, k;
Node node[200005];

void DFS(int depth, int id) {
    node[id].depth = depth;
    for (auto i : node[id].edges) {
        if (node[id].father == i) continue;
        node[i].father = id;
        DFS(depth + 1, i);
        node[id].weightAll ^= node[i].weightAll;
    }
}

void solve() {
    int x, y;
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> node[i].weight;
        node[i].weightAll = node[i].weight;
    }
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        node[--x].edges.push_back(--y);
        node[y].edges.push_back(x);
    }
    node[0].father = -1;
    DFS(0, 0);
    if (node[0].weightAll == 0) cout << "YES\n";
    else if (k == 2) cout << "NO\n";
    else {
        bool flag = true;
        for (auto i : node[0].edges) q.push(i);
        while (!q.empty()) {
            cout<<q.front()<<' '<<node[q.front()].weightAll<<',';
            if (node[q.front()].weightAll == node[0].weightAll) {
                flag = !flag;
                if (flag) {
                    cout << "YES\n";
                    return;
                }
            } else {
                for (auto j : node[q.front()].edges) {
                    if (j == node[q.front()].father) continue;
                    q.push(j);
                }
            }
            q.pop();
        }
        cout << "NO\n";
    }
    return;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}


/*
1
7 3
1 1 1 1 1 1 3
1 2
2 3
3 4
4 5
5 6
6 7
*/
