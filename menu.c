/* 
* @Author: huangjingzhong
* @Date:   2016-08-11 18:50:57
* @Last Modified by:   anchen
* @Last Modified time: 2016-08-11 18:51:47
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
	char cmd[128];
        while(1)
	{
		scanf("%s",&cmd);
		if(strcmp(cmd,"help") == 0)
		{
			printf("This is help cmd\n");	
		}else if(strcmp(cmd,"quit") == 0)
                {
                        exit(1);
                }else
                {
                        printf("Wrong cmd!\n");
                }
	}	
	return 0;
}
