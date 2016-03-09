#include"stdlib.h"
#include"stdio.h"
int main(int arg,char * argx[])
{
	printf("change 0000  in file to Space \n");
	if(arg<2)
	{
		fputs("input file name \n",stderr);
		exit(1);
	}
	char *filename =argx[1];
	printf("change %s \n",filename);
	char filenameout[100];
	sprintf(filenameout,"%s_new",filename);
	printf("write new file to %s \n",filenameout);
	
	FILE *fold =fopen(filename,"rb");
	if(fold==NULL)
	{
		fputs ("File error \n",stderr);
		exit (1);
	}
	
	
	fseek(fold,0,SEEK_END);
	long fsize = ftell(fold);
	printf("file size is %d \n",fsize);
	
	char *buf=(char*)malloc(sizeof(char)*fsize);
	if(buf==NULL) 
	{
		fputs ("memory error \n",stderr);
                exit (1);
	}
	rewind(fold);
	size_t results;
	results = fread(buf,1,fsize,fold);	
	
	if(results!=fsize)
	{
		printf("read size %d \n",results);
		fputs ("file read error \n",stderr);
                exit (1);
	}

	
	for(int i=0;i<fsize;i++)
	{
		if(buf[i]==0)
			buf[i]=32;
	}
	
	FILE *fnew =fopen(filenameout,"wb");
	fwrite(buf,1,fsize,fnew);
	fclose(fold);	
	fclose(fnew);	
	free(buf);
	
	printf("end ---------\n");
		
	
}
