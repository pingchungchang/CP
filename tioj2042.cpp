#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin>>k>>n;
    if(k==0){
        int c = 0;
        for(int i =0;i<10;i++){
            for(int j =0;j<10;j++){
                for(int k =0;k<10;k++){
                    if(i+j!=k){
                        c++;
                        cout<<i<<j<<k;
                        if(c!=n)cout<<'\n';
                        else return 0;
                    }
                }
            }
        }
    }
    else if(k==1){
        int c = 0;
        for(int i =0;i<=90;i+=10){
            for(int k =0;k<10;k++){
                c++;
                cout<<i<<k<<i+k;
                if(c!=n)cout<<'\n';
                else return 0;
            }
        }
        for(int i =0;i<10;i++){
            for(int j =0;j<=90;j+=10){
                c++;
                cout<<i<<j<<i+j;
                if(c!= n)cout<<'\n';
                else return 0;
            }
        }
    }
    else{
        int c = 0;
        for(int i =1;i<10;i++){
            string a;
            string b;
            for(int j =1;j<10;j++){
                a+= to_string(i);
                b=a;
                for(int k =j+1;k<10;k++){
                    c++;
                    b+=to_string(i);
                    cout<<a<<b<<stoi(a)+stoi(b);
                    if(c != n)cout<<'\n';
                    else return 0;
                }
            }
        }
    }
}
