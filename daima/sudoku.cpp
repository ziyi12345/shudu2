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
int test[10];
bool get_arr(int i,int j)//搜索第（i，j）位置处可以存储的数字,找到解则返回true，否则返回false  
{  
    if(i>9||j>9)   
        return true;//越界，说明数独填完了，结束 
  
    for(int k=1;k<=9;++k)   
    {   s=rand()%9+1;//S是随机生成的，保证了数独的随机性 
        bool can=true; //can变量用于记录数字s能否放在(i,j)处  
       	for(int ts=1;ts<k;ts++)
		{if(test[ts]==0) 
			{
			test[ts]==s; 
			break;
			}else if(test[ts]<s)
				continue;
			else if(test[ts]>s)
					{
						for(int ts2=k+1;ts2>ts;ts2--)
							{test[ts2]=test[ts2-1];}
						test[ts]=s;	
						break;
					}
		else if (test[ts]==s)
			{do
				{s++;
				ts++;				}
			while(test[ts]==s);
			if(test[ts]==0)
				{
				test[ts]=s;	
				break;}
			else 
				{
				for(int ts3=k+1;ts3>ts;ts3--)
					{test[ts3]=test[ts3-1];}
					test[ts]=s;
					break;
				}
		 	} 
		}
        for( int m=1;m<i;++m)   
            if(arr[m][j]==s)  
            {  
                can=false;  
                break;  
            } // 检查同一列是否出现过数字s
            
        if (can)   
            for( int n=1;n<j;++n)   
                if(arr[i][n]==s)  
                {  
                    can=false;  
                    break;   
                }// 检查同一行是否出现过数字s  
                
        if(can)   
        {  
            int x=(i-1)/3;
            int y=(j-1)/3;
            for(int p=(x*3+1);p<=(x*3+3);p++)//判断九宫格中有没有重复填入 
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
            arr[i][j]=s;//将数字填入 
				  for(int k2=1;k2<=9;k2++)
            		test[k2]=0; 
            if(j<9)   
            {  
                if(get_arr(i,j+1))//填第一行的下一列 
                    return true;//  
            }  
            else  
            {  
                if(i<9)    
                {  
                    if(get_arr(i+1,1))//开始填下一行 
                        return true;
                }  
                else  
                    return true;//全部完成，结束 
   
            }  
            arr[i][j]=0;//不能填入要重置0
       for(int k2=1;k2<=9;k2++)
            test[k2]=0; }  
    }  
    return false;//全部试过了之后还不成功就返回上一步 
} 

long long myrand() 
{__asm("RDTSC");}//用来生成生成种子的东西 


void start()   
{
  srand (myrand()); // 产生s的随机数种子  
    for(int i=1;i<=9;++i)  
        for(int j=1;j<=9;++j)  
            arr[i][j]=0;//初始全部置0 
   arr[1][1]=5;//学号尾数13，所以第一个位置是5 
    get_arr(1,2) ;  //第一个数字固定了所以从第二个开始 

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
	 c=argv[2];
	 t=strlen(c);
	
    for(int l=0;l<t;l++)
	{if(c[l]>'9'||c[l]<'0')
	{
	cout<<"输出错误"<<endl;
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
        	cout<<endl;//输出结果（写到文件里面去了） 
  }  
	 		cout<<endl;
		
			 a++;}  

    return 0;  
}  
