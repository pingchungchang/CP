#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int la,lb,lc;
    cin>>la>>lb>>lc;
    priority_queue<int,vector<int>,greater<int>> a;
    priority_queue<int,vector<int>,greater<int>> b;
    priority_queue<int,vector<int>,greater<int>> c;
    unordered_map<int,int> ua;
    unordered_map<int,int> ub;
    unordered_map<int,int> uc;
    for(int i =0;i<la;i++){
        int j;
        cin>>j;
        if(ua.count(j)==0) a.push(j);
        ua[j] = 1;
    }
    for(int i =0;i<lb;i++){
        int j;
        cin>>j;
        if(ub.count(j) == 0)b.push(j);
        ub[j] = 1;
    }
    for(int i =0;i<lc;i++){
        int j;
        cin>>j;
        if(uc.count(j) == 0)c.push(j);
        uc[j] = 1;
    }
    int a1 = 0;
    int c1 = 0;
    int ans = 0;
    while(!b.empty()){
        if(!a.empty()&&a.top()<=b.top()){
            a1++;
            a.pop();
        }
        else if(!c.empty()&&c.top()<=b.top()){
            c1++;
            c.pop();
        }
        else{
            ans += a1*c1;
            b.pop();
        }
    }
    cout<<ans;
}
