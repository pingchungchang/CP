#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        int h1,h2,m1,m2,m3;
        cin>>h1>>m1>>h2>>m2>>m3;
        m1+=m3;
        if(m1>=60){
            h1+=m1/60;
            m1=m1%60;
        }
        if(h2>h1||(h2==h1&&m2>=m1))cout<<"Yes\n";
        else cout<<"No\n";
    }
}