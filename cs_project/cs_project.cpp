#include<iostream>
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
      static  int object_count=1;
        cout<<object_count<<endl;
        cout<<"Ente age :";
        cin>>age;
        cout<<"Enter name :";
        cin>>name;
        object_count++;
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
    void show_record(){
    
    cout<<"name is :"<<name<<endl<<"age is :"<<age<<endl<<reg_no<<endl<<faculty<<endl;
    cout<<"reg no is :"<<reg_no<<endl<<"faculty is :"<<faculty;
    
}

};

int main(){
// Person obj;
int a;string b;int c;
cout<<"no of student is :";
cin>>a;
cout<<"enter the data of all students :"<<endl;
Student abj[a];
cout<<"what you want to do :";
cin>>b;
if (b=="sh"){
    cin>>c;
    int i=0;
    while(i<a){
    if (c==abj[i].reg_no){
        abj[i].show_record();
    }
i++;
}}
// abj.AddMeal();
    return 0;
}
