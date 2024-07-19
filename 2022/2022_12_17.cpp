#include<map>
#include<iostream>

int main() {
    std::map<std::string,int> a;
    a.insert(std::make_pair("zhangsan",99));
    a.insert(std::make_pair("lisi",86));
    a.insert(std::make_pair("ziyou",87));
    a.insert(std::make_pair("scarborough",0));
    a.insert(std::make_pair("laoshi",59));
    a.insert(std::make_pair("zhangsan",61));

    a.insert(std::make_pair("b",99));
    a.insert(std::make_pair("c",86));
    a.insert(std::make_pair("d",100));
    a.insert(std::make_pair("d",0));
    a.insert(std::make_pair("d",59));
    a.insert(std::make_pair("e",61));

    a.insert(std::make_pair("f",99));
    a.insert(std::make_pair("g",86));
    a.insert(std::make_pair("h",100));
    a.insert(std::make_pair("z",0));
    a.insert(std::make_pair("i",59));
    a.insert(std::make_pair("j",61));

    //std::string yes;
    
    //std::cout<<a.find("99")->first<<std::endl;
    for (std::map<std::string,int>::iterator i=a.begin(); i!=a.end(); i++){
        //between 80 and 90
        if(i->second>80&&i->second<90){
            std::cout<<i->first<<std::endl;
            a.erase(i++);
        }
    }
    //find 100 and erase
    //a.erase(a.find("g"));

}