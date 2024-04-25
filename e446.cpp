#include <bits/stdc++.h>
using namespace std;
void(dfs(deque<int> s,vector<int> v)){
    if(s.size()==v.size()-1){
        while(s.size()>1){
            printf("%d ",s.front());
            s.pop_front();
        }
        printf("%d\n",s.front());
        s.pop_front();
        return;
    }
    for(int i = 1;i<=v.size()-1;i++){
        if(v[i] != 1){
            s.push_back(i);
            v[i] = 1;
            dfs(s,v);
            v[i] = 0;
            s.pop_back();
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v(n+1,0);
    for(int i = 1;i<=v.size()-1;i++){
        deque<int> s;
        v[i] = 1;
        s.push_back(i);
        dfs(s,v);
        s.pop_back();
        v[i] = 0;
    }
}