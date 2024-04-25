#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        if(a==b&&b==c&&c==d&&d==0)return 0;
        double moving = d;
        double steps = b;
        moving = steps*d/100;
        double down =c;
        double now = 0;
        int days = 0;
        while(now>=0&&now<=a){
            days++;
            now+=steps;
            if(steps>moving)steps-=moving;
            else steps=0;
            if(now>a)break;
            now-=down;
            // cout<<now<<' '<<steps<<' '<<days<<endl;
        }
        if(now>a) printf("success on day %d\n",days);
        else printf("failure on day %d\n",days);
    }
}

