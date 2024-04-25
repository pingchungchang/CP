#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
int n;
void solve1(){
    if(n == 3){
        cout<<"1 3 5\n9 6 4\n7 2 8";
        return;
    }
    vector<vector<int>> arr(n,vector<int>(n,0));
    int c = 1;
    for(int i = 0;i<n;i++){
        if(c>n*n)break;
        for(int j = 0;j<n;j++){
            if(c>n*n)break;
            arr[i][j] = c;
            c+=2;
        }
    }
    c = 2;
    if(n == 5)c = -14;
    else if(n == 6)c = -2;
    else if(n == 7)c = -2;
    else if(n == 8)c = 0;

    for(int i = n-1;i>=0;i--){
        if(c>n*n)break;
        for(int j = n-1;j>=0;j--){
            if(arr[i][j]>0)break;
            if(c>n*n)break;
            arr[i][j] = c;
            c+=2;
        }
    }
    c = n*n-(n*n&1);
    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            if(arr[i][j]<=0){
                arr[i][j] = c;
                c-=2;
            }
        }
    }
    for(auto &i:arr){
        for(auto &j:i)cout<<j<<' ';cout<<'\n';
    }
    return;
}
void solve2(){
    vector<int> ev,odd;
    set<int> st;
    for(int i = 1;i<=n*n;i+=6){
        odd.push_back(i);
        st.insert(i);
    }
    reverse(odd.begin(),odd.end());
    for(int i = 2;i<=n*n;i+=6){
        ev.push_back(i);
        st.insert(i);
    }
    reverse(ev.begin(),ev.end());
    for(int i = 1;i<=n*n;i++){
        if(st.find(i) != st.end())continue;
        if(i&1)odd.push_back(i);
        else ev.push_back(i);
    }
    vector<vector<int>> arr(n,vector<int>(n));
    for(int i = 0;i<n;i++){
        if(odd.empty())break;
        for(int j = 0;j<n;j++){
            if(odd.empty())break;
            arr[i][j] = odd.back();
            odd.pop_back();
        }
    }
    for(int i = n-1;i>=0;i--){
        if(ev.empty())break;
        for(int j =n-1;j>=0;j--){
            if(ev.empty())break;
            arr[i][j] = ev.back();
            ev.pop_back();
        }
    }
    for(auto &i:arr){
        for(auto &j:i)cout<<j<<' ';cout<<'\n';
    }
    return;
}
int main(){
    cin>>n;
    if(n<=8){
        solve1();
    }
    else solve2();
}

/*
n = 3:
9 1 5
3 6 4
7 2 8
1:8
3:6
5:4
7:2,8
9:6


1 3 5
9 6 4
7 2 8

3 9 1
5 4 8
7 2 6
*/
