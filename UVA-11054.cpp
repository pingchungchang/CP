#include <bits/stdc++.h>
using namespace std;

int main(){
    int m;
    while(cin>>m){
        if(m == 0) return 0;
        queue<pair<int,int>> givers;
        queue<pair<int,int>> buyers;
        for(int j = 0;j<m;j++){
            int k;
            cin>>k;
            if(k>0) buyers.push(make_pair(k,j));
            else if(k<0) givers.push(make_pair(-k,j));
        }
        int ans = 0;
        while(!buyers.empty()){
            if(buyers.front().first-givers.front().first>0){
                buyers.front().first-=givers.front().first;
                ans += givers.front().first*max(givers.front().second-buyers.front().second,buyers.front().second-givers.front().second);
                givers.pop();
            }
            else{
                givers.front().first-=buyers.front().first;
                ans += buyers.front().first*max(givers.front().second-buyers.front().second,buyers.front().second-givers.front().second);
                if(givers.front().first==0) givers.pop();
                buyers.pop();
            }
        }
        cout<<ans<<"\n";
    }
}