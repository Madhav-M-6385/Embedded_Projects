#include<stdio.h>
#include <unistd.h>
int main()
{
   
    int key,i,j=3,chance=3;
    key:printf("Enter the lock key:");
    scanf("%d",&key);
    int org_key=123;
    here:
        for(i=j;i>0;i--)
        {
            if(key==org_key)
            {
                break;
            }
            else
            {
                
                printf("Try again! %d attempts remaining \n",j-1);
                j--;
                if(j==0)
                {
                    printf("You are out of attempts! \n");
                    goto again;
                }
                else
                {
                    goto key;
                }
            } 
        }
    if(key==org_key)
    {
        printf("Door is Unlocked! \n");
        return 0;
    }
    else
    {
        again:
            
            printf("The door is locked.Try again after 1 minute! \n");
            sleep(3);
            chance=chance-1;
            j=chance;
        if(chance!=0)
        {
            printf("You now have only %d attempts to unlock! \n",j);
            goto key;
        }
            
        else
        {
            printf("Your door has been locked permanently.Please contact the service. \n");
        }
    }

    return 0;
}
