#include<iostream>
#include<vector>
using namespace std;

int main(){
    int q=0, p=0;
    vector<string> a(3);
    vector<string> b(3);
    for (int i=0; i<3; i++)
        cin>>a[i];
    for (int i=0; i<3; i++)
        cin>>b[i];
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (a[i][j]==b[i][j]){
                a[i][j]=' ';
                b[i][j]=' ';
                q++;
            }
        }
    }
    for (int i=0; i<b.size(); i++){
        for (int j=0; j<b[i].size(); j++){
            for (int x=0; x<a.size(); x++){
                for (int z=0; z<a[x].size(); z++){
                    if (b[i][j]==a[x][z] && a[x][z]!=' '){
                        a[x][z]=' ';
                        b[i][j]=' ';
                        p++;
                    }
                }
            }
        }
    }
    cout<<q<<endl<<p<<endl;
}