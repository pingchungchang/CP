#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    scanf("%lld",&n);
    unordered_map<long long,unordered_map<long long,unordered_map<long long,long long>>> m;
    long long biggest = 0;
    long long used = 0;
    for(long long i =0;i<n;i++){
        long long a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        vector<long long> k = {a,b,c};
        sort(k.begin(),k.end());
        if(k[0]+k[1]<=k[2])continue;
        else used++;
        vector<long long> kc = k;
        long long gcd = 1;
        while(k[0]!=0){
            k[1]-=(k[1]/k[0])*k[0];
            long long buf = k[1];
            k[1] = k[0];
            k[0] = buf;
        }
        sort(k.begin(),k.end());
        while(k[1]!=0){
            k[2] -= (k[2]/k[1])*k[1];
            long long buf = k[2];
            k[2] = k[1];
            k[1] = buf;
        }
        gcd = k[2];
        kc[0]/=gcd;
        kc[1]/=gcd;
        kc[2]/=gcd;
        if(m.count(kc[0]) == 0){
            m[kc[0]][kc[1]][kc[2]] = 0;
        }
        else if(m[kc[0]].count(kc[1]) == 0){
            m[kc[0]][kc[1]][kc[2]] = 0;
        }
        else if(m[kc[0]][kc[1]].count(kc[2]) == 0){
            m[kc[0]][kc[1]][kc[2]] = 0;
        }
        else{
            m[kc[0]][kc[1]][kc[2]] +=1;
            biggest = max(m[kc[0]][kc[1]][kc[2]],biggest);
        }
    }
    printf("%lld %lld",used,biggest);
    return 0;
}