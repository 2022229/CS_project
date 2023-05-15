#include <iostream>
#include<string>
using namespace std;
class Person
{
    public:
    string name;
    string ms;
    int age;
    int total_bill;
    Person()
    {
      static int object_count=1;
        cout<<object_count<<endl;
        cout<<"Enter age: ";
        cin>>age;
        cout<<"Enter name: ";
        cin>>name;
        cout<<"enter mess status:";
        cin>>ms;
        object_count++;
    }
    Person(string name,int age)
    {    
      name="abc";
      age=0;
      cout<<"the data of the student no: ";
    }
    void AddMeal(int & meals,int & pr_per_meal)
  {
      meals=meals+1;
      total_bill=0;
      total_bill=meals*pr_per_meal;
      cout<<total_bill;
  }
  void Mess_bill() 
  {
    cout<<"Your mess bill is :"<<total_bill;
  }
    void Mess_in()
    {
        ms="in";
    }
    void Mess_out()
    {
        ms="out";
    }
};
/*Child class */
class Student :public Person
{
    public :
    int reg_no;
    string faculty;
    string degree;
    Student()
    {
        cout<<"Enter reg no: ";
        cin>>reg_no;
        cout<<"Enter faculty: ";
        cin>>faculty;
        if(faculty=="fcse")
        {
            cout<<"Enter program: ";
            cin>>degree;
        }       
    }
    void show_record() 
  {
    
    cout<<"name is: "<<name<<endl
        <<"age is: "<<age<<endl
        <<"reg no is: "<<reg_no<<endl
        <<endl<<"faculty is: "<<faculty<<endl; 
  }
};
class Manager
{
    public :
    string name;
    int salary;
    int id;
    Manager()
    {
        cout<<"enter manager data : "<<endl;
        cout<<"enter name: ";
        cin>>name;
        cout<<"enter salary: ";
        cin>>salary;
        cout<<"enter your id: ";
        cin>>id;
    }
    friend class Student;
};
class Servant :public Person
{ public:
string name;
int age;
int salary ;


};
class Guest: public Student ,public Servant
{
    public:
    string name;
    Guest()
    {
        cout<<"enter name :";
        cin>>name;
    }
};
int main()
{
int a,b,c,d,e,f,g,j;
int meals=0;
int pr_per_meal=500;
cout<<"no of student is: ";
cin>>a;
cout<<"enter the data of all students : "<<endl;
Student *abj;
abj=new Student[a];

Manager obj; 
while (true){
cout<<"enter 1 if you are student: ";
cout<<"enter 2 if you are manager: ";
cout<<"enter 3 if you are servant: ";
cout<<"enter 4 for logging out: "; 
cin>>d;
if (d==1)
{
    cout<<"enter your reg no: ";
    cin>>c;
    bool student=true;
    while (student)
    {
      cout<<"what you want to do: "<<endl
          <<"for info press-1: "
          <<"for adding meal press-2: " 
          <<"for checking bill press-3: "
          <<"for in your mess press-4: "
          <<"for out your mess press-5: "
          <<"for closing press-6: ";
      cin>>b;
    int i=0;
    while(i<a)
    {
       if (c==abj[i].reg_no)
       {
           switch (b)
            {
              case 1:    
              abj[i].show_record();   
              break;
              case 2:
              if(abj[i].ms=="in")
              { 
                 abj[i].AddMeal(meals,pr_per_meal);  
              }
              else
              {
                cout<<"your mess is out: "<<endl;
              }
              break;
              case 3:
              abj[i].Mess_bill();
              break;
              case 4:
              abj[i].Mess_in();
              break;
              case 5:
              abj[i].Mess_out();
              break;
              case 6:
              student=false;
              break;
            }
             i++;
         }
       if (b==6)
       {
         break;
       }
    }
    }}
    if (d == 2) 
    {
        cout << "enter your id no: ";
        cin >> e;
        if (e == obj.id)
        {
          cout <<"enter 1 for students record: " 
               <<"enter 2 for add student: "
               <<"enter 3 for remove student: ";
          cin >> f;
          switch (f)
          {
             case 1:
             cout << "enter reg no of the student: ";
             cin >> g;
             for (int i = 0; i <= a; i++)
             {
                if (g == abj[i].reg_no)
                {
                  abj[i].show_record();
                  break;
                }
             else
             {
                cout << "student not found !!! "<<endl;
                break;
             }
             i++;
      }
           break;
       case 2:
     
       case 3:
          cout << "enter reg no of the student to be deleted: ";
          cin >> g;
          int index = -1;
          for (int i = 0; i < a; i++)
          {
            if (g == abj[i].reg_no)
            {
              index = i;
              break;
            }
          }
            if (index != -1)
            {
              for (int i = index; i < a-1; i++)
              {
                abj[i] = abj[i+1];
              }
             a--;
            cout << "student with reg no " << g << " has been deleted." << endl;
            } 
            else
            {
            cout << "student with reg no " << g << " not found." << endl;
            }
            break;
       }
    }}
          if (d==4)
          {
           return 0;
     }}
           return 0;
       }
