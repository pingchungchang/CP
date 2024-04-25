#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<float,int>> v(n);
    for(int i =0;i<n;i++){
        int a;
        float b;
        cin>>a>>b;
        v[i] = make_pair(b,a);
    }
    sort(v.begin(),v.end());
    vector<vector<pair<float,int>>> groups(8);
    for(int i =0;i<n;i++){
        int x = i%16;
        if(x == 0||x == 15)groups[0].push_back(v[i]);
        else if(x == 1||x==14)groups[1].push_back(v[i]);
        else if(x == 2||x==13)groups[2].push_back(v[i]);
        else if(x ==3||x==12)groups[3].push_back(v[i]);
        else if(x == 4||x==11)groups[4].push_back(v[i]);
        else if(x ===5||x==10)groups[5].push_back(v[i]);
        else if(x ==6||x==9)groups[6].push_back(v[i]);
        else if(x == 7||x==8)groups[7].push_back(v[i]);
    }


}
