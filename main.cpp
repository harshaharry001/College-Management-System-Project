#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Student
{
public :
    string roll_no,branch,name;
public :
    void enter_input()
    {
        cout << "Enter Student Name :";
        getline(cin,name);
        cout << "Enter Roll Number :";
        getline(cin,roll_no);
        fflush(stdin);
        cout << "Enter Branch :";
        getline(cin,branch);
        fflush(stdin);
    }
    void display()
    {
        //system("CLS");
        cout << "Display Student Records" << endl;
        cout << "Student Name : " << name << endl;
        cout << "Roll Number  : " << roll_no << endl;
        cout << "Branch       : " << branch << endl;
        //system("CLS");
    }
    bool operator ==(Student a)
    {
        if(roll_no==a.roll_no)
            return true;
        else
            return false;
    }
};

vector <Student> v;
int search_rollno(string roll,int &i);
void get_file();

void bubble_sort()
{
    Student x;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v.size()-i-1;j++)
        {
            x=v[j];
            v[j]=v[j+1];
            v[j+1]=x;
        }
    }
}

void insert_stud()
{
    int flag=1,ta;
    while(flag)
    {
        fflush(stdin);
        Student x;
        x.enter_input();
        if(search_rollno(x.roll_no,ta)==0)
            v.push_back(x);
        else
            cout << "Roll Number Already Exists!" << endl;
        cout << "Do you want to continue (0 or 1) :";
        cin >> flag;
        fflush(stdin);
    }
}

void write_file()
{
    bubble_sort();
    fstream file;
    file.open("College.txt",ios::out);
    for(int i=0;i<v.size();i++)
    {
        Student x=v[i];
        file.write((char *) &x,sizeof(class Student));
    }
    file.close();
}

int search_rollno(string roll,int &i)
{
    int ta=0;
    for(i=0;i<v.size();i++)
    {
        if(v[i].roll_no==roll)
        {
            ta=1;
            break;
        }
    }
    return ta;
}

void get_file() {
    Student x;
    int i=0;
    fstream file;
    file.open("College.txt",ios::in);
    if(file)
    {
        file.read((char *) &x,sizeof(class Student));
        while(!file.eof())
        {
            v.push_back(x);
            file.read((char *) &x,sizeof(class Student));
        }
    }
    else
        ;
    file.close();
}

int search_name(string name, vector <int> &vi)
{
    int ta=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].name==name)
        {
            ta=1;
            vi.push_back(i);
        }
    }
    return ta;
}

int search_branch(string branch, vector <int> &vj)
{
    int ta=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i].branch==branch)
        {
            ta=1;
            vj.push_back(i);
        }
    }
    return ta;
}

void search_print()
{
    int ch,i;
    string name,branch,rno;
    vector <int> vi,vj;
    poi :
    cout << "****************************" << endl;
    cout << "1. To Search Roll Number" << endl;
    cout << "2. To Search Student Name" << endl;
    cout << "3. To Search Branch" << endl;
    cout << "****************************" << endl;
    cout << "Enter your choice :";
    cin >> ch;
    switch(ch)
    {
        case 1 : cout << "Enter Roll Number :";
                 fflush(stdin);
                 getline(cin,rno);
                 if(search_rollno(rno,i)==1)
                     v[i].display();
                 else
                     cout << "Record Not Found!" << endl;
            break;
        case 2 : cout << "Enter Student Name :";
                 fflush(stdin);
                 getline(cin,name);
                 if(search_name(name,vi)==1)
                 {
                     for(int j=0;j<vi.size();j++)
                         v[vi[j]].display();
                 }

            break;
        case 3 : cout << "Enter Branch :";
                 fflush(stdin);
                 getline(cin,branch);
                 if(search_branch(branch,vj)==1)
                 {
                     for(int j=0;j<vj.size();j++)
                         v[vj[j]].display();
                 }
                 else
                     cout << "Record Not Found!" << endl;
            break;
        default : cout << "Invalid Choice" << endl;
            goto poi;
    }
}

void print()
{
    for(int i=0;i<v.size();i++)
        v[i].display();
}

void delete_stud()
{
    int i;
    string reg;
    vector <Student> :: iterator p=v.begin();
    cout << "Enter Roll Number :";
    fflush(stdin);
    getline(cin,reg);
    if(search_rollno(reg,i)==1)
    {
        Student x=v[i];
        cout << "Below Student's Data is deleted" << endl;
        x.display();
        p+=i;
        v.erase(p,p+1);
    }
}

void edit_stud()
{
    int i;
    string reg;
    vector <Student> vi;
    cout << "Enter Roll Number :";
    fflush(stdin);
    getline(cin,reg);
    if(search_rollno(reg,i)==1)
    {
        cout << "Enter New Data :";
        fflush(stdin);
        v[i].enter_input();
    }
}

void menu()
{
    cout << "***********************************" << endl;
    cout << "     College Management System     " << endl;
    cout << "***********************************" << endl;
    cout << "1. To Add Student" << endl;
    cout << "2. To Display All Students" << endl;
    cout << "3. To Remove Student" << endl;
    cout << "4. To Edit Student" << endl;
    cout << "5. To Search Student" << endl;
    cout << "0. To Exit System" << endl;
    cout << "***********************************" << endl;
}

int main()
{
    int ch;
    while(1)
    {
        menu();
        cout << "Enter your choice :";
        cin >> ch;
        switch(ch)
        {
            case 1 : insert_stud();
                break;
            case 2 : print();
                break;
            case 3 : delete_stud();
                break;
            case 4 : edit_stud();
                break;
            case 5 : search_print();
                break;
            case 0 : exit(0);
            default : cout << "Invalid Choice" << endl;
                break;
        }
    }
    return 0;
}