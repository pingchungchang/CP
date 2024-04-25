#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
    int n;
    unordered_map<int,int> repeated;
    priority_queue<int,vector<int>,greater<int>> pq;
    cin>>n;
    int s = 0;
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        if(repeated.count(k) ==0){
            pq.push(k);
            repeated[k] = 1;
            s++;
        }
    }
    cout<<s<<"\n";
    vector<int> ans;
    while(!pq.empty()){
        cout<<pq.top()<<' ';
        pq.pop();
    }
    return 0;
}
