#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int m;
        cin>>m;
        vector<int> v(m+1,0);
        int now = 0;
        for(int j = 1;j<=m;j++){
            string s;
            cin>>s;
            if(s == "LEFT"){
                now--;
                v[j] = -1;
            }
            else if(s == "RIGHT"){
                now++;
                v[j] = 1;
            }
            else{
                cin>>s;
                int k;
                cin>>k;
                now += v[k];
                v[j] = v[k];
            }
        }
        cout<<now<<endl;
    }
}
