//vs ������ʾ��ݼ�ctrl+j
#include <windows.h>  
#include <string>
#include<iostream>
#include"hacker.h"

/*
hacker.lib
��ӿ��ļ���Ҫ�ȵ�Ӧ��,��ȷ��,������ļ������ʧ��
*/

using namespace std;	//standard:��׼  ʹ��std�����ռ��ԭ����cout�����⺯����c++std��׼����

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
			cout<<"������Ч!"<<endl;
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
	//�����ն˴��ڵĴ�С  cols:����  lines:����(�����Ǹ߶�)
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
		std::cout<<"�������˺�:";//cout��'c'ָ�����ַ��� character:�ַ� character���ַ�;�Ը����˼
		std::cin>>name;			//string����,�ӵ�һ���ǿհ��ֿ�ʼ,ֱ�������հ��ַ�ʱֹͣ���� �հ��ַ�ָ���ǿո�,�Ʊ��,�س�

		std::cout<<"����������:";
		std::cin>>pwd;

		if(name=="hack" && pwd=="123456"){
			system("cls");
			break;
		}else{
			cout<<"�˺Ż����������"<<endl;
			system("pause");
		}
	}
}

void menushow(){
	string menu[]={
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.�����޸�",
		"4.������¼��ѯ",
		"5.DNS����",
		"6.�˳�"
	};
	//����˵������󳤶�
	int max=0;
	int menuCount=sizeof(menu)/sizeof(menu[0]);	//������ÿ��Ԫ�س�����һ����
	for(int i=0;i<menuCount;i++){
		if(menu[i].length()>max){
			max=menu[i].length();
		}
	}
	//��ӡ����
	printMiddle("------����ϵͳ------");
	//��ӡ�˵�
	int space=(WIDTH-max)/2;
	for(int i=0;i<menuCount;i++){
		for(int j=0;j<space;j++){
			cout<<" ";
		}
		cout<<menu[i]<<endl;
	}

}

int menuChoice(void){
	//���빦�ܱ��
	int n=0;
	while(1){
		cout<<"������ѡ��:";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"������Ч,����������"<<endl;
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
	char id[64];	//��վid
	char response[MAXSIZE];	//�������ؽ��

	printMiddle("-----��վ404����-----");
	cout<<"������׼����������վid:";
	scanf_s("%s",id,sizeof(id));
	// ���𹥻�
	cout<<"����ִ��404����..."<<endl;
	hk_404(id,response);

	//�������
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void siteEdit(){
	//int hk_tamper(char *id, char *para, char *response);
	char id[64];
	string para;
	char response[MAXSIZE];

	printMiddle("-----��վ�۸Ĺ���-----");
	cout<<"������׼��������վ��id:";
	scanf_s("%s",&id,sizeof(id));
	cout<<"������۸�����:";
	cin>>para;
	//����
	cout<<"����ִ����վ�۸Ĺ���..."<<endl;
	//��Ϊ��hacker.h�в�����char*����,����Ҫ��C++��string����ת����char*����
	//����c_str()��C++�ַ���ת����C���ַ���,����char*ǿ������ת��
	GBKToUTF8(para);	//�ı���� �����ص�GBK����ת���ɷ�������UTF8����
	hk_tamper(id,(char*)para.c_str(),response);
	//�������
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackRepair(){
	//int hk_restore(char *id, char *response);
	char id[64];
	char response[MAXSIZE];

	printMiddle("-----��վ�޸�-----");
	cout<<"������׼���޸�����վid:";
	scanf_s("%s",&id,sizeof(id));

	//��վ�޸�
	cout<<"�����޸�..."<<endl;
	hk_restore(id,response);

	//�޸����
	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackRecord(){
	//int hk_record(char *id, char *response);
	char id[64];
	char response[MAXSIZE];

	printMiddle("-----������¼��ѯ-----");
	cout<<"��������Ҫ��ѯ������¼����վid:";
	scanf_s("%s",&id,sizeof(id));

	//ִ�в�ѯ
	cout<<"���ڲ�ѯ..."<<endl;
	hk_record(id,response);

	string retStr=UTF8ToGBK(response);
	cout<<retStr<<endl;

	system("pause");
}

void attackDNS(){
	cout<<"DNS������δʵ��..."<<endl;
	system("pause");
}

