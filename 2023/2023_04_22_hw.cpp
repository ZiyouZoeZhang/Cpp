//如果我旁边一圈有 有指针的，我就指向它指的地方并把 它指向的地方指向的list的地方+1
//我过我旁边没有有指针的，我就把我旁边的全部低洼指向自己，并把自己&旁边加到list里面
//我需要一个可以指向int的指针，他可以指向其他地方，或者指向一个list里面属于我的位置。

#include <iostream>
#include <vector>
using namespace std;
void process(int m,int n);

struct node{
    int value;
    int *leader = NULL;

    //perhaps write a function here which may return the adress of the int which *leader is pointing to...?
};

node land[1000][1000];
int count=0;

int main(){
    int m,n;
    int input;
    cin>>m;
    cin>>n;
    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>input;
            land[i][j].value=input;
        }
    }

    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<land[i][j].value;
        }
        cout<<endl;
    }

    for (int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if (land[i][j].value==0){
                process(i,j);
            }
        }
        cout<<endl;
    }
    return 0;
}

void process(int m,int n)
{
    //找到一个有指向的。。。然后把所有指向的都指向他
    bool found=false;
    for (int i=m-1; i<m+1; i++){
        for (int j=n-1; j<n+1; j++){
            if (land[i][j].value==0&&i!=m&&j!=n){
                if (land[i][j].leader==NULL) {
                    land[i][j].leader=&land[m][n].value;
                }
                if (land[i][j].leader!=NULL){
                    //如果旁边一圈有已经指向了的
                
                    //my goal which is basically not working........!!!!!!!!..........nfjdwiugfy
                    land[m][n].leader = ((land[i][j].leader));
                    //or
                    //*land[m][n].leader = *((land[i][j].leader));

                    //land[m][n].leader= ->value;
                    //cout<<*land[m][n].leader<<endl;
                } 
            }
        }

    }
}
