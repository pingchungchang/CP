#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int z = 0;z<n;z++){
        int a,b,c;
        int out = 0;
        cin>>a>>b>>c;
        for(int i = a+1;i<b;i++){
            if(i%c != 0){
                cout<<i<<' ';
                out = 1;
            }
        }
        if(out == 0){
            cout<<"No free parking spaces.";
        }
        cout<<endl;
    }
}
