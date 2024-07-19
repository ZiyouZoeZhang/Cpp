#include <iostream>
#include <string>
using namespace std;


int main(){
    cout<<"I came in"<<endl;

    int inside=0, outside=0;

    for (int i=0; i<5; i++){
        int xPo=rand() %101  -50;
        int yPo=rand() %101  -50;

        cout<<xPo<<endl;
        cout<<yPo<<endl;
        int value = (xPo)^2+(yPo)^2;
        if (value<=2500){
            inside++;
        } else {
            outside++;
        }
    }



    cout<<(inside)<<endl;
    //long double solution=(inside/10000000)/0.25;
    //printf("%Lf",solution);


    return 0;
}
