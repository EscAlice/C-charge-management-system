#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#define N 300
struct student
{
	char num[10];
	char name[11];
	int money;
	time_t start;
	time_t end;
};
void print();
void creat();
void mystart();
void myend();
void add();
void del();
void addmoney();
void search();
 main()                                                                       //       0
{
	char choice='\0',judge='\0';
	do{
		print();
		choice=getch();
		switch(choice)
		{
			case '1':creat();break;
			case '2':mystart();break;
			case '3':myend();break;
			case '4':add();break;
			case '5':del();break;
			case '6':addmoney();break;
			case '7':search();break;
			case '0':printf("��лʹ�ñ�������������˳����������������");exit(0);
			default :printf("�Ƿ����룡\n");break;
		}
		printf("\n�Ƿ񷵻����˵���Y/N����\n");
		do
		{
			judge=getch();
		}while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');

	}while(judge=='Y'||judge=='y');
}
void print()
{
	system("cls");
	printf("\t\t................................\n");
	printf("\t\t.    ������ѡ����(0~7):      .\n");
	printf("\t\t................................\n");
	printf("\t\t.    1���������ϻ�����         .\n");
	printf("\t\t.    2������ʼ�ϻ�             .\n");
	printf("\t\t.    3�����뿪����             .\n");
	printf("\t\t.    4��������µ���           .\n");
	printf("\t\t.    5����ע���ɵ���           .\n");
	printf("\t\t.    6������Ǯ                 .\n");
	printf("\t\t.    7������ʾ�����û���Ϣ     .\n");
	printf("\t\t.    0�����˳�ϵͳ             .\n");
	printf("\t\t................................\n");
}
void creat()                                                                     //        1
{
	struct student stu[30],*tu=stu;
	int i=0;
	FILE *fp=NULL;
	char judge='\0';
	system("cls");
	if((fp=fopen("duli16.3.dat","w"))==NULL){
        printf("Can not open file duli16.3.dat!\n");
        exit(0);
	}
	else
	{
		do{
			printf("������ѧ�ţ�");
			scanf("%s",tu->num);
			printf("���������֣�");
			scanf("%s",tu->name);
			printf("��ֵ��");
			scanf("%d",&tu->money);
			tu->start=0;
			tu->end=0;
			fprintf(fp,"%s %s %d %d %d\n",tu->num,tu->name,tu->money,tu->start,tu->end);
			tu++;
			i++;
			printf("\n�Ƿ���Ҫ����ע�᣿��Y/N��\n");
			do{
			judge=getch();
		}while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	}while(judge=='Y'||judge=='y');

	}
	fclose(fp);
}
void mystart()                                                                          //              2
{
	struct student stu[30]={0};
	int j=0,i=0,k=-1;
	char s[10];
	FILE *fp=NULL;
	printf("�������ϻ�ѧ�ţ�");
	scanf("%s",s);
	if((fp=fopen("duli16.3.dat","r"))==NULL)
	printf("��ѯ������ѧ��");
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d\n",stu[j].num,stu[j].name,&stu[j].money,&stu[j].start,&stu[j].end);
		j++;
	}
	fclose(fp);
	printf("\n");
	for(i=0;i<j;i++)
	{
		if(strcmp(stu[i].num,s)==0){
		k=i;
		break;}
	}
	if(k==-1)
	{
		
		printf("\n��ѯ������ѧ��,����������");
		mystart();
	}
	else if(stu[k].money>=6)
	{
		time(&stu[k].start);
		printf("�ϻ��ɹ�����ӭʹ�ã�\n");
		printf("ѧ�ţ�%s  ������%s  ��%d\n",stu[k].num,stu[k].name,stu[k].money);
		fp=fopen("duli16.3.dat","r+");
		for(i=0;i<j;i++)
        fprintf(fp,"%s %s %d %d %d\n",stu[i].num,stu[i].name,stu[i].money,stu[i].start,stu[i].end);
    fclose(fp);
	}

	else printf("\n���㣬���ֵ��");
}
void myend()                                                                         //              3
{
	struct student stu[30]={0};
	int dif;
	int minute,hour,second;
	int usemoney;
	int j=0,i=0,k=-1;
	char s[10];
	FILE *fp=NULL;
	printf("�������»�ѧ�ţ�");
	scanf("%s",s);
	if((fp=fopen("duli16.3.dat","r"))==NULL)
	printf("��ѯ������ѧ��");
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d\n",stu[j].num,stu[j].name,&stu[j].money,&stu[j].start,&stu[j].end);
		j++;
	}
	fclose(fp);
	printf("\n");
	for(i=0;i<j;i++)
	{
		if(strcmp(stu[i].num,s)==0){
		k=i;
		break;}
	}
	if(k==-1)
	{
		system("cls");
		printf("\n��ѯ������ѧ��,����������");
		mystart();
	}
	else
	{
	time(&stu[k].end);
	printf("�»��ɹ�����ӭ�´�ʹ�á�\n");
	dif=stu[k].end-stu[k].start;
	hour=dif/3600;
    minute=dif%3600/60;
    second=dif%60;
    if(second>0){
        minute++;
        second=0;
    }
    if(minute>30)
    {
        hour++;
        minute=0;
    }
    else if(minute>0)
        minute=30;
	usemoney=hour*2+minute*1/30;
	stu[k].money=stu[k].money-usemoney;
	printf("ѧ�ţ�%s  ������%s  ��%d\n",stu[k].num,stu[k].name,stu[k].money);
	fp=fopen("duli16.3.dat","r+");
	for(i=0;i<j;i++)
        fprintf(fp,"%s %s %d %d %d\n",stu[i].num,stu[i].name,stu[i].money,stu[i].start,stu[i].end);
    fclose(fp);
	}
}
void add()                                                                            //              4
{
    struct student stu[30],st[30],*tu=stu;                                 //st��ȡ�ļ����ݣ�stu��ȡ������¼
    int i=0,j=0,k=0;
    FILE *fp=NULL;
	system("cls");
    char judge='Y',num[10];
	fp=fopen("duli16.3.dat","a+");
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d\n",st[j].num,st[j].name,&st[j].money,&st[j].start,&st[j].end);
		j++;
	}
	while(judge=='Y'||judge=='y')
	{
		system("cls");
	do
	{
		printf("��������Ҫ��ӵ�ѧ�ţ�");
		scanf("%s",num);
		for(i=0;i<j;i++)
			if(strcmp(st[i].num,num)==0){
				i=1;
				system("cls");
				printf("��ѧ�Ŵ��ڣ�������ע�ᣡ\n");
				break;
			    }
	}while(i==1);
	strcpy(stu->num,num);
	printf("���������֣�");
	scanf("%s",stu->name);
	printf("��ֵ��");
	scanf("%d",&stu->money);
	stu->start=0;
	stu->end=0;
	fprintf(fp,"%s %s %d %d %d\n",stu->num,stu->name,stu->money,stu->start,stu->end);
	k++;
	printf("\n�Ƿ���Ҫ����ע�᣿��Y/N��\n");
	do{
		judge=getch();
	}while(judge!='Y'&&judge!='y'&&judge!='N'&&judge!='n');
	}
	fclose(fp);
}
void del()                                                                              //        5
{
    struct student stu[30]={0};
    int j=0,k=-1,i=0;
    char s[10];
    FILE *fp=NULL;
    printf("������Ҫɾ����ѧ�ţ�");
    scanf("%s",s);
    if((fp=fopen("duli16.3.dat","r"))==NULL)
	{
		printf("��ѯ������ѧ��");
	}
	while(feof(fp)==0)
    {
        fscanf(fp,"%s %s %d %d %d\n",stu[j].num,stu[j].name,&stu[j].money,&stu[j].start,&stu[j].end);
		j++;
    }
    fclose(fp);
    printf("\n");
    for(i=0;i<j;i++)
    {
        if(strcmp(stu[i].num,s)==0){
		k=i;
		break;}
	}
	if(k==-1)
	{
		system("cls");
		printf("\n��ѯ������ѧ��,����������");
		del();
	}
	else{
        for(i=k;i<j-1;i++)
        {
            strcpy(stu[i].num,stu[i+1].num);
            strcpy(stu[i].name,stu[i+1].name);
            stu[i].money=stu[i+1].money;
        }
        printf("�ɹ�ɾ����¼��\n");
	}
	fp=fopen("duli16.3.dat","w");
	for(i=0;i<j-1;i++)
        fprintf(fp,"%s %s %d %d %d\n",stu[i].num,stu[i].name,stu[i].money,stu[i].start,stu[i].end);
    fclose(fp);
}
void addmoney()                                                                     //           6
{
    struct student stu[30]={0};
    int j=0,i=0,k=-1,a=0,cmoney=0;
    char s[10];
    FILE *fp=NULL;
    printf("��������Ҫ��ֵ��ѧ�ţ�");
    scanf("%s",s);
    if((fp=fopen("duli16.3.dat","r"))==NULL)
	printf("��ѯ������ѧ��");
	while(feof(fp)==0)
    {
        fscanf(fp,"%s %s %d %d %d\n",stu[j].num,stu[j].name,&stu[j].money,&stu[j].start,&stu[j].end);
		j++;
    }
    fclose(fp);
    printf("\n");
    for(i=0;i<j;i++)
    {
       if(strcmp(stu[i].num,s)==0)
		k=i;
	}
	if(k==-1)
	{
		system("cls");
		printf("\n��ѯ������ѧ��,����������");
		addmoney();
	}
	else
	{
		printf("�����ֵ��");
		scanf("%d",&cmoney);
		stu[k].money=stu[k].money+cmoney;
		printf("ѧ�ţ�%s ������%s ��%d\n",stu[k].num,stu[k].name,stu[k].money);
		fp=fopen("duli16.3.dat","r+");
		for(a=0;a<j;a++)
			fprintf(fp,"%s %s %d %d %d\n",stu[a].num,stu[a].name,stu[a].money,stu[a].start,stu[a].end);
		fclose(fp);
	}
}
void search()                                                                       //            7
{
    struct student stu[30]={0};
    int j=0,k=0;
    FILE *fp;
    if((fp=fopen("duli16.3.dat","r"))==NULL){
        printf("Can not open file duli16.3.dat!\n");
        exit(0);
	}
    while(feof(fp)==0)
    {
        fscanf(fp,"%s %s %d %d %d\n",stu[j].num,stu[j].name,&stu[j].money,&stu[j].start,&stu[j].end);
		j++;
    }
    system("cls");
    for(k=0;k<j;k++)
        printf("ѧ�ţ�%s ������%s ��%d\n",stu[k].num,stu[k].name,stu[k].money);
}


