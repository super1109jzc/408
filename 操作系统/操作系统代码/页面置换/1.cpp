#include <iostream>
#include <stdlib.h>
using namespace std;

#define M 12//作业的页面数

//定义页面
typedef struct page{
  int id;
  struct page *next;
}Page;

//定义页面链表
typedef struct pages{
  int count;
  Page *head;Page *tail;

}Pages;
Pages *pages=(Pages*)malloc(sizeof(Pages)) ;

//初始化页面链表
void Init( ){
   pages->count=0;
   pages->head=NULL;
   pages->tail=NULL;
}
//插入页面
void Insert(int i){
 page *p=(Page*)malloc(sizeof(Page));
  p->id=i;
  p->next=NULL;
  if(pages->head==NULL)
  {
      pages->head=pages->tail=p;
  }
  else{
    pages->tail->next=p;
    pages->tail=p;
  }
  pages->count++;
}
//页面调出
void Out( ){
    pages->head=pages->head->next;
    pages->count--;

}
//在链表中查找,若找到则返回1，否则返回0
int Check(int i){
  for(page *p=pages->head;p!=NULL;p=p->next)
  {
      if(p->id==i){return 1;}
  }
  return 0;
}
//在链表中查找,若找到则返回1并且移动到链尾，否则返回0
int Move(int i){
  if(pages->head==NULL){return 0;}
  else if(pages->head->id==i){pages->head=pages->head->next;pages->count--;Insert(i);return 1;}
  else{
    for(page *p=pages->head;p->next!=NULL;p=p->next)
    {
        if(p->next->id==i){
            p->next=p->next->next;
            pages->count--;
            Insert(i);
            return 1;
        }
    }
    return 0;
  }
}
//打印页面链表
void Print( ){
  cout<<"内存中的页面：";
  for(page *p=pages->head;p!=NULL;p=p->next)
  {
      cout<<p->id<<" ";
  }
  cout<<endl;
}
//先进先出算法
void FIFO(int A[]){
   int n=0;
   for(int i=0;i<M;i++)
   {
       if(Check(A[i]))
       {   Print();
           n++;
       }
       else
       {
           if(pages->count<4){Insert(A[i]);Print();}
           else{Out();Insert(A[i]);Print( );}
       }
   }

   cout<<"FIFO的命中率为: "<<(float)n/M;
}
//最近最少使用页面淘汰算法
void LRU(int A[]){
   int n=0;
   for(int i=0;i<M;i++)
   {
       if(Move(A[i]))
       {   Print();
           n++;
       }
       else
       {
           if(pages->count<4){Insert(A[i]);Print();}
           else{Out();Insert(A[i]);Print( );}
       }
   }
   cout<<"LRU的命中率为: "<<(float)n/M;
}

int main(){
    Init( );
   int A[100];
   cout<<"请输入作业的页面调入串：";
   for(int i=0;i<M;i++){int j;cin>>j;A[i]=j;}
   cout<<"------------先进先出算法------------"<<endl;
   FIFO(A);
   cout<<endl;
   cout<<"------------最近最少使用页面淘汰算法------------"<<endl;
   Init( );
   LRU(A);
   return 0;
}
