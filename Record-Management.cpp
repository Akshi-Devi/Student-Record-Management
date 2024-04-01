#include <conio.h>
#include<bits/stdc++.h>
using namespace std;
class student
{
private:
    string name, roll_no, course, address, email_id, contact_no;
 
public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void Delete();
};
  
void student::menu()
{
menustart:
    int choice;
    char x;
    // system("cls");
 
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t| STUDENT MANAGEMENT SYSTEM |" << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t 1. Enter  Record " << endl;
    cout << "\t\t\t 2. Display Record" << endl;
    cout << "\t\t\t 3. Modify Record " << endl;
    cout << "\t\t\t 4. Search Record " << endl;
    cout << "\t\t\t 5. Delete Record " << endl;
    cout << "\t\t\t 6. Exit" << endl;
 
    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choose: ";
    cin >> choice;
 
    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y,N): ";
            cin >> x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
    
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        Delete();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }
    goto menustart;
}
void student::insert() 
{
    // system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- Add Student Details -------------------------------------------" << endl;
 
    cout << "\t\t\tEnter Name: ";
    cin >> name;
        while(true){
                    /* code */
                    cout << "\t\t\tEnter Roll No.: ";
                    cin >> roll_no;
 
                    if(roll_no[0]!='0' && roll_no.size()==10){
 
                        bool check_numeric=true;
 
                        for(int i=0;i<roll_no.size();i++){
                            if(! (roll_no[i]>='0' && roll_no[i]<='9') ){
                            check_numeric=false;
                            break;
                            }
                        }
 
                        if(check_numeric==true){
                            break;
                        }else{
                            cout<<"\n\t\t\tEvery Letter should be numeric.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
                    else{
                        if(roll_no[0]=='0'){
                            cout<<"\n\t\t\tFirst digit can't be zero.\n\t\t\tPlease enter correct number\n"<<endl;
                        }else{
                            cout<<"\n\t\t\tRoll number must have 10 digits.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
 
                } 
    cout << "\t\t\tEnter Course: ";
    cin >> course;
   
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    
    while(true){
        /* code */
        cout << "\t\t\tEnter Contact No: ";
        cin >> contact_no;
 
        if(contact_no[0]!='0' && contact_no.size()==10){
 
            bool check_numeric=true;
 
            for(int i=0;i<contact_no.size();i++){
                if(! (contact_no[i]>='0' && contact_no[i]<='9') ){
                   check_numeric=false;
                   break;
                }
            }
 
            if(check_numeric==true){
                break;
            }else{
                cout<<"\n\t\t\tEvery Letter should be numeric.\n\t\t\tPlease enter correct number\n"<<endl;
            }
        }
        else{
            if(contact_no[0]=='0'){
                cout<<"\n\t\t\tFirst digit can't be zero.\n\t\t\tPlease enter correct number\n"<<endl;
            }else{
                cout<<"\n\t\t\tContact number must have 10 digits.\n\t\t\tPlease enter correct number\n"<<endl;
            }
        }
 
    } 
 
    cout << "\t\t\tEnter Address: ";
    cin >> address;
    file.open("studentRecord.txt", ios::app | ios::out);
    file << name << " "<<" " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
}
 
void student::display() 
{
    // system("cls");
    fstream file;
    int total = 1;
    cout << "\n---------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------- STUDENT RECORD TABLE ----------------------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        		cout << "\n\n\nStudent No."<<"\tStudent Name\t\tRoll.NO"
			<< "\t\tCourse\t\tEmail.ID"
				"\t\t\tContact.NO"<<"\t\tAddress\n\n";
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n " << total++ ;
            cout << "\t\t" <<name ;
            cout << "\t\t\t"<< roll_no ;
            cout << "\t\t" <<course ;
            cout << "\t\t" << email_id ;
            cout << "\t\t"<< contact_no ;
            cout << "\t\t " <<address ;
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (total == 0)
        {
            cout << "\n\t\t\tNo Data Is Present...";
        }
    }getch();
    file.close();
}
void student::modify() 
{
    // system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)
 
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
               
                 while(true){
                    /* code */
                    cout << "\t\t\tEnter Roll No.: ";
                   cin >> roll_no;
 
                    if(roll_no[0]!='0' && roll_no.size()==10){
 
                        bool check_numeric=true;
 
                        for(int i=0;i<roll_no.size();i++){
                            if(! (roll_no[i]>='0' && roll_no[i]<='9') ){
                            check_numeric=false;
                            break;
                            }
                        }
 
                        if(check_numeric==true){
                            break;
                        }else{
                            cout<<"\n\t\t\tEvery Letter should be numeric.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
                    else{
                        if(roll_no[0]=='0'){
                            cout<<"\n\t\t\tFirst digit can't be zero.\n\t\t\tPlease enter correct number\n"<<endl;
                        }else{
                            cout<<"\n\t\t\tRoll number must have 10 digits.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
 
                } 
                
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
 
 
                while(true){
                    /* code */
                    cout << "\t\t\tEnter Contact No: ";
                    cin >> contact_no;
 
                    if(contact_no[0]!='0' && contact_no.size()==10){
 
                        bool check_numeric=true;
 
                        for(int i=0;i<contact_no.size();i++){
                            if(! (contact_no[i]>='0' && contact_no[i]<='9') ){
                            check_numeric=false;
                            break;
                            }
                        }
 
                        if(check_numeric==true){
                            break;
                        }else{
                            cout<<"\n\t\t\tEvery Letter should be numeric.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
                    else{
                        if(contact_no[0]=='0'){
                            cout<<"\n\t\t\tFirst digit can't be zero.\n\t\t\tPlease enter correct number\n"<<endl;
                        }else{
                            cout<<"\n\t\t\tContact number must have 10 digits.\n\t\t\tPlease enter correct number\n"<<endl;
                        }
                    }
 
                } 
 
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
 
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }getch();
}
void student::search() 
{
    // system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "--------------------------------------- Student Search Data -------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string rollno;
        cout << "\n-----------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------------- Student Search Data -------------------------------------------" << endl;
        cout << "\n Enter Roll No. of Student Which You Want to Search: ";
        cin >> rollno;
 
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\t\t\t Student Name: " << name << endl;
                cout << "\t\t\t Student Roll No.: " << roll_no << endl;
                cout << "\t\t\t Student course: " << course << endl;
                cout << "\t\t\t Student Email Id.: " << email_id << endl;
                cout << "\t\t\t Student Address: " << address << endl;
                found++;           
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tStudent Roll No. Not Found...";
        }
        file.close();
    }
    getch();
}
void student::Delete()
{
    // system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
int main()
{
    student project;
    project.menu();
    return 0;
}