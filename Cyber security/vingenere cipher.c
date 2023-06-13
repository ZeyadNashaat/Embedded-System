#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Encryption(char* message,char* key);
void Decryption(char* message,char* key);

void main(void)
{
	char msg[]="ZEYADMOHAMED";
	char key[]="HELLO";
	int msglen=strlen(msg),keylen=strlen(key),i,j;
	char newkey[msglen];
	for (i=0,j=0;i<msglen;++i,++j)
	{
			if (j==keylen)
				j=0;
			newkey[i]=key[j];
	}
	newkey[i]='\0';
	printf("New Generated Key: %s", newkey);
}

void Encryption(char* message,char* key)
{
	
}
void Decryption(char* message,char* key)
{
	
}