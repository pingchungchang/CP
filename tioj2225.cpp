#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n;
    cin>>n;
    string ss;
    string s;
    cin>>s;
    ll x = 0;
    for(auto &i:s){
        x ^= 1LL<<(i-'a');
    }
    ll arr[n];
    for(int i = 0;i<n;i++){
        cin>>ss;
        arr[i] = 0;
        for(auto &j:ss){
            arr[i] |= (1LL<<(j-'a'));
        }
    }
    ll p1 = 0,p2 = 0,p3 = 0,p4 = 0,p5 = 0;
    for(auto &i:arr){
        if((i^x) == (i|x))p1++;
        else if((i&x) == x&&i != x)p2++;
        else if((x&i) == i&&i != x)p3++;
        else p4++;
    }
    for(ll i = 0;i<(1LL<<s.size());i++){
        ll ta = 0;
        for(int j = 0;j<s.size();j++){
            if(i&(1<<j))ta ^= (1LL<<(s[j]-'a'));
        }
        ll tb = x^ta;
        int flag = 1;
        for(auto &j:arr){
            // cout<<j<<' '<<ta<<' '<<tb<<' '<<(j&ta)<<' '<<(j&tb)<<endl;
            if((j&ta) == 0);
            else if(j == ta);
            else if((j&ta) == ta&&j != ta);
            else if((j&ta) == j&&j != ta);
            else{
                flag = 0;
                break;
            }
            if((j&tb) == 0);
            else if(j == tb);
            else if((j&tb) == tb&&j != tb);
            else if((j&tb) == j&&j != tb);
            else{
                flag = 0;
                break;
            }
        }
        if(flag != 0)p5++;
        // cout<<ta<<' '<<tb<<' '<<flag<<endl;
    }
    cout<<p1<<' '<<p2<<' '<<p3<<' '<<p4<<' '<<p5;
}