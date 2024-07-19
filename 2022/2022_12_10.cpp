
#include <fstream>
#include <iostream>
#include <stdio.h>
using namespace std;

//goal: use virtual function
//have input and output into a file
//get some pointers involved in the class

//高考类型里面有一个virtual函数，判断

//抽象类： 高考类型，包含一个虚函数表示百分比和跟average的差距
//子类们：
//ib: 33.02 out of 45
//sat 1060 out of 1600
//toefl 88 out of 120
//act 20.3 out of 36
//生成一份文件，里面包含高考类型名字，你的成绩，百分比和跟2021average的差距...
class GraduationTest {
    public:
        virtual void calculation(){};
        string studentName;
        string testName;
        float testScore;
        float dAverage;
        int totalScore;
        void getInfo(){
            cout<<"Please enter the student's name"<<endl;
            cin>>studentName;
            cout<<"Please enter the student's test Score"<<endl;
            cin>>testScore;
        }
        void openFile(){
            ofstream outfile;
            outfile.open("04_10_12_2022_result.txt",ios::app);
            outfile<<"Student name: "<<this->studentName<<endl;
            outfile<<"Test taken: "<<this->testName<<endl;
            outfile<<"Test Score: "<<this->testScore<<" out of "<<this->totalScore<<endl;
            outfile<<"Score in percentage: "<<(this->testScore/this->totalScore)*100<<"%"<<endl;
            outfile<<"Difference from average: "<<this->dAverage<<endl<<endl;
            outfile.close();
        }
        void record(){
            getInfo();
            calculation();
            openFile();
        }
};

class ib: public GraduationTest {
    public:
        void calculation(){
            this->totalScore=45;
            this->dAverage = this->testScore-33.02;
        }
};

class sat: public GraduationTest {
    public:
        void calculation(){
            this->totalScore=1600;
            this->dAverage = this->testScore-1060;
        }
};


class toefl: public GraduationTest {
    public:
        void calculation(){
            this->totalScore=120;
            this->dAverage = this->testScore-88;
        }
};

class act: public GraduationTest {
    public:
        void calculation(){
            this->totalScore=36;
            this->dAverage = this->testScore-20.3;
        }
};


void initialize(){
    ofstream outfile;
    outfile.open("04_10_12_2022_result.txt");
    outfile<<"Data collection: "<<endl<<endl<<endl;
}
void read(){
    ifstream outfile;
    string data;
    ifstream ReadF("04_10_12_2022_result.txt");
    while (getline(ReadF,data)){
        cout<<data<<endl;
    }
    ReadF.close();
}

int main(){

    /*
    int numberOfStudents;
    //ask for name, test name and score, based on this, create person according to their name and test type
    cout<<"how many students would you like to record?"<<endl;
    cin>>numberOfStudents;
    string students[numberOfStudents];
    int testType;
    for (int i=0; i<numberOfStudents; i++){
        cout<<"Enter the student's name"<<endl;
        cin>>students[i];
        cout<<"Which test did the student take? 1.ib 2. sat"<<endl;
        cin>>testType;
        string *ip = &students[i];
        //create class using these data.......!!!!!!!!!!!!!!!!!!!!!!
        switch (testType){
            case 1:
                ib *ip;
                printf("%x",*ip);
        }


        cout<<"what is the student's score?"<<endl;
    }
    */
    initialize();

    
    const char* students[4]
        = { "Zoe", "Ziyou", "Zhang", "ZhangZiYou" };
 
    // Printing Strings stored in 2D array
    for (int i = 0; i < 4; i++){   
        std::cout << students[i] << "\n";
        string hi= students[i];

        ib students[i];
        students[i].record();
    }
    


    //ib: 33.02 out of 45
    //sat 1060 out of 1600
    //toefl 88 out of 120
    //act 20.3 out of 36

    /*
    ib Ziyou;
    Ziyou.record();
    act Zoe;
    Zoe.record();
    */


    read();
}





/*
oftream 
插入
cin.getline(d输入的首地址， 读入的最大长度,/0(读完))
seekg （input stream) (seekget)
seek

e.g. fileObject.seekg( n, cur ); 找到outfil里面的n，
*/

/*
抽象类/虚函数
描述了类的行为，
virtual double getVolume() = 0;
派生函数必须重写这个虚函数
*/

/*
int *p[5]


int (*p)[3] p是指向这个数组的指针
int **p 



#include <iostream>
using namespace std;
int main(){
    char a[5];
    for(int i=0;i<=4;i++){
        a[i]=i+'0';
    }
    char *p=a;
    printf(p);
    printf("%p",*p);
    p++;
    
    cout<<p<<endl;
    cout<<*p<<endl;

   return 0;
}

#include <iostream>
using namespace std;
int main(){
    int a[5];
    for(int i=0;i<=4;i++){
        a[i]=i;
    }
    int *p=a;


    cout<<p<<endl;
    cout<<*p<<endl;
    p++;
    
    cout<<p<<endl;
    cout<<*p<<endl;

   return 0;
}

https://blog.csdn.net/Master_0_/article/details/123793762

*/

