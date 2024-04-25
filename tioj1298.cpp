#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int cnt = 0;
    int total[n] = {};
    for(auto &i:total){
        cin>>i;
        if(i>=0)cnt++;
        else i = -i;
    }
    sort(total,total+n);
    int sum = 0;
    for(int i = 1;i<n-1;i++)sum += total[i];
    cout<<"Average time: "<<fixed<<setprecision(3)<<sum/(float)(n-2)<<" sec(s).\n";
    cout<<"Winning rate: "<<fixed<<setprecision(3)<<100*cnt/(float)n<<" %.";

}