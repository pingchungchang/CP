#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    priority_queue<int,vector<int>,less<int>> biggest;
    priority_queue<int,vector<int>,greater<int>> smallest;
    unordered_map<int,int> m;
    while(scanf("%d",&n)!= EOF){
        if(n ==1){
            int k;
            scanf(" %d",&k);
            biggest.push(k);
            smallest.push(k);
            if(m.count(k) == 0)m[k] = 0;
            m[k]++;
        }
        else if(n == 2){
            while(m[biggest.top()]<=0)biggest.pop();
            printf("%d\n",biggest.top());
            m[biggest.top()]--;
            biggest.pop();
        }
        else{
            while(m[smallest.top()]<=0)smallest.pop();
            printf("%d\n",smallest.top());
            m[smallest.top()]--;
            smallest.pop();
        }
        scanf("\n");
    }
}