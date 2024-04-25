#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    vector<vector<int>> m1(b,vector<int>(a,0));
    vector<vector<int>> m2(d,vector<int>(c,0));
    for(int i= 0;i<b;i++){
        for(int j = 0;j<a;j++){
            int k;
            cin>>k;
            m1[b][a] = k;
        }
    }
    for(int i = 0;i<d;i++){
        for(int j = 0;j<c;j++){
            int k;
            cin>>k;
            m2[d][c] = k;
        }
    }
    if(d != a){
        cout<<"error";
        return 0;
    }
    vector<vector<int>> ans(b,vector<int>(d,0));
    for(int i = 0;i<a;i++){
        for(int j = 0;j<a;j++){
            for(int l = 0;)
        }
    }
}
