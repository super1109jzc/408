//时间片轮转调度算法

#include<iostream>
using namespace std;

class PCB
{
public:
    	int id;//进程标识符
    	PCB *next ;//连接指针
    	int time_slice ;//轮转时间片
    	int runtime ;//占用的CPU时间片数
    	int needtime ;//进程所需时间片数
    	char state;//进程状态
    	PCB()
    	{
        	id=0;
        	next=NULL;
        	time_slice=0;
        	runtime=0;
        	needtime=0;
        	state='R';//R-就绪,r-运行,F-完成
    	}
};

class PCBS
{
public:
    	PCB *run;//运行进程指针
    	PCB *ready;//就绪队列头指针
    	PCB *tail;//就绪队列尾指针
    	PCB *finish;//完成队列指针
    	PCBS()
    	{
        	run=NULL;
        	ready=NULL;
        	tail=NULL;
        	finish=NULL;
    	}
};

void input_readyqueue(PCBS *pcbs)//插入进程至就绪队列
{  
	int i;int t;int r;int n;
   	PCB *pcb=new PCB();
   	cout<<"请输入进程标识符：";
   	cin>>i;
   	cout<<"输入格式为： （轮转时间片，占用CPU时间片数，进程所需时间片数） : ";
   	cin>>t>>r>>n;
   	pcb->id=i;
   	pcb->time_slice=t;
   	pcb->runtime=r;
   	pcb->needtime=n;
   	if(pcbs->ready == NULL && pcbs->tail == NULL)
   	{
       		pcbs->ready = pcb;
       		pcbs->tail = pcb;
   	}
  	else
   	{
       		pcbs->tail->next = pcb ;
       		pcbs->tail = pcb ;
   	}
}

void print(PCBS *pcbs)//打印运行、就绪、完成队列
{   	
	PCB *r,*f;
     	r=pcbs->ready;f=pcbs->finish;
     	cout<<"--------------------------------------------------  \n";
     	cout<<"运行队列："<<endl;
     	if(pcbs->run != NULL)
     	{
        	cout<<"进程标识符："<<pcbs->run->id<<"   轮转时间片："<<pcbs->run->time_slice<<"   进程占用CPU时间片数："<<pcbs->run->runtime<<"   进程所需时间片数:"<<pcbs->run->needtime<<endl;
     	}
     	else
     	{
         	cout<<"运行队列为空"<<endl;
     	}
     	cout<<"就绪队列："<<endl;
     	if(r==NULL)
     	{
         	cout<<"就绪队列为空"<<endl;
     	}
     	else
     	{
         	while(r != NULL)
       		{
         		cout<<"进程标识符："<<r->id<<"   轮转时间片："<<r->time_slice<<"   进程占用CPU时间片数："<<r->runtime<<"   进程所需时间片数:"<<r->needtime<<endl;
         		r = r->next ;
       		}
     	}
     	cout<<"结束队列："<<endl;
     	if(f==NULL)
     	{
         	cout<<"就绪队列为空"<<endl;
     	}
     	else
     	{
     		while(f != NULL)
       		{
         		cout<<"进程标识符："<<f->id<<"   轮转时间片："<<f->time_slice<<"   进程占用CPU时间片数："<<f->runtime<<"   进程所需时间片数:"<<f->needtime<<endl;
         		f = f->next ;
       		}
     	}
}

void time_slice_algorithm(PCBS *pcbs)//时间片轮转调度算法
{   
	print(pcbs);
     	while(pcbs->ready != NULL)
     	{
         	pcbs->run = pcbs->ready ;
         	pcbs->run->state='r';
         	pcbs->ready = pcbs->ready->next ;
         	pcbs->run->next = NULL;
         	print(pcbs);
         	pcbs->run->runtime = pcbs->run->runtime+1;
         	pcbs->run->needtime = pcbs->run->needtime-1 ;
         	if(pcbs->run->needtime == 0)
         	{
           		if(pcbs->finish == NULL)
           		{
               			pcbs->finish = pcbs->run ;
               			pcbs->finish->state='F';
               			pcbs->finish->next = NULL ;
           		}
           		else
           		{
              			PCB *f=pcbs->finish;
              			pcbs->finish=pcbs->run;
              			pcbs->finish->state='F';
              			pcbs->finish->next=f;
           		}
         	}
         	else
        	{
            		if(pcbs->run->time_slice!=pcbs->run->runtime)
            		{
                		if(pcbs->ready != NULL && pcbs->tail != NULL)
              			{
                 			PCB *r=pcbs->ready;
                 			pcbs->ready=pcbs->run;
                 			pcbs->ready->state='R';
                 			pcbs->ready->next=r;
              			}
               			else
               			{
                 			pcbs->ready = pcbs->run ;
                 			pcbs->tail = pcbs->run ;
                 			pcbs->ready->state='R';
               			}
            		}
            		else
            		{  
			       	pcbs->run->runtime=0;
                		if(pcbs->ready == NULL && pcbs->tail == NULL)
               			{
                   			pcbs->ready = pcbs->run;
                   			pcbs->tail = pcbs->run;
                   			pcbs->ready->state='R';
               			}
               			else
               			{
                   			pcbs->tail->next = pcbs->run ;
                   			pcbs->tail = pcbs->run ;
                   			pcbs->tail->state='R';
                		}
            		}
        	}
     	}
     	pcbs->run = NULL ;
     	print(pcbs);
}

int main()
{
    	PCBS *pcbs=new PCBS();
    	int n;
    	cout<<"请输入要处理的进程数目： ";
    	cin>>n;
    	for(int i = 0 ; i < n ; i++)
    	{
        	input_readyqueue(pcbs);
    	}
    	cout<<"时间片轮转调度算法："<<endl;
    	time_slice_algorithm(pcbs);
    	return 0 ;
}
