#include <iostream>

using namespace std;

int main(){
    int h1, h2, m1, m2;
    int ans;
    while(cin>>h1>>m1>>h2>>m2){
        ans = 0;
        if(h1==0&&h2==0&&m1==0&&m2==0){
            break;
        }
        if(m2-m1<=0){
            ans += m2 + 60 - m1;
            h2 -= 1;
        }
        else{
            ans += m2 - m1;
        }
        if(h2>=h1)
            ans += 60 * (h2 - h1);
        else
            ans += 60 * (24 + h2 - h1);
        cout<<ans<<endl;
    }
}
