//vs 智能提示快捷键ctrl+j
#include <windows.h>  
#include <string>
#include<iostream>
#include"hacker.h"

/*
hacker.lib
添加库文件需要先点应用,再确定,否则库文件会添加失败
*/

using namespace std;	//standard:标准  使用std命名空间的原因是cout等特殊函数在c++std标准库里

#define WIDTH 100
#define HEIGHT 40

void login();
void menushow();
int menuChoice();
void attack404();
void siteEdit();
void attackRepair();
void attackRecord();
void attackDNS();
void init();
void printMiddle(string msg);

int main(){
	
	init();
	login();

	while(1){
		menushow();
		int n=menuChoice();

		switch(n){
		case 1:
			attack404();
			system("cls");
			break;
		case 2:
			siteEdit();
			system("cls");
			break;
		case 3:
			attackRepair();
			system("cls");
			break;
		case 4:
			attackRecord();
			system("cls");
			break;
		case 5:
			attackDNS();
			system("cls");
			break;
		case 6:
			return 0;
			break;
		default:
			cout<<"输入无效!"<<endl;
			system("pause");
			break;
		}
	}


	return 0;
}

void printMiddle(string msg){
	int space=(WIDTH-msg.length())/2;

	for(int i=0;i<space;i++){
		cout<<" ";
	}
	cout<<msg<<endl;
}

void init(){
	//设置终端窗口的大小  cols:列数  lines:线条(这里是高度)
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(cmd);
	//system("mode con cols=100 lines=40");
}

void login(){
	std::string name;   //char name
	std::string pwd;	//int pwd

	while(1){
		system("cls");
		std::cout<<"请输入账号:";//cout的'c'指代“字符” character:字符 character有字符;性格等意思
		std::cin>>name;			//string输入,从第一个非空白字开始,直到遇到空白字符时停止输入 空白字符指的是空格,制表符,回车

		std::cout<<"请输入密码:";
		std::cin>>pwd;

		if(name=="hack" && pwd=="123456"){
			system("cls");
			break;
		}else{
			cout<<"账号或者密码错误"<<endl;
			system("pause");
		}
	}
}

void menushow(){
	string menu[]={
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.攻击修复",
		"4.攻击记录查询",
		"5.DNS攻击",
		"6.退出"
	};
	//计算菜单项的最大长度
	int max=0;
	int menuCount=sizeof(menu)/sizeof(menu[0]);	//数组里每个元素长度是一样的
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>max){
			max=menu[i].length();
		}
	}
	//打印标题
	printMiddle("------攻击系统------");
	//打印菜单
	int space=(WIDTH-max)/2;
	for(int i=0;i<menuCount;i++){
		for(int j=0;j<space;j++){
			cout<<" ";
		}
		cout<<menu[i]<<endl;
	}

}

int menuChoice(void){
	//输入功能编号
	int n=0;
	while(1){
		cout<<"请输入选项:";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"输入无效,请重新输入"<<endl;
			system("pause");
			system("cls");
		}else{
			break;
		}
	}
	return n;
}

void attack404(){
	//int hk_404(char *id,char *response);
	char id[64];	//网站id
	char response[MAXSIZE];	//攻击返回结果

	printMiddle("-----网站404攻击-----");
	cout<<"请输入准备攻击的网站id:";
	scanf_s("%s",id,sizeof(id));
	// 发起攻击
	cout<<"正在执行404攻击..."<<endl;
	hk_404(id,response);

	//攻击结果
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void siteEdit(){
	//int hk_tamper(char *id, char *para, char *response);
	char id[64];
	string para;
	char response[MAXSIZE];

	printMiddle("-----网站篡改攻击-----");
	cout<<"请输入准备攻击网站的id:";
	scanf_s("%s",&id,sizeof(id));
	cout<<"请输入篡改内容:";
	cin>>para;
	//攻击
	cout<<"正在执行网站篡改攻击..."<<endl;
	//因为在hacker.h中参数是char*类型,所以要把C++的string类型转换成char*类型
	//先用c_str()把C++字符串转换成C的字符串,再用char*强制类型转换
	GBKToUTF8(para);	//改变编码 将本地的GBK编码转换成服务器的UTF8编码
	hk_tamper(id,(char*)para.c_str(),response);
	//攻击结果
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackRepair(){
	//int hk_restore(char *id, char *response);
	char id[64];
	char response[MAXSIZE];

	printMiddle("-----网站修复-----");
	cout<<"请输入准备修复的网站id:";
	scanf_s("%s",&id,sizeof(id));

	//网站修复
	cout<<"正在修复..."<<endl;
	hk_restore(id,response);

	//修复结果
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackRecord(){
	//int hk_record(char *id, char *response);
	char id[64];
	char response[MAXSIZE];

	printMiddle("-----攻击记录查询-----");
	cout<<"请输入需要查询攻击记录的网站id:";
	scanf_s("%s",&id,sizeof(id));

	//执行查询
	cout<<"正在查询..."<<endl;
	hk_record(id,response);

	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackDNS(){
	cout<<"DNS攻击尚未实现..."<<endl;
	system("pause");
}

