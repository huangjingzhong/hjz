/* 
* @Author: huangjingzhong
* @Date:   2016-08-11 18:50:57
* @Last Modified by:   huangjingzhong
* @Last Modified time: 2016-11-3 20:50
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	FILE *fp = NULL;
	char *line = NULL;
	int cnt = -1;
	int len = 0;
	fp = fopen("./test.txt", "rwa");
	if(NULL == fp)
	{
		printf("open test.txt  error!\n");
		return -1;
	}
	if((cnt = getline(&line, &len,fp))!=-1) //读取行信息，'\n'为换行标志
    {
    	
    	printf("%d\n", cnt);
    	if (cnt == 17)
    	{
	    	for(int i=2;i<=14;i+=3)
	    	{
	    		char *temp =strchr(line,':');
	        	if (*(temp) ==*(line+i))
	        	{
	        		continue;
	        	}else
	        	{
	        		printf("Invlid MAC.\n");
	        		//break;
	        		return 0;
	        	}
	    	}
	    	if ((isxdigit(line[0])) &&(isxdigit(line[1]))&&(isxdigit(line[3]))&&(isxdigit(line[4]))&&(isxdigit(line[6]))&&(isxdigit(line[7])) &&(isxdigit(line[9]))&&(isxdigit(line[10]))&&(isxdigit(line[12]))&&(isxdigit(line[13])) &&(isxdigit(line[15]))&&(isxdigit(line[16])))
	    	{
	    		if(line[0]=='0')
				{
					if (line[1]=='0'&&line[3]=='0'&&line[4]=='0'&&line[6]=='0' &&line[7]=='0' &&line[9]=='0' &&line[10]=='0'&&line[12]=='0'&&line[13]=='0'&&line[15]=='0' &&line[16]=='0' )
					{
						printf("zero MAC\n");
						return 0;
					}else
					{
						printf("Unicast address\n");
						return 0;
					}	
				}else if (line[0]=='1')
				{
					if (line[1]=='1'&&line[3]=='1'&&line[4]=='1'&&line[6]=='1'&&line[7]=='1'&&line[9]=='1'&&line[10]=='1'&&line[12]=='1' &&line[13]=='1'&&line[15]=='1'&&line[16]=='1')
					{
						printf("Broadcast MAC\n");
						return 0;
					}else
					{
						printf("Multicast address\n");
						return 0;
					}	
				}
	    	}
    	}
    	printf("Invlid MAC.\n");
    }
    if(-1 == cnt)
    {
    	printf("getline function error!\n");
    }

	return 0;
}

