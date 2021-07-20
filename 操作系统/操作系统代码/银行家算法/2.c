#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
int Res[15];//剩余资源数
int Req[15];//申请资源数
//定义结构体,即例子中那个定义的表格
struct Process
{
	int Had[15];//已分配资源数
	int Max[15];//最大资源分配数
	int Need[15];//还需资源数
	bool IsEnd;//用来判断是否能分配
}Processes[15];//进程数组
int n,m;//进程数和资源数
int curProcess;//申请的资源的进程
struct Process tmpProcesses[15];//假设允许分配的进程数组

bool IsEnd()//判断所有进程是否结束
{
	bool R=true;
	int i;
	for(i=0;i<n;i++)
	{
		if(Processes[i].IsEnd==false)
		{
			R=false;
			break;
		}
	}
	return R;
}

bool IstmpEnd()//判断所有假设允许分配的进程是否结束
{
	bool R=true;
	int i;
	for(i=0;i<n;i++)
	{
		if(tmpProcesses[i].IsEnd==false)
		{
			R=false;
			break;
		}
	}
	return R;
}
bool Legal=false;
bool Banker()//银行家算法
{
	int i,j;
        Legal=true;
	for(i=0;i<m;i++)//如果申请的资源大于所需资源，错误
	{
		if(Req[i]>Processes[curProcess].Need[i])
		{
			Legal=false;
			break;
		}
	}

	for(i=0;i<m;i++)//如果申请资源大于剩余资源，错误
	{
		if(Req[i]>Res[i])
		{
			Legal=false;
			break;
		}
	}

	//将Processes表格和Res数组复制，对复制体进行操作，本体数据不会变化
	int tmp[15];
	for(i=0;i<m;i++)
	{
		tmp[i]=Res[i];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			tmpProcesses[i].Max[j]=Processes[i].Max[j];
			tmpProcesses[i].Need[j]=Processes[i].Need[j];
			tmpProcesses[i].Had[j]=Processes[i].Had[j];
			tmpProcesses[i].IsEnd=Processes[i].IsEnd;
		}
	}

	//按照申请资源分配完后，目前资源状态
	for(i = 0;i<m;i++)
  	{
    		tmpProcesses[curProcess].Had[i] +=Req[i];
   	 	tmpProcesses[curProcess].Need[i] -= Req[i];
    		tmp[i]-=Req[i];
  	}

	bool IsFind = false;
	do{
    		IsFind = false;
     		int curRel = -1;
		//对每个进程进行分析，看看哪个不死锁，可以分配
     		for(i = 0;i<n;i++)
     		{
       			if(tmpProcesses[i].IsEnd == false)
       			{
         			bool IsFF = true;
				//如果需要的资源大于剩余资源，错误
         			for(j= 0;j<m;j++)
         			{
           				if(tmpProcesses[i].Need[j] > tmp[i])
           				{
            					IsFF = false;
             					break;
           				}
         			}
        			IsFind = IsFF;
        			if(IsFind == true)
        			{
         				curRel = i;
         				break;
				}
			}
		}
		if(IsFind)
		{
			for(i=0;i<m;i++)
			{
				tmp[i]+=tmpProcesses[curRel].Had[i];
				tmpProcesses[curRel].IsEnd=true;
				tmpProcesses[curRel].Had[i]=0;
				tmpProcesses[curRel].Need[i]=0;
			}
		}
	}while(!IstmpEnd() && IsFind==true);
	//判断资源是否完全分配完毕
	for(i=0;i<n;i++)
	{
		if(tmpProcesses[i].IsEnd==false)
		{
			Legal=false;
			break;
		}
	}
	return Legal;
}

void Print()//打印第i个进程占有第j种资源的数目和最多需要第j种资源的数目和每种资源所剩的数目
{
	int i,j;
	for(i = 0;i<n;i++)
	{
    		for(j = 0;j<m;j++)
		{
			printf("%d",i);
			printf("进程占有第");
			printf("%d",j);
			printf("种资源的数目和所需的最大数目：");
			printf("%d %d\n",Processes[i].Had[j],Processes[i].Max[j]);
  		}	
  		printf("\n");
  	}
  	printf("每种资源所剩数目:\n");
  	for(i = 0;i<m;i++)
	{
		printf("%d",Res[i]);
		printf(" ");
	}
 	printf("\n");
}

int main()
{
	int i,j;
	memset(Processes,0,sizeof(Processes));
	memset(Res,0,sizeof(Res));
	memset(Req,0,sizeof(Req));
	printf("请输入进程总数和资源种数:\n");
	scanf("%d %d",&n,&m);
	printf("请输入每种资源所剩数目:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&Res[i]);
	}
	printf("请输入第i个进程占有第j种资源的数目和最多需要第j种资源的数目:\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d %d",&Processes[i].Had[j],&Processes[i].Max[j]);
		}
	}
	int option=-1;
	printf("是否采用防止死锁算法（0为采用）:\n");
	scanf("%d",&option);
	if(option==0)
	{
		do{
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					Processes[i].Need[j]=Processes[i].Max[j]-Processes[i].Had[j];
				}
			}
			printf("请输入需要申请资源的进程ID:\n");
			scanf("%d",&curProcess);
			printf("请输入该进程所需要每种资源的数目:\n");
			for(i=0;i<m;i++)
			{
				scanf("%d",&Req[i]);
			}
			Legal=false;
			Banker();
			if(Legal)
			{
				printf("同意申请！\n");
				Processes[curProcess].IsEnd=true;
				for(i=0;i<m;i++)
				{
					Processes[curProcess].Had[i]+=Req[i];
					Processes[curProcess].Need[i]-=Req[i];
					Res[i]-=Req[i];
					if(Processes[curProcess].Had[i]<Processes[curProcess].Max[i])
					{
						Processes[curProcess].IsEnd=false;
					}
					else
					{
						Res[i]+=Processes[curProcess].Had[i];
						Processes[curProcess].Had[i]=0;
						Processes[curProcess].Need[i]=0;
						printf("进程");
						printf("%d",curProcess);
						printf("已经完成所有需求！\n");
					}
				}
				Print();
			}
			else
        		{
                		printf("拒绝申请!\n");
        		}
		}while(!IsEnd());
		printf("所有进程都已完成所有需求！");
	}
	else
	{
		while(1)
		{
			for(i=0;i<n;i++)
                        {
                                for(j=0;j<m;j++)
                                {
                                        Processes[i].Need[j]=Processes[i].Max[j]-Processes[i].Had[j];
                                }
                        }
                        printf("请输入需要申请资源的进程ID:\n");
                        scanf("%d",&curProcess);
                        printf("请输入该进程所需要每种资源的数目:\n");
                        for(i=0;i<m;i++)
                        {
                                scanf("%d",&Req[i]);
                        }
			bool Legal=true;
			for(i=0;i<m;i++)
			{
				if(Req[i]>Processes[curProcess].Need[i] || Req[i]>Res[i])
				{
					Legal=false;
					break;
				}
			}
			if(Legal)
			{
				printf("同意申请！\n");
                                for(i=0;i<m;i++)
                                {
                                        Processes[curProcess].Had[i]+=Req[i];
                                        Processes[curProcess].Need[i]-=Req[i];
                                        Res[i]-=Req[i];
                                        if(Processes[curProcess].Had[i]==Processes[curProcess].Max[i])
                                        {
                                                Res[i]+=Processes[curProcess].Had[i];
                                                Processes[curProcess].Had[i]=0;
                                                Processes[curProcess].Need[i]=0;
                                                printf("进程");
                                                printf("%d",curProcess);
                                                printf("已经完成所有需求！\n");
                                        }
                                }
			}
			else
			{
				printf("出错，拒绝申请");
				return 0;
			}
		}
		return 0;
	}
}
