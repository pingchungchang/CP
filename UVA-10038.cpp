#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        vector<int> v(n,0);
        int fail = 0;
        int a,b;
        for(int i = 0;i<n;i++){
            cin>>b;
            if(i==0)a=b;
            else{
                if(abs(a-b)>n-1){
                    fail = 1;
                }
                else{
                    v[abs(a-b)] +=1;
                    if(v[abs(a-b)]>1)fail = 1;
                    a=b;
                }
            }
        }
        if(fail)cout<<"Not jolly\n";
        else cout<<"Jolly\n";
    }
}