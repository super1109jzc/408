#include <unistd.h>
# include<stdio.h> 
int main() 
 {
         int p1, p2; 
         while((p1=fork())== -1); 
         if(p1==0) 
                 printf("b\n"); 
         else 
                 {
                         while((p2=fork())==-1); 
                         if(p2==0) 
                                 printf("c\n"); 
                         else 
                            
				 printf("a\n"); 
                                 printf("m\n"); 
                 } 
}
