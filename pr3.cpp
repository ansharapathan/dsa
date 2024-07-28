/*implement all the functions of a dictionary using hashing and handle collision
using chaining with or without replacement 
*/
#include <iostream>

using namespace std;

struct node
{
    string word;
    string mean;
    node *next;
};
class hashtable
{
    node *ht[26];
    int size;
    public:
        hashtable()
        {
           for (int i=0;i<26;i++)
           {
               ht[i]=new node;
               ht[i]->next=NULL;
           }
        }
   
    int hash(string word)
    {                         //97 is numeric value for 'a'
        return (word[0]-97);  //if we subtract 97 from a character between
    }                         //a-z we are mapping that character 
                             //to an index of our array between 0 and 25
                             /*The lowercase alphabet characters 'a' to 'z'
                              have ASCII values ranging from 97 to 122.
                               So, subtracting 97 from the ASCII value of the 
                               first character in a string will give you
                                a number between 0 and 25, which can be used 
                                as an index for an array or other data structure.*/
   
    void insert()
    {
        node *curr;
        string word;
        string mean;
        cout<<"enter the word\n";
        cin>>word;
        cout<<"enter the meaning\n";
        cin>>mean;
        int index=hash(word);
        curr=new node;
        curr->word=word;
        curr->mean=mean;
        curr->next=NULL;
        curr->next=ht[index]->next;
        ht[index]->next=curr;
    }
   
    void display()
    {
        node *temp;
        for(int i=0;i<26;i++)
        {
            temp=ht[i]->next;
            while(temp!=NULL)
            {
                 cout<< i << "-: word ::"<<temp->word<<"  meaning :: "<<temp->mean<<endl;
           
            temp=temp->next;
            }
         }
    }
     
    void search()
    {
        string key;
        int flag=0;
        cout<<"enter the word that you want to found\n";
        cin>>key;
        int index=hash(key);
        node*temp;
        
        temp=ht[index]->next;
        while(temp!=NULL)
        {
            if(temp->word==key)
            {
                cout<<"***********found******************\n";
                cout<< index << "-: word ::"<<temp->word<<"  meaning :: "<<temp->mean<<endl;
                flag=1;
                break;
            }
           
            temp=temp->next;
        }
        if(flag==0)
        {
            cout<<"not found"<<endl;
        }

       
    }
   
    void dlt()
    {
      
        string key;
        cout<<"enter the word that you want to delete\n";
        cin>>key;
        int index=hash(key);
        int flag=0;
        node *pre=ht[index];
        node *cur=ht[index]->next;
        while(cur!=NULL){
            if(cur->word==key)
            {
                pre->next=cur->next;
                delete cur;
                flag=1;
                cout<<"\n deleted successfully"<<endl;

            }
            pre=cur;
            cur=cur->next;
        }
        if(flag==0)
        {
            cout<<"not found";
        }
    }
};
int main()
{   int ch;
    string word;
    string mean;
    hashtable h;
    do
    {
        cout<<"enter 1: insert"<<endl;
        cout<<"enter 2: display"<<endl;
        cout<<"enter 3: search"<<endl;
        cout<<"enter 4: delete"<<endl;
        cout<<"enter your choice-:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.search();
                break;
            case 4:
                h.dlt();
               
                break;
        }
    }while(ch!=5);
    return 0;
}
