#include <bits/stdc++.h>
using namespace std;
class Compare{
public:
    bool operator()(vector<int>a,vector<int>b){
        if(a[1]*b[0]==b[1]*a[0])return a[2]>b[2];
        return a[1]*b[0]<b[1]*a[0];
    }
};
int main(){
    int n;
    scanf("%d",&n);
    for(int j = 0;j<n;j++){
        int x;
        scanf("%d",&x);
        priority_queue<vector<int>,vector<vector<int>>,Compare> pq;
        for(int i =0;i<x;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            pq.push({a,b,i+1});
        }
        int days = 0;
        int ans =0;
        while(!pq.empty()){
            printf("%d",pq.top()[2]);
            if(pq.size()!=1)printf(" ");
            pq.pop();
        }
        if(j != n-1)printf("\n\n");
    }
}