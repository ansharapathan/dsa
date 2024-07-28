

#include<iostream>
#define max 20
using namespace std;

class heap
{
    private:
        int a[max];
        int n;
       
    public:
   
        void reheapdown(int i)
        {
            int t,j;
            while((2*i)+1<n)
            {
                j=(2*i)+1;
                if(j+1<n && a[j+1]>a[j])
                    j=j+1;
                if(a[i]>a[j])
                    break;
                else
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                    i=j;
                }
            }
        }
       
        void builtheap()
        {
            for(int i=(n-2)/2;i>=0;i--)
                reheapdown(i);
        }
       
       
       
        void heapsort()
        {
            int t;
        
            while(n>0)
            {
                t=a[0];
                a[0]=a[n-1];
                a[n-1]=t;
                n--;
                reheapdown(0);
            }
        }
       
        void read()
        {
            cout<<"\nENTER THE NO. OF STUDENTS:";
            cin>>n;
            cout<<"\nENTER THE MARKS:";
            for(int i=0;i<n;i++)
                cin>>a[i];
        }
       
        void dis()
        {
            cout<<a[0];
        }
};

int main()
{
    heap h;
    h.read();
    h.builtheap();
    cout<<"\nHIGHEST MARKS:";
    h.dis();
    h.heapsort();
     cout<<"\nLOWEST MARKS:";
    h.dis();
}