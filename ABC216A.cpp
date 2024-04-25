#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    scanf("%d.%d",&x,&y);
    if(y<=2)cout<<x<<'-';
    else if(y<=6)cout<<x;
    else cout<<x<<'+';
}
