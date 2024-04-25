#include <bits/stdc++.h>
using namespace std;
void change(int place,vector<int> &now,vector<int> &p){
    int k = now[place+1];
    p[now[place]] = place+1;
    p[now[place+1]] = place;
    now[place+1] = now[place];
    now[place] = k;
}
int main(){
    int n;
    cin>>n;
    vector<int> now(n,0);
    vector<int> place(n,0);
    for(int i = 0;i<n;i++){
        int k;
        cin>>k;
        now[i] = k-1;
        place[k-1] = i;
    }
    int ans = 0;
    for(int i = place.size()-1;i>=0;i--){
        while(now[i]!= i){
            change(place[i],now,place);
            ans++;
        }
    }
    printf("%d",ans);
}