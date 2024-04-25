#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        unordered_map<int,int> m;
        int wrong = 0;
        int biggest=0,smallest=INT_MAX;
        for(int i = 0;i<n;i++){
            int k;
            cin>>k;
            smallest = min(smallest,k);
            biggest = max(biggest,k);
            if(m.count(k) != 0){
                wrong = 1;
                break;
            }
        }
        cout<<smallest<<' '<<biggest<<' ';
        if(wrong){
            cout<<"no\n";
            continue;
        }
        else if(biggest-smallest == n-1){
            cout<<"yes\n";
            continue;
        }
        else{
            cout<<"no\n";
            continue;
        }
    }
}
