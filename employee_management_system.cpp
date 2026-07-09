#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Employee
{
    string name;
    string id;
    string address;
    string contact;
    int salary;
};

vector<Employee> employees;

void addEmployee()
{
    int n;
    cout << "How many employees you want to add: ";
    cin >> n;
    cin.ignore();

    for(int i=0;i<n;i++)
    {
        Employee e;

        cout << "\nEmployee " << employees.size()+1 << endl;

        cout << "Enter Name: ";
        getline(cin,e.name);

        cout << "Enter ID: ";
        getline(cin,e.id);

        cout << "Enter Address: ";
        getline(cin,e.address);

        cout << "Enter Contact: ";
        getline(cin,e.contact);

        cout << "Enter Salary: ";
        cin >> e.salary;
        cin.ignore();

        employees.push_back(e);
    }
}

void showEmployee()
{
    if(employees.size()==0)
    {
        cout<<"No record found\n";
        return;
    }

    for(int i=0;i<employees.size();i++)
    {
        cout<<"\nEmployee "<<i+1<<endl;
        cout<<"Name: "<<employees[i].name<<endl;
        cout<<"ID: "<<employees[i].id<<endl;
        cout<<"Address: "<<employees[i].address<<endl;
        cout<<"Contact: "<<employees[i].contact<<endl;
        cout<<"Salary: "<<employees[i].salary<<endl;
    }
}

void searchEmployee()
{
    string id;

    cout<<"Enter ID to search: ";
    cin>>id;

    for(int i = 0; i < employees.size(); i++)
    {
        if(employees[i].id == id)
        {
            cout<<"\nEmployee Found\n";
            cout<<"Name: "<<employees[i].name<<endl;
            cout<<"ID: "<<employees[i].id<<endl;
            cout<<"Address: "<<employees[i].address<<endl;
            cout<<"Contact: "<<employees[i].contact<<endl;
            cout<<"Salary: "<<employees[i].salary<<endl;
            return;
        }
    }

    cout<<"Employee not found\n";
}

void updateEmployee()
{
    string id;

    cout<<"Enter ID to update: ";
    cin>>id;
    cin.ignore();

    for(int i=0;i<employees.size();i++)
    {
        if(employees[i].id==id)
        {
            cout<<"Enter New Name: ";
            getline(cin,employees[i].name);

            cout<<"Enter New Address: ";
            getline(cin,employees[i].address);

            cout<<"Enter New Contact: ";
            getline(cin,employees[i].contact);

            cout<<"Enter New Salary: ";
            cin>>employees[i].salary;

            cout<<"Record Updated\n";
            return;
        }
    }

    cout<<"Employee not found\n";
}

void deleteEmployee()
{
    int choice;
    cout<<"1. Delete all records\n";
    cout<<"2. Delete specific record\n";
    cin>>choice;

    if(choice==1)
    {
        employees.clear();
        cout<<"All records deleted\n";
    }
    else
    {
        string id;
        cout<<"Enter ID: ";
        cin>>id;

        for(int i=0;i<employees.size();i++)
        {
            if(employees[i].id==id)
            {
                employees.erase(employees.begin()+i);
                cout<<"Record deleted\n";
                return;
            }
        }

        cout<<"Employee not found\n";
    }
}

int main()
{
    string username,password;

    cout<<"*** Employee Management System ***\n";

    cout<<"\nSign Up\n";
    cout<<"Enter Username: ";
    cin>>username;

    cout<<"Enter Password: ";
    cin>>password;

    while(true)
    {
        string u,p;

        cout<<"\nLogin\n";

        cout<<"Username: ";
        cin>>u;

        cout<<"Password: ";
        cin>>p;

        if(u==username && p==password)
        {
            char choice;

            while(true)
            {
                cout<<"\n1. Enter Data\n";
                cout<<"2. Show Data\n";
                cout<<"3. Search Data\n";
                cout<<"4. Update Data\n";
                cout<<"5. Delete Data\n";
                cout<<"6. Exit\n";

                cout<<"Enter Choice: ";
                cin>>choice;

                switch(choice)
                {
                    case '1': addEmployee(); break;
                    case '2': showEmployee(); break;
                    case '3': searchEmployee(); break;
                    case '4': updateEmployee(); break;
                    case '5': deleteEmployee(); break;
                    case '6': return 0;
                    default: cout<<"Invalid choice\n";
                }
            }
        }
        else
        {
            cout<<"Incorrect username or password\n";
        }
    }

    return 0;
}
