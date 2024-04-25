#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(pair<int,int> a,pair<int,int> b){
        return max(a.first+b.first+b.second,a.first+a.second)>max(a.first+a.second+b.first,b.first+b.second);
    }
};
int main(){
    int n;
    scanf("%d",&n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> pq;
    for(int i =0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        pq.push(make_pair(a,b));
    }
    int ans = 0;
    int wt = 0;
    while(!pq.empty()){
        pair<int,int> now = pq.top();
        pq.pop();
        wt+= now.first;
        ans = max(ans,wt+now.second);
    }
    cout<<ans;
}
