#include<bits/stdc++.h>
using namespace std;

class node
{
    public:

    string data1;
    node* next;
    string data2;

    node(string number, string name)
    {
        data1 = number;
        next = NULL;
        data2 = name;
    }    
};

void InsertContact(node* &head)
{
    string number;
    cout << "Enter the Mobile Number - "; 
    getline(cin, number);

    if(number.size() == 10)
    {
        string name;
        cout << "Enter the Name - ";
        getline(cin, name);

        if(head == NULL)
        {
            head = new node(number, name);
        }
        else
        {
            node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new node(number, name);
        }
    }
    else
    {
        cout<< "Invalid Mobile Number, Please Try again." <<endl;
        InsertContact(head);
    }
}
void ShowAllContact(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data2<<" - "<<temp->data1<<endl;
        temp = temp->next;
    }
}
void Searchbynumber(node* head)
{
    string find;
    cout<< "Enter the Mobile Number - ";
    getline(cin,find);

    if(find.size() == 10)
    {
        node* temp = head;
        while(temp != NULL)
        {
            if(temp->data1 == find)
            {
                cout<<"Mobile Number present with name - "<<temp->data2<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Mobile Number Not found"<<endl;
    }
    else
    {
        cout<< "Invalid Mobile Number, Please try again."<<endl;
        Searchbynumber(head);
    }
}
void DeleteContact(node* &head)
{
    string del;
    cout<<"Enter the Mobile Number you want to delete - ";
    getline(cin, del);

    node* todelete;
    if(del == head->data1)
    {
        todelete = head;
        head = head->next;

        cout<<"Contact with Name - "<<todelete->data2<<" has been Deleted"<<endl;
        delete todelete;
        return;
    }
    else
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            if(temp->next->data1 == del)
            {
                todelete = temp->next;
                temp->next = temp->next->next;

                cout<<"Contact with Name - "<<todelete->data2<<" has been Deleted."<<endl;
                delete todelete;
                return;
            }
            temp = temp->next;
        }
        cout<<"Entered Mobile Number is not present."<<endl;
    }
}
void EditContact(node* &head)
{
    int opt;
    cout<<"Choose one of the following options"<<endl;
    cout<<"1. Edit the Name    2. Edit the Number    3. Press Any other Key to exit."<<endl;
    cin>>opt;

    if(opt == 1)
    {
        string edit;
        cout<<"Enter the Contact Number - ";
        cin>>edit;

        node* temp = head;
        while(temp != NULL)
        {
            if(temp->data1 == edit)
            {
                string change;
                cout<<"Enter the New Name - ";
                cin>>change;

                string previous = temp->data2;
                temp->data2 = change;

                cout<<"Contact Named - "<<previous<<" has been edited with name - "<<change<<endl;
                return;
            }
            temp = temp->next;
        }
        cout<<"Entered Mobile Number is not Present."<<endl;
        EditContact(head);
    }
    else if(opt == 2)
    {
        string edit;
        cout<<"Enter the Mobile Number you want to change - ";
        cin>>edit;

        node* temp = head;
        while(temp != NULL)
        {
            if(temp->data1 == edit)
            {
                string change;
                cout<<"Enter the New Number - ";
                cin>>change;

                string previous = temp->data1;
                temp->data1 = change;
                cout<<"Mobile Number - "<<previous<<" has been changed to "<<change<<endl;
                return ;
            }
            temp = temp->next;
        }
        cout<<"Entered Mobile Number is not Present."<<endl;
        EditContact(head);
    }
    else 
    {
        return ;
    }
}

int main()
{
    node* head = NULL;

    cout<<"Telephone Directory Project"<<endl;
    cout<<"You can perform the following function to this Directory, ";
    int opt = 0;
    while(opt != 6)
    {
        cout<<"Choose one of the following option or Exit"<<endl;
        cout<<"1. Insert a Contact      2. Delete a Contact"<<endl;
        cout<<"3. Edit a Contact        4. Search a Contact"<<endl;
        cout<<"5. Show all Contacts     6. Exit"<<endl;

        cout<<"Please Enter your Option here - ";
        cin>>opt;

        switch (opt)
        {
        case 1:
            InsertContact(head);
            break;

        case 2:
            DeleteContact(head);
            break;
        
        case 3:
            EditContact(head);
            break;

        case 4:
            Searchbynumber(head);
            break;

        case 5:
            ShowAllContact(head);
            break;

        default:
            cout<<"Thanks for Using this Telephone Directory"<<endl;
            break;
        }
    }
    
    return 0;
}