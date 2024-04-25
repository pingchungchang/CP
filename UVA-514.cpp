#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
int function(queue<int> target,queue<int> start){
    stack<int> station;
    while(start.empty()==false && target.empty()==false){
        if(station.empty()){
            station.push(start.front());
            start.pop();
        }
        if(station.top()==target.front()){
            station.pop();
            target.pop();
        }
        else {
            station.push(start.front());
            start.pop();            
        }
    }
    // for (int i = 0; i < target.size();i++){
    //     cout << target.front() << ',';
    //     target.pop();
    // }
        if (target.empty())
            return 1;
        else if (target.front() != station.top())
            return 0;
        else{
        while(!station.empty()){
            if(station.top()==target.front()){
                station.pop();
                target.pop();
            }
            else return 0;
        }
        return 1;
    }
}

int main(){
    int N = 9;
    cin >> N;
    vector<int> op;
    while(N !=0){
        while(true){
            queue<int> target;
            queue<int> start;
            int f = 0;
            for (int i = 1; i <= N;i++){
                int k;
                cin >> k;
                if(k==0){
                    f = 1;
                    op.push_back(2);
                    break;
                }
                target.push(k);
                start.push(i);
            }
            if(f==1) break;
            op.push_back(function(target, start));
        }
        cin >> N;
    }
    for (int i = 0; i < op.size();i++){
        if(op[i]==1) cout << "Yes" << endl;
        if(op[i]==0) cout << "No" << endl;
        if(op[i]==2) cout << endl;
    }
}