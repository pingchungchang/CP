#include <bits/stdc++.h>
using namespace std;
const int bits = 21;
const int mxn = 1<<bits;
int bit[mxn];
void modify(int p,int v){
    for(;p<mxn;p+= p&-p)bit[p] += v;
    return;
}
int getval(int p){
    int re = 0;
    for(;p>0;p -= p&-p)re += bit[p];
    return re;
}
int findpos(int val){
    int re = 0;
    for(int i = bits-1;i>=0;i--){
        if(bit[re^(1<<i)]<val){
            val -= bit[re^(1<<i)];
            re ^= (1<<i);
        }
    }
    return re+1;
}
int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n*2;i++)modify(i,1);
}