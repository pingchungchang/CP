#include <iostream>
#include <string>
#include <vector>
using namespace std;
class subject{
public:
    int time;
    string name;
};
int main(){
    int N;
    cin>>N;
    for(int i =0;i<N;i++){
        bool found = false;
        int k;
        cin>>k;
        vector<subject> v;
        for(int j =0;j<k;j++){
            int time;
            string s;
            cin>>s>>time;
            subject a;
            a.time = time;
            a.name = s;
            v.push_back(a);
        }
        string str;
        int time1;
        cin>>time1>>str;
        cout << "Case " << i + 1 << ": ";
        for(int j = 0;j<v.size();j++){
            if(v[j].name==str){
                found = true;
                if(v[j].time<=time1){
                    cout<<"Yesss\n";
                }
                else if(v[j].time <=time1+5){
                    cout<<"Late\n";
                }
                else{
                    cout<<"Do your own homework!\n";
                }
            }
        }
        if (found == false){
            cout << "Do your own homework!\n";
        }
    }
}
