#include <iostream>
#include<string>
using namespace std;
class Person{
    public:
    string name;
    string ms;
    int age;
    Person(){
      static  int object_count=1;
        cout<<object_count<<endl;
        cout<<"Ente age :";
        cin>>age;
        cout<<"Enter name :";
        cin>>name;
        cout<<"enter mess statis :";
        cin>>ms;
        object_count++;
    }
    Person(string name,int age){
        

      name="abc";
      age=0;
    }
    
    void AddMeal(int & meals,int & pr_per_meal){
    meals=meals+1;
    int total_bill=meals*pr_per_meal;
    cout<<total_bill;
    
    }
};
class Student :public Person{
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
    
    cout<<"name is :"<<name<<endl<<"age is :"<<age<<endl;
    cout<<"reg no is :"<<reg_no<<endl<<"faculty is :"<<faculty;
    
}

};

int main(){
// Person obj;
int a;int b;int c;
int meals=0;
int pr_per_meal=500;
cout<<"no of student is :";
cin>>a;
cout<<"enter the data of all students :"<<endl;
Student abj[a];
while (true){
cout<<"what you want to do : for info press 1 : for adding meal press 2 : for checking bill press 3: for out your mess press 4: for in your mess press 5 : for closing press :7"<<endl;
cin>>b;
 int i=0;
    switch (b){
            case 1:
    cout<<"enter your reg no :";
    cin>>c;
    while(i<a){
    if (c==abj[i].reg_no){
        if(abj[i].ms=="in"){
        abj[i].show_record();   
    }
    else{
        cout<<"your mess is out :"<<endl;
    }
    }
i++;
}
break;
case 2:
cout<<"enter your reg no :";
cin>>c;
    while(i<a){
    if (c==abj[i].reg_no){
         abj[i].AddMeal(meals,pr_per_meal);
          }
i++;
}
break;
case 7:
return 0;
}

// abj.AddMeal();
    
}
 return 0;}
