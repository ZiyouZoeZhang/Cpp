#include <iostream>


/*
list=[0,1,2,3,4,5,1]
list.max()
for i in list:
    i+=1
permutations
*/

/*
int myList[13];
int TBD=0;

int main(){
    std::cout<<"input\n";
    for (int i=0; i<=12; i++){
        std::cin>>myList[i];
    }
    for (int number=0; number<=12; number++){
        for (int comparedN=0; comparedN<=12; comparedN++){
          if (myList[number]>myList[comparedN]){
                //number and compared N switch place
                TBD=myList[comparedN];
                myList[comparedN]=myList[number];
                myList[number]=TBD;
          }
        }
    }
    //test
    for (int i=0; i<=12; i++){
        std::cout<<myList[i];
    }
}
//test run

*/


#include <vector>
//#include <string>
#include <iostream>
using namespace std;



int main(){
    string s = "ahdgwqygdwuu";
    //string s1 = "bfehwgyr3u3oj2w";
    //cout<<s+s1;
    cin>>s;
    int index=s.length();
    s[index-1]='3';
    s.erase(2,4);
    s.insert(2,"hallo");
    cout<<s;


    /*
    std::cout<<"i ran\n";
    std::vector<int>hi(10);
    for (int i=0; i<hi.size(); i++){
        std::cin>>hi[i];
    }
    hi.erase(hi.begin()+2);
    for (int i=0; i<hi.size(); i++){
        std::cout<<hi[i]<<" ";
    }
    std::cout<<"\n";
    hi.pop_back();
    for (int i=0; i<hi.size(); i++){
        std::cout<<hi[i]<<" ";
    }
    std::cout<<"\n";
    hi.push_back(10);
    for (int i=0; i<hi.size(); i++){
        std::cout<<hi[i]<<" ";
    }
    std::cout<<"\n";
    */
}

