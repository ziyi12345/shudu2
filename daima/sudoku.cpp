#include<iostream>  
#include<iomanip> 
#include <Windows.h>
#include <stdlib.h>
#include <fstream>
#include <cstdlib> 
#include <direct.h>  


using namespace std;  
   
int arr[10][10];   
int s;

bool get_arr(int i,int j)//�����ڣ�i��j��λ�ô����Դ洢������,�ҵ����򷵻�true�����򷵻�false  
{  
    if(i>9||j>9)   
        return true;//Խ�磬˵�����������ˣ����� 
  
    for(int k=1;k<=9;++k)   
    {   s=rand()%9+1;//S��������ɵģ���֤������������� 
        bool can=true; //can�������ڼ�¼����s�ܷ����(i,j)��  
        
        for( int m=1;m<i;++m)   
            if(arr[m][j]==s)  
            {  
                can=false;  
                break;  
            } // ���ͬһ���Ƿ���ֹ�����s
            
        if (can)   
            for( int n=1;n<j;++n)   
                if(arr[i][n]==s)  
                {  
                    can=false;  
                    break;   
                }// ���ͬһ���Ƿ���ֹ�����s  
                
        if(can)   
        {  
            int x=(i-1)/3;
            int y=(j-1)/3;
            for(int p=(x*3+1);p<=(x*3+3);p++)//�жϾŹ�������û���ظ����� 
            {  
                if(can==false)
                    break;  
                    
                for(int q=(y*3+1);q<=(y*3+3);q++)   
                    if(arr[p][q]==s)   
                    {  
                        can=false;  
                        break;  
                    }  
            }  
        }  
        
        if(can)   
        {  
            arr[i][j]=s;//���������� 
			 
            if(j<9)   
            {  
                if(get_arr(i,j+1))//���һ�е���һ�� 
                    return true;//  
            }  
            else  
            {  
                if(i<9)    
                {  
                    if(get_arr(i+1,1))//��ʼ����һ�� 
                        return true;
                }  
                else  
                    return true;//ȫ����ɣ����� 
   
            }  
            arr[i][j]=0;//��������Ҫ����0
        }  
    }  
    return false;//ȫ���Թ���֮�󻹲��ɹ��ͷ�����һ�� 
} 

long long myrand() 
{__asm("RDTSC");}//���������������ӵĶ��� 


void start()   
{
  srand (myrand()); // ����s�����������  
    for(int i=1;i<=9;++i)  
        for(int j=1;j<=9;++j)  
            arr[i][j]=0;//��ʼȫ����0 
   arr[1][1]=5;//ѧ��β��13�����Ե�һ��λ����5 
    get_arr(1,2) ;  //��һ�����̶ֹ������Դӵڶ�����ʼ 

}
  
   
int main(int argc, char *argv[])  
{char s[100] = {0};
int ck=0;
int check=90;
strcpy(s, _pgmptr); 
while(s[check]!='.')
check--; 
s[check+1]='t';
s[check+2]='x'; 
s[check+3]='t';

     ofstream cout(s,ios::out);
 
		 int a=0,t=0;
	 char* c; 
	 c=argv[1];
	 t=strlen(c);
	
    for(int l=0;l<t;l++)
	{if(c[l]>='9'||c[l]<='0')
	{
	cout<<"�������"<<endl;
	return 0;}
	} 
	int g=atoi(c);

	while(a<g)
  		{ 
	 	start();

	 	for(int i=1;i<=9;i++)   
    {  
        for(int j=1;j<=9;j++)  
			{
            cout<<arr[i][j]<<" "; } 
        	cout<<endl;//��������д���ļ�����ȥ�ˣ� 
  }  
	 		cout<<endl;
		
			 a++;}  

    return 0;  
}  
