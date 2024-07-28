#include<iostream>                                  
#include<fstream>
using namespace std;
#define max 30
struct node
{
	node *next;
	int vertex,dist;
	string cityname;

};
class graph1
{
public:
	node *head[max];
	int n;
	int visited[max];
	graph1()
	{
	for(int i=0;i<max;i++)
	{
		head[i]=new node;
		head[i]->next=NULL;
		head[i]->vertex=i;
		head[i]->cityname="";
	
	}
	}
	public:
	void readgraph();
	void display();
	void invisited();
	void dfs(int);
	
};
void graph1::readgraph()
{
	char ans;
	
	cout<<"enter no of vertices: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		node *temp=head[i];
		cout<<"\n enter city for head: ";
		cin>>temp->cityname;
		do
		{
	
		node* curr =new node;
		cout<<"\nenter the no. of vertex  connected to"<<temp->cityname;
		cin>>curr->vertex;
		cout<<"\nenter the name of city:";
		cin>>curr->cityname;
		cout<<"\nenter the distance:";
		cin>>curr->dist;
		curr->next=NULL;
		temp->next=curr;
		temp=curr;
		cout<<"\ndo you want to add more vertices :";
		cin>>ans;
		
		}while(ans=='Y'||ans=='y');
	}
}
void graph1::display()
{
	for(int i=0;i<n;i++)
	{
	
		node* temp=head[i];
		while(temp!=NULL)
		{
		cout<<temp->vertex<<":"<<temp->dist<<":"<<temp->cityname<<"-->";
		temp=temp->next;
		}
		cout<<"NULL";
		cout<<"\n";
	}

}
void graph1::invisited()
{
	for(int i=0;i<n;i++)
	{
		visited[i]=0;
	}
}
void graph1::dfs(int i)
{
	node* curr;
	visited[i]=1;
	curr=head[i];
	cout<<"\t"<<i<<":"<<curr->cityname;
	while(curr!=NULL)
	{
		if(!visited[curr->vertex])
		  dfs(curr->vertex);
		curr=curr->next;
	}
}
int main()
{
	graph1 g;
	int ch;
	while(ch!=4)
	{
		cout<<"\n1.read graph1\n2.display\n3.dfs\n4.exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:g.readgraph();
			break;
			case 2: g.display();
			break;
			case 3:g.invisited();
			g.dfs(0);
			break;
			case 4:exit(0);
		}
	}
return 0;
}





















