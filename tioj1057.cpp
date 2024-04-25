#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main (){
    int M;
    int P;
    int N;
    queue<int> q;
    cin >> M >> P >> N;
    for (int i = 0; i < N; i++){
        int k;
        cin >> k;
        q.push(k);
    }
    q.push(P);
    int start = 0;
    int keep = 0;
    int times = 0;
    bool ipble = false;
    while(!q.empty()){
        if(P < M){
            ipble = false;
            times = 0;
            break;
        }
        while(!q.empty()){
            if (q.front()-start<=M){
                keep = q.front();
                q.pop();
            }
            else{
                times += 1;
      ;
            }
            break;
        }
        start = keep;
        if(q.front()-start > M){
            cout << "IMPOSSIBLE";
            ipble = true;
            break;
        }
    }

    if(!ipble){
        cout << times;
    }
}