#include<iostream>
using namespace std;
#include <iostream>
using namespace std;
class food_eaten{
    public :
    int meals=0;
    int pr_per_meal=500;

    void AddMeal(){
    meals=meals+1;
    int total_bill=meals*pr_per_meal;
    cout<<total_bill;
    }

};
class Person{
    public:
    string name;
    int age;
    Person(){
        cout<<"Ente age :";
        cin>>age;
        cout<<"Enter name :";
        cin>>name;
    }
};
class Student :public Person,public food_eaten{
    public :
    int reg_no;
    string faculty;
    string degree;
    Student(){
        cout<<"Enter reg no :";
        cin>>reg_no;
        cout<<"Enter faculty :";
        cin>>faculty;
        if(faculty=="fcse"){
            cout<<"Enter program :";
            cin>>degree;
        }
        
       
    }

};
void show_record(){
    int idn;
    cin>>idn;
    if (idn==reg_no){
        cout<<"hello";
    }
    
}
int main(){
// Person obj;
Student abj;
abj.AddMeal();
    return 0;
}
