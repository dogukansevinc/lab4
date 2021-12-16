#include <stdio.h>
#include <stdlib.h>
int lru(){
   int no_frames,len=0,i,j,l=0,pf=0,ph=0;
   printf("Enter number of frames >> ");
   scanf("%d",&no_frames);
   char ch,*str,frame[no_frames];
   str=(char *)malloc(sizeof(char));
   printf("If You Done,Please Press Enter>>\n");
   scanf("%c",&ch);
   //getting reference string
   while((ch=getchar())!='\n'){
       str = realloc(str,sizeof(char));
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
   for(j=i;j<len;j++){
       //checking for page in pageframe
       int flag=0;
       for(i=0;i<no_frames;i++){
           if(str[j]==frame[i]){
               ph++;
               flag=0;
               break;
           }
           else flag=1;
       }
       //if page fault occurs
       if(flag==1){
           pf++;
           int k,max=9999,index=0,count=0;
           //finding least recenlty used frame page
           for(k=0;k<no_frames;k++){
               for(i=j-1;i>=0;i--){
                   if(frame[k]==str[i]){
                       if(max>i){
                           max=i;
                           index=k;
                       }
                       break;
                   }
               }
               if(i==0){
                   index=k;
                   break;
               }
           }
           frame[index]=str[j];
           l=(l+1)%no_frames;
       }
   }
   printf("\nNumber of Page Faults >> %d",pf);
   printf("\nNumber of Page Hits >> %d\n",ph);
   return 0;
}