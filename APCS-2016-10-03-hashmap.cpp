#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    unordered_map<int, vector<int>> map;
    // map[value] = [front,next]
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n;i++){
        map[i].push_back(i - 1);
        map[i].push_back(i + 1);
    }
    map[1][0] = n;
    map[n][1] = 1;
    int f = 1;
    for (int i = 0; i < k;i++){
        for (int j = 1; j <= m-1;j++){
            f = map[f][1];
        }
        map[map[f][1]][0] = map[f][0];
        // cout << f;
        map[map[f][0]][1] = map[f][1];
        f = map[f][1];
    }
    cout << f<<endl;
}
// why k<=m do not work??????????