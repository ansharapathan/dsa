import java.util.*;
public class prac1
	{
	public void sort(int [] arr,int n)
			{
			int gap;
			gap=(int)n/2;
			while(gap>0)
				{
				for(int i=gap;i<n;i++)
					{
						int temp=arr[i];
						int j=i;
						while(j>=gap && arr[j-gap]>temp)
						{
							arr[j]=arr[j-gap];
							j=j-gap;
						}
						arr[j]=temp; 
					}
					gap=(int)gap/2;
					
					
				}
			
			}
	public static void main(String args[])
			{
		
			Scanner sr=new Scanner(System.in);
			
			int [] arr=new int[100];
			
			int n;
			System.out.println("Enter array size: ");
			n=sr.nextInt();
			System.out.println("\nEnter array elements: ");
			
			for(int i=0;i<n;i++)
			{
				arr[i]=sr.nextInt();
			}
			
			System.out.println("\nArray before sorting: ");
			
			for(int i=0;i<n;i++)
			{
				System.out.printf(arr[i]+ " ");	
			}
			
			prac1 p=new prac1();
			p.sort(arr,n);
			
			System.out.println("\nArray after shell sorting: ");
			for(int i=0;i<n;i++)
			{
				System.out.printf(arr[i]+ " ");	
			}
			}
	}


