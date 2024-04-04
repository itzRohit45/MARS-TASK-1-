#include <iostream>
#include<string>
using namespace std;

//for creating custom data types we can use structure or class

class customData{     //user-defined data types
    public:
           int data1;
           string data2;      //members
    private:     
           float data3;
       
    public:    
    float getdata3()    //getter(enables to access private data types everywhere)
    {
        return data3;
    }
    
    void setdata3(float data)   //setter
    {
        data3=data;
    }
};

// struct cusData{
//     int value1;
//     char value2[10];
//     float value3;
// }c1;


int main() {
    
    //cusData c1;   //if structure is used

    customData c1;    //instance of class(object/variable)

    c1.data1=90;          //accessing members via dot operator
    c1.data2="hello world";
   
    c1.setdata3(3.2); 
    
     //definition of Lambda function(inline function)
    
    [](customData c1){
        cout<<"Data 1:"<<c1.data1<<endl;
        cout<<"Data 2:"<<c1.data2<<endl;
        cout<<"Data 3:"<<c1.getdata3()<<endl;
    }(c1);
    
    //lambda function returning something
    auto useCustomData=[](customData c1){
        return c1.data1+c1.getdata3();
    };

    cout<<"Result of operation done by lambda function:"<<useCustomData(c1)<<endl;

    cout<<"The string data type in class contains:"<<[](customData c1)->string{
        return c1.data2;
    }(c1)<<endl;
    
}