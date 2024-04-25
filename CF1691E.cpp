#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
    ll l,r,c;
    node(ll lll,ll rrr,ll cc){
        l = lll,r = rrr,c = cc;
    }
    node(){}
};
bool cmp(node a,node b){
    if(a.l != b.l)return a.l<b.l;
    else return a.r<b.r;
}
int main(){

}
