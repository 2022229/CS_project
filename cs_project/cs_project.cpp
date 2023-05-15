#include <iostream>
#include <string>
using namespace std;

/* Parent class */
class Person
{
public:
    string name;
    int age;
    string ms;
    int total_bill;

    /* Class constructor */
    Person()
    {
        static int object_count = 1;
        cout << object_count << endl;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter name: ";
        cin >> name;
        object_count++;
    }

    /* Add meal function */
    void addMeal(int &meals, int &pr_per_meal)
    {
        meals = meals + 1;
        total_bill = meals * pr_per_meal;
        cout << total_bill << endl;
    }

    /* Mess bill function */
    void Mess_bill()
    {
        cout << " mess bill is: " << total_bill << endl;
    }

    /* Mess bill in function */
    void Mess_in()
    {
        ms = "in";
        cout << "Your mess is in now.";
    }

    /* Mess bill out function */
    void Mess_out()
    {
        ms = "out";
        cout << "Your mess is out now.";
    }
};

/* Child class */
class Student : public Person
{
public:
    int reg_no;
    string faculty;
    string degree;

    /* Constructor */
    Student()
    {
        cout << "Enter reg no: ";
        cin >> reg_no;
        cout << "Enter mess status: ";
        cin >> ms;
        cout << "Enter faculty: ";
        cin >> faculty;
        if (faculty == "fcse")
        {
            cout << "Enter program: ";
            cin >> degree;
        }
    }

    /* Show record function */
    void show_record()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Reg No: " << reg_no << endl;
        cout << "Faculty: " << faculty << endl;
    }
};

/* Class Manager */
class Manager
{
public:
    string name;
    int salary;
    int id;

    /* Constructor */
    Manager()
    {
        cout << "Enter manager data" << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter your ID: ";
        cin >> id;
    }

    /* Friend function */
    friend class Student;
    friend class Servant;
};

/* Second child class */
class Servant
{
public:
    string name;
    int total_salary;
    int idn;
    int salary;

    /* Constructor */
    Servant()
    {
        cout << "Enter servant data" << endl;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> idn;
        total_salary = 0;
        salary = 0;
    }

    /* Show function */
    void show()
    {
        cout << "name is: " << name << endl;
        cout << "salary: " << salary << endl;
        cout << "ID: " << idn << endl;
    }

    void addSalary(int &sal_per_day)
    {
        salary += sal_per_day;
        total_salary += salary;
        cout << "Attendance marked and salary added." << endl;
        cout << "Total salary: " << total_salary << endl;
    }

    /* Friend class */
    friend class Student;
};

/* Multiple Inheritance */
class Guest : public Student, public Servant
{
public:
    string name;

    /* Constructor */
    Guest()
    {
        cout << "Enter name: ";
        cin >> name;
    }
};

/* Main function */
int main()
{
    int no_of_students, no_of_servants;
    int meals = 0;
    int pr_per_meal = 500;
    int sal_per_day = 1000;
    int mgn_ser;

    cout << "Number of students: ";
    cin >> no_of_students;

    cout << "Enter the data of all students: " << endl;
    Student *students = new Student[no_of_students];

    Manager manager;

    cout << "Enter the number of servants: ";
    cin >> no_of_servants;

    Servant *servants = new Servant[no_of_servants];

    while (true)
    {
        int choice;
        cout << "Enter 1 if you are a student" << endl;
        cout << "Enter 2 if you are a manager" << endl;
        cout << "Enter 3 if you are a servant" << endl;
        cout << "Enter 4 to log out" << endl;
        cin >> choice;

        if (choice == 1)
        {
            int reg_no;
            cout << "Enter your reg no: ";
            cin >> reg_no;

            for (int i = 0; i < no_of_students; i++)
            {
                if (reg_no == students[i].reg_no)
                {
                    while (true)
                    {
                        int student_choice;
                        cout << "What do you want to do?" << endl;
                        cout << "1. Info" << endl;
                        cout << "2. Add Meal" << endl;
                        cout << "3. Check Bill" << endl;
                        cout << "4. In Your Mess" << endl;
                        cout << "5. Out Your Mess" << endl;
                        cout << "6. Close" << endl;
                        cin >> student_choice;

                        switch (student_choice)
                        {
                            case 1:
                                students[i].show_record();
                                break;
                            case 2:
                                if (students[i].ms == "in")
                                {
                                    students[i].addMeal(meals, pr_per_meal);
                                }
                                else
                                {
                                    cout << "Your mess is out" << endl;
                                }
                                break;
                            case 3:
                                students[i].Mess_bill();
                                break;
                            case 4:
                                students[i].Mess_in();
                                break;
                            case 5:
                                students[i].Mess_out();
                                break;
                            case 6:
                                goto end_loop;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }
                    }
                }
            }

            cout << "Student not found!" << endl;
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter your ID number: ";
            cin >> id;

            if (id == manager.id)
            {
                while (true)
                {
                    int manager_choice;
                    cout << "1. Students Record" << endl;
                    cout << "2. servant record " << endl;
                    cout << "3. Remove Student" << endl;
                    cout << "4. Close" << endl;
                    cin >> manager_choice;

                    switch (manager_choice)
                    {
                        case 1:
                            {
                                int reg_no;
                                cout << "Enter the reg no of the student: ";
                                cin >> reg_no;

                                bool found = false;
                                for (int i = 0; i < no_of_students; i++)
                                {
                                    if (reg_no == students[i].reg_no)
                                    {                                        students[i].show_record();
                                        found = true;
                                        break;
                                    }
                                }

                                if (!found)
                                {
                                    cout << "Student not found!" << endl;
                                }
                            }
                            break;
                        case 2:
                        cout<<"enter servant id"<<endl;
                        cin>>mgn_ser;
                        for (int i=0;i<no_of_servants;i++){
                            if (servants[i].idn==mgn_ser){
                                servants[i].show();
                            }
                        }
                        
                        case 3:
                            {
                                int reg_no;
                                cout << "Enter the reg no of the student to remove: ";
                                cin >> reg_no;

                                bool found = false;
                                for (int i = 0; i < no_of_students; i++)
                                {
                                    if (reg_no == students[i].reg_no)
                                    {
                                        for (int j = i; j < no_of_students - 1; j++)
                                        {
                                            students[j] = students[j + 1];
                                        }

                                        found = true;
                                        break;
                                    }
                                }

                                if (found)
                                {
                                    no_of_students--;
                                    cout << "Student removed successfully!" << endl;
                                }
                                else
                                {
                                    cout << "Student not found!" << endl;
                                }
                            }
                            break;
                        case 4:
                            goto end_loop;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                            break;
                    }
                }
            }
            else
            {
                cout << "Manager not found!" << endl;
            }
        }
        else if (choice == 3)
        {
            int idn;
            cout << "Enter your ID number: ";
            cin >> idn;

            for (int i = 0; i < no_of_servants; i++)
            {
                if (idn == servants[i].idn)
                {
                    while (true)
                    {
                        int servant_choice;
                        cout << "What do you want to do?" << endl;
                        cout << "1. Info" << endl;
                        cout << "2. Add Salary" << endl;
                        cout << "3. Close" << endl;
                        cin >> servant_choice;

                        switch (servant_choice)
                        {
                            case 1:
                                servants[i].show();
                                break;
                            case 2:
                                servants[i].addSalary(sal_per_day);
                                break;
                            case 3:
                                goto end_loop;
                                break;
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                                break;
                        }
                    }
                }
            }

            cout << "Servant not found!" << endl;
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    end_loop:
    delete[] students;
    delete[] servants;

    return 0;
}
