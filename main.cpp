#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
bool isletter(char ch);
bool isdigit(char ch);
string a;
int main() 
{
	fstream in,out;
	int i=1;
	int j;
	in.open("test.txt",ios::in);
	if(in.fail())
	{
		cout<<"error"<<endl;
		exit(0);
	}
	out.open("answer.txt",ios::out);
	if(out.fail())
	{
		cout<<"error"<<endl;
		exit(0);
	}
	while(getline(in,a,'\n'))
	{
		j=0;
		char b[100];
		while(j<a.size())
		{
			if(isletter(a[j]))
			{
				int k=1;
				b[0]=a[j];
				while(isletter(a[j+1])||isdigit(a[j+1]))
				{
					b[k]=a[j+1];
					j++;
					k++;
				}
				if(strcmp(b,"const")==0||strcmp(b,"var")==0||strcmp(b,"procedure")==0||strcmp(b,"begin")==0||strcmp(b,"end")==0||strcmp(b,"if")==0||strcmp(b,"odd")==0||strcmp(b,"then")==0||strcmp(b,"call")==0||strcmp(b,"while")==0||strcmp(b,"do")==0||strcmp(b,"read")==0||strcmp(b,"write")==0||strcmp(b,"program")==0||strcmp(b,"else")==0)
					out<<b<<"是保留字"<<endl;		
				else
					out<<b<<"是标识符"<<endl;
				memset(b,'\0',sizeof(b));
			} 
			else if(isdigit(a[j]))
			{
				int k=1;
				b[0]=a[j];
				bool flag=0;
				while(isletter(a[j+1])||isdigit(a[j+1]))
				{
					b[k]=a[j+1];
					if(isletter(b[k]))
						flag=1;
					j++;
					k++;

				}		
				if(flag==0)
					out<<b<<"是常数"<<endl;
				else
					cout<<"第"<<i<<"行"<<b<<"词法错误"<<endl;
				memset(b,'\0',sizeof(b));
			} 
			else if(a[j]=='+'||a[j]=='-')
				out<<a[j]<<"是运算符"<<endl;
			else if(a[j]=='/')
			{
				if(a[j+1]=='*')
				{
					out<<a[j]<<a[j+1]<<"是界符"<<endl;
					j++;
				}
				else 
					 out<<a[j]<<"是运算符"<<endl;
			}
			else if(a[j]=='*')
			{
				if(a[j+1]=='/')
				{
					out<<a[j]<<a[j+1]<<"是界符"<<endl;
					j++;
				}
				else 
					 out<<a[j]<<"是运算符"<<endl;
			}
			else if(a[j]==';'||a[j]=='('||(a[j]==')')||(a[j]==','))
				out<<a[j]<<"是界符"<<endl;
			else if(a[j]==':')
			{
				if(a[j+1]=='=')
				{
					out<<a[j]<<a[j+1]<<"是运算符"<<endl;
					j++;
				}
				else 
					cout<<"第"<<i<<"行"<<a[j]<<"词法错误"<<endl;	 
			}
			else if(a[j]=='<')
			{
				if(a[j+1]=='='||a[j+1]=='>')
				{
					out<<a[j]<<a[j+1]<<"是运算符"<<endl;
					j++;
				}
				else 
					 out<<a[j]<<"是运算符"<<endl;
			}			
			else if(a[j]=='=')
				out<<a[j]<<"是运算符"<<endl;
			else if(a[j]=='>')
			{
				if(a[j+1]=='=')
				{
					out<<a[j]<<a[j+1]<<"是运算符"<<endl;
					j++;
				}
				else 
					 out<<a[j]<<"是运算符"<<endl;
			}
			else if(a[j]!=' ')
			{
				int k=1;
				b[0]=a[j];
				bool flag=0;
				while(!isletter(a[j+1])&&!isdigit(a[j+1])&&(a[j+1]!='-')&&(a[j+1]!='+')&&(a[j+1]!='*')&&(a[j+1]!='/')&&(a[j+1]!=';')&&(a[j+1]!=':')&&(a[j+1]!='(')&&(a[j+1]!=')')&&(a[j+1]!='<')&&(a[j+1]!='=')&&(a[j+1]!='>')&&(a[j+1]!=',')&&(a[j+1]!=' '))
				{
					b[k]=a[j+1];
					j++;
					k++;	
				}
				cout<<"第"<<i<<"行"<<b<<"词法错误"<<endl;
				memset(b,'\0',sizeof(b));
			} 
			j++;
		}
		i++;
	}
	out.close();
	in.close();
	return 0;
}
bool isletter(char ch)
{
	if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
		return true;
	else
		return false;
}
bool isdigit(char ch)
{
	if(ch>='0'&&ch<='9')
		return true;
	else
		return false;
}
