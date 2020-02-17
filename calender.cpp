#include<stdio.h>
#include<stdlib.h>


int dow(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4}; // caluculated century numbers
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;  // formula to get the week number
  
}

int main(){

    printf("ENTER THE DATE TO KNOW THE DAY
                 in YYYY MM DD Format         ");
    int ye; // year variabe
    int mo; // month variable
    int da; // date variable
    scanf("%d %d %d",&ye,&mo,&da);

    int result = dow(ye, mo, da); // getting the value of the day in the week
    printf("Day in the week is %d" , result);

    if(result==0)
    {
       printf("its sunday");
    }
    else if(result==1)
    {
       printf("its monday");
    }


    else if(result==2)
    {
       printf("its tuesday");
    }


    else if(result==3)
    {
       printf("its wednesday");
    }


    else if(result==4)
    {
       printf("its thursday");
    }


    else if(result==5)
    {
       printf("its friday");
    }


    else if(result==6)
    {
      printf("its saturday");
    }





    return 0;
}
