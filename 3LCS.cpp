#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;
    cin>>a>>b>>c;
    int s1 = a.size();
    int s2 = b.size();
    int s3 = c.size();
    vector<vector<vector<int>>> v(s1,vector<vector<int>>(s2,vector<int>(s3,0)));
    if(a[0]==b[0]&&b[0] == c[0])v[0][0][0] = 1;
    for(int i =1;i<s1;i++){
        if(v[i-1][0][0] == 1)v[i][0][0] = 1;
        else if(a[i] == b[0]&&b[0] == c[0])v[i][0][0] = 1;
    }
    for(int i =1;i<s2;i++){
        if(v[0][i-1][0] == 1)v[0][i][0] = 1;
        else if(a[0] == b[i]&&b[i] == c[0])v[0][i][0] = 1;
    }
    for(int i =1;i<s3;i++){
        if(v[0][0][i] == 1)v[0][0][i] = 1;
        else if(a[0] == b[0]&&b[0] == c[i])v[0][0][i] = 1;
    }
    for(int i =1;i<s1;i++){
        for(int j = 1;j<s2;j++){
            if(v[i-1][j][0]==1||v[i][j-1][0] == 1||(a[i]==b[j]&&b[j]==c[0]))v[i][j][0] = 1;
        }
    }
    for(int i =1;i<s2;i++){
        for(int j =1;j<s3;j++){
            if(v[0][i][j-1]==1||v[0][i-1][j] == 1||(a[0]==b[i]&&b[i]==c[j]))v[0][i][j] = 1;
        }
    }
    for(int i = 1;i<s1;i++){
        for(int j = 1;j<s3;j++){
            if(v[i][0][j-1] == 1||v[i-1][0][j] == 1||(a[i]==b[0]&&b[0]==c[j]))v[i][0][j] = 1;
        }
    }
    for(int i =1;i<s1;i++){
        for(int j =1;j<s2;j++){
            for(int k = 1;k<s3;k++){
                v[i][j][k] = max(v[i][j][k-1],v[i-1][j][k]);
                v[i][j][k] = max(v[i][j][k],v[i][j-1][k]);
                if(a[i] == b[j]&&b[j]==c[k])v[i][j][k] = max(v[i][j][k],v[i-1][j-1][k-1]+1);
            }
        }
    }
    cout<<v[s1-1][s2-1][s3-1];
}