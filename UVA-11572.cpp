#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i = 0;i<n;i++){
        int m;
        deque<int> q;
        unordered_map<int,int> used;
        scanf("%d\n",&m);
        int ans = 0;
        for(int j = 0;j<m;j++){
            int k;
            scanf("%d",&k);
            if(used.count(k) == 0)used[k] = 0;
            if(used[k] == 0)used[k]++;
            else if(used[k]>0){
                ans = max(ans,(int)q.size());
                while(q.front()!=k){
                    used[q.front()] = 0;
                    q.pop_front();
                }
                q.pop_front();
            }
            q.push_back(k);
            if(i != n-1||j!= m-1)scanf("\n");
        }
        ans = max((int)q.size(),ans);
        printf("%d",ans);
        if(i !=n-1)printf("\n");
    }
}