#include <stdio.h>
#define  max 6//������ʾϵͳҪ�������������
# include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
int main(){
	
	char temp1;
	int i,j,temp ;
	int sc;//���������±ꣻ
	char tempName[10];
	int cout=5;//��ǰδ�����乬������������
	//ʹ���ַ������ʾ�ַ���
	char emperorname[10];//�ʵ۵�����;
	int choice;//�ʵ۵�ѡ��1-4֮��;
	char names[6][8]={"����","����","��ʩ","���¸�","��֪��"};
	//�����ļ�������
	char levelNames[5][10]={"����","����","�ʹ���","�ʺ�","����"};
	//�������ÿλ���ӵļ���ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
	int levels[]={1,2,0,0,0,-1};
	//loveÿ��Ԫ�ض�Ӧÿ���ӵĺøж�
 
	int loves[] ={100,100,100,100,100,-1};
	
	printf("-----------------------------------------------------------------\n");
	printf("���ԣ��鿴��ǰ������״̬\n");
	printf("����\t\t����\t�øж�\n");
	for(i=0; i<cout; i++){

		printf("%s\t\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
		 
;
	}
	printf("-----------------------------------------------------------------\n");
	printf("�����뵱ǰ�ǻ��Ļʵ����ţ�");
	scanf("%s",emperorname);//¼���ַ���.
	printf("��ǰ�ʵ���%s�������ꡢ\n\n",emperorname);
	 for (i=0;;i++){
	printf("1���ʵ���ּѡ����\t\t(���ӹ���)\n");
	printf("2�����Ƴ��ң�\t\t(�޸�״̬)\n");
	printf("3�������乬��\t\t(ɾ������)\n");
	printf("4�������ټ�����ȥС������������¡�\n");
	printf("������ѡ��;");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1://1���ʵ���ּѡ����\t\t(���ӹ���)
		//��������Ԫ�أ���
		//����ǰ��Ҫ�ж�������û�пռ�
		PlaySound(TEXT("sounds\\��������.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
		if (cout<max){//�����ǰ����С��ϵͳ���ֵ

	
			//ִ�в���
			printf("���������������");
			scanf("%s",names[cout]);
			levels[cout]=0;//�����Ϊ0;
			loves[cout]=100;//�øжȳ�ʼΪ0��
			cout++;
			
		}else {

			printf("�����ˣ������ܲ���");
		}

		break;
	case 2://���Ƴ��ң�\t\t(�޸�״̬)
		   //�ҵ��������ӵ��±ꣻ
		   //�޸������ӵ�״̬���øж�+10����������1�������߼��Ͳ�����
			//�޸��������ӵ�״̬�����ڼ��ʣ��������Ӻøо���-10
			PlaySound(TEXT("sounds\\����.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
		printf("�����������Ҫ���Ƶ�����");
		scanf("%s",tempName);
	 for (i=0;i<cout;i++)
	 {
		 if(strcmp(tempName,names[i])==0){
			 loves[i]+=10;
			 //����Ҫע�⣬���ܳ���5��
			 levels[i]=levels[i]>=4?4:levels[i]+1;
		 }else{
			 loves[i]-=10;
		 }


	 }
		break;
	case 3://3�������乬��\t\t(ɾ������)
			 //����
			//��һ������ǰ��һ��Ԫ��;
		//����--	
		PlaySound(TEXT("sounds\\�乬.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
			printf("���£�������Ҫ�����乬������");
			scanf("%s",tempName);
				for (i=0;i<cout;i++)
				{	 if (strcmp(tempName,names[i])==0)
				     {	sc=i;
			  
				} else{
						  loves[i]+=10;
				}
				}
				if (sc==-1)
				{
					printf("���˴����乬");
				}else
				     {
					for (i=sc;i<cout-1;i++)
					      {	
							  strcpy(names[i],names[i+1]);
							loves[i]=loves[i+1];
							levels[i]=levels[i+1];
							 

							
					        }
					cout--;
					 
				     }
			break;
	case 4://4�������ټ�����ȥС�������������
		 	PlaySound(TEXT("sounds\\һЦ���.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);

		break;
	default:
	printf("��������");
	}
	for (i=0;i<cout-1; i++){
		for(j=i+1;j<cout;j++){

			if (levels[i]<levels[j])
			{temp=levels[j];
			levels[j]=levels[i];
			levels[i]=temp;
			temp=loves[j];
			loves[j]=loves[i];
			loves[i]=temp;
			 strcmp(tempName,names[j]);
			strcmp(names[j],names[i]);
			strcmp(names[i],tempName);
			}

		}



	}

	printf("-----------------------------------------------------------------\n");
	printf("���ԣ��鿴��ǰ������״̬\n");
	printf("����\t\t����\t�øж�\n");
	for(i=0; i<cout; i++){

		printf("%s\t\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);

		;
	}
	printf("-----------------------------------------------------------------\n");
	 }
	return 0;
}