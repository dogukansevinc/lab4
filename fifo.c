/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include <stdlib.h>

int fifo()
{
      
   int no_frames,len=0,i,j,l=0,pf=0,ph=0,pos=0,k;
   printf("Enter number of frames >> ");
   scanf("%d",&no_frames);
   char ch,*str,frame[no_frames];
   str=(char *)malloc(sizeof(char));
   printf("If You Done,Please Press Enter>>\n");
   scanf("%c",&ch);
   //getting reference string
   while((ch=getchar())!='\n'){
       str=realloc(str,sizeof(char));
       str[len++]=ch;
   }
   str[len]='\0';
   //initailly page frame filling
   for(i=0;i<no_frames;i++){
       frame[i]=str[i];
   }
   frame[i]='\0';
   //starting page replacement algorithm
   pf=no_frames;
   for(i=no_frames;i<len;i++)
   {
      
       k=0;
       for(j=0;j<no_frames;j++)
       {
           //printf("| %d |\t",b[j]);
           if(str[i]==frame[j])
           {
               k=1;
               //pos++;
              
              
           }
          
       }
       //printf("\n");
       if(k==0)
       {
           //pos=pos%3;
           //pos=(pos)%3;
           frame[pos]=str[i];
           pos=(pos+1)%no_frames;
          
           pf++;
       }
       else
       {
           ph++;
       }
   }
   printf("\n page faults\t : %d",pf);
   printf("\n page hits : %d ",ph);
}
