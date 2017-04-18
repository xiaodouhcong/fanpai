#include <stdio.h>
#define  max 6//常量表示系统要求最大妃子数量
# include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib, "WINMM.LIB")
int main(){
	
	char temp1;
	int i,j,temp ;
	int sc;//用来查找下标；
	char tempName[10];
	int cout=5;//当前未打入冷宫的嫔妃个数；
	//使用字符数组表示字符串
	char emperorname[10];//皇帝的名号;
	int choice;//皇帝的选择1-4之间;
	char names[6][8]={"貂蝉","杨玉环","西施","郭德纲","不知火"};
	//嫔妃的级别数组
	char levelNames[5][10]={"贵人","嫔妃","皇贵妃","皇后","嫔妃"};
	//用来存放每位妃子的级别，每个数组元素对应每个妃子的当前级别
	int levels[]={1,2,0,0,0,-1};
	//love每个元素对应每妃子的好感度
 
	int loves[] ={100,100,100,100,100,-1};
	
	printf("-----------------------------------------------------------------\n");
	printf("测试，查看当前嫔妃的状态\n");
	printf("姓名\t\t级别\t好感度\n");
	for(i=0; i<cout; i++){

		printf("%s\t\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);
		 
;
	}
	printf("-----------------------------------------------------------------\n");
	printf("请输入当前登基的皇帝名号：");
	scanf("%s",emperorname);//录入字符串.
	printf("当前皇帝是%s万岁万岁、\n\n",emperorname);
	 for (i=0;;i++){
	printf("1、皇帝下旨选妃：\t\t(增加功能)\n");
	printf("2、翻牌宠幸：\t\t(修改状态)\n");
	printf("3、打入冷宫！\t\t(删除功能)\n");
	printf("4、单独召见爱妃去小树林做纯洁的事。\n");
	printf("陛下请选择;");
	scanf("%d",&choice);
	
	switch(choice)
	{
	case 1://1、皇帝下旨选妃：\t\t(增加功能)
		//增加数组元素（）
		//增加前需要判断数组有没有空间
		PlaySound(TEXT("sounds\\背景音乐.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
		if (cout<max){//如果当前妃子小于系统最大值

	
			//执行操作
			printf("请输入娘娘的名字");
			scanf("%s",names[cout]);
			levels[cout]=0;//级别初为0;
			loves[cout]=100;//好感度初始为0；
			cout++;
			
		}else {

			printf("后宫满了，怕你受不了");
		}

		break;
	case 2://翻牌宠幸：\t\t(修改状态)
		   //找到宠幸妃子的下标；
		   //修改这妃子的状态，好感度+10，级别升级1，如果最高级就不升级
			//修改其他妃子的状态，由于嫉妒，其它妃子好感觉度-10
			PlaySound(TEXT("sounds\\翻牌.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
		printf("陛下输入今天要翻牌的名字");
		scanf("%s",tempName);
	 for (i=0;i<cout;i++)
	 {
		 if(strcmp(tempName,names[i])==0){
			 loves[i]+=10;
			 //级别要注意，不能超过5级
			 levels[i]=levels[i]>=4?4:levels[i]+1;
		 }else{
			 loves[i]-=10;
		 }


	 }
		break;
	case 3://3、打入冷宫！\t\t(删除功能)
			 //查找
			//后一个赋给前面一个元素;
		//总数--	
		PlaySound(TEXT("sounds\\冷宫.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);
			printf("陛下，请输入要打入冷宫的姓名");
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
					printf("无人打入冷宫");
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
	case 4://4、单独召见爱妃去小树林做纯洁的事
		 	PlaySound(TEXT("sounds\\一笑倾城.wav"),NULL, SND_FILENAME| SND_ASYNC | SND_LOOP);

		break;
	default:
	printf("陛下累了");
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
	printf("测试，查看当前嫔妃的状态\n");
	printf("姓名\t\t级别\t好感度\n");
	for(i=0; i<cout; i++){

		printf("%s\t\t%s\t%d\n",names[i],levelNames[levels[i]],loves[i]);

		;
	}
	printf("-----------------------------------------------------------------\n");
	 }
	return 0;
}