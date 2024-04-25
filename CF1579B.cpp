#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int asd=0;asd<t;asd++){
        int n;
        cin>>n;
        int arr[n];
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i =0;i<n;i++){
            cin>>arr[i];
            pq.push(arr[i]);
        }
        int tri = 0;
        vector<vector<int>> ans;
        for(int i =0;i<n;i++){
            int now = pq.top();
            pq.pop();
            int c =0;
            while(arr[i]!= now){
                tri=1;
                c++;
                int k = arr[i];
                for(int j = n-1;j>=i;j--){
                    int x = arr[j];
                    arr[j] = k;
                    k = x;
                }
            }
            if(c!=0)ans.push_back({i+1,n,c});
        }
        if(tri==0)cout<<"0\n\n";
        else{
            cout<<ans.size()<<'\n';
            for(int i =0;i<ans.size();i++)cout<<ans[i][0]<<' '<<ans[i][1]<<' '<<ans[i][2]<<'\n';
        }
    }
}
