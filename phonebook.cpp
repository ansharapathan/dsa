/*pr 2: phonebook and compare two collision handling technique:*/
#include<iostream>
using namespace std;

struct phonebook
{
 string name;
 long int no;
};
class hashing
{
phonebook ph[10];
int size;
public:
    hashing()
    {
        size=10;
        for(int i=0;i<size;i++)
        {
        ph[i].no=0;
        }
    }

  void display()
  {
    cout<<endl;
    cout<<"***phonebook***"<<endl;
    for(int i=0;i<size;i++)
    {
       cout<<i<<" : "<<ph[i].no<<": "<<ph[i].name<<endl;
    }
 }

int hash(int key)
{
 return (key%10);
}



void insert(int key,string nm)
{
    int index;
    index=hash(key);

    if(ph[index].no==0)
    {
        ph[index].no=key;
        ph[index].name=nm;

    }else
    {
        for(int i=index;i%10<size;i=(i+1)%10)
        {
            if(ph[i].no==0)
            {
                ph[i].no=key;
                ph[i].name=nm;
                break;
            }

        }
    }
}

void search(int key)
{
    int index;
    index=hash(key);
    int flag=0,count=0;
    for(int a=0;a<size;a++)
    {
        if(ph[index].no==key)
        {
            count++;
            cout<<index<<" : "<<ph[index].no<<": "<<ph[index].name<<endl;
            flag=1;
            cout<<"comparisons are:"<<count;
            break;
        }
        else {
            count++;
        index = (index + 1) % size;
        }
    }
    if(flag==0)
    {
        cout<<"\nnot found";
    }
}

void del(int key)
{
    int index;
    index=hash(key);
    int flag=0;
    for(int a=0;a<size;a++)
    {
        if(ph[index].no==key)
        {
            ph[index].no=0;
            ph[index].name=" ";

            flag=1;
            break;
        }
        else 
        index = (index + 1) % size;

    }
    if(flag==0)
    {
        cout<<"\nrecord not present";
    }
}
};
int main(){

hashing h;
int q;
long int t;
string s;
int ch;
do{
 
cout<<"\n1.insert\t2.display\t3.delete\t4.search\t5.exit"<<endl;
cout<<"enter your choice";
cin>>ch;
switch (ch){
    case 1:
     cout<<"enter no";
     cin>>t;
     cout<<"enter name:";
     cin>>s;
     h.insert(t,s);
     cout<<"inserted!\n";
     break;

     case 2:
     h.display();
    break;

    case 3:
    cout<<"enter no to delete";
     cin>>t;
     
     h.del(t);
     cout<<"deleted successfully !"<<endl;
     break;

     case 4:
     cout<<"enter no to search:";
     cin>>t;
     
     h.search(t);
     break;
}


}while(ch!=5);
return 0;

}
