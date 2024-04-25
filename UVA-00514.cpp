#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0) return 0;
        int k;
        while(cin>>k){
            if(k == 0){
                cout<<endl;
                break;
            }
            vector<int> v(n,0);
            v[0] = k;
            for(int i = 1;i<n;i++){
                cin>>k;
                v[i] = k;
            }
            stack<int> s;
            queue<int> q;
            for(int i = 1;i<=n;i++){
                q.push(i);
            }
            int x = 0;
            while(!q.empty()){
                if(q.front()==v[x]){
                    x++;
                    q.pop();
                }
                else{
                    if(!s.empty()&&s.top()==v[x]){
                        s.pop();
                        x++;
                    }
                    else{
                        s.push(q.front());
                        q.pop();
                    }
                }
            }
            while(!s.empty()){
                if(s.top()!= v[x]){
                    cout<<"No\n";
                    break;
                }
                s.pop();
                x++;
            }
            if(s.empty())cout<<"Yes\n";
        }
    }
}
