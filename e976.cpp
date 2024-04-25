#include <bits/stdc++.h>
using namespace std;

int main(){
    int t,m,v;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin>>t>>m>>v){
        cout<<t<<' '<<m<<' '<<v<<". ";
        double need = (double)m/(double)v;
        if(t>=need){
            cout<<"I will make it!\n";
        }
        else cout<<"I will be late!\n";
    }
}
