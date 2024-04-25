#include <bits/stdc++.h>
using namespace std;

int n,m;
int main(){
    cin>>n>>m;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    for(int i = 0;i<m;i++){
        string s(m,'0');
        s[i] = '1';
        cout<<"? "<<s<<endl;
        int k;
        cin>>k;
        pq.push(make_pair(k,i));
    }
    string s(m,'0');
    int sum = 0;
    while(!pq.empty()){
        pair<int,int> now = pq.top();pq.pop();
        s[now.second] = '1';
        sum += now.first;
        cout<<"? "<<s<<endl;
        int k;cin>>k;
        if(k != sum){
            s[now.second] = '0';
            sum -= now.first;
        }
    }
    cout<<"! "<<sum<<endl;
}
