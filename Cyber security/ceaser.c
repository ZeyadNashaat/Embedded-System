#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Encryption(char *message,int key);
void Decryption(char *message,int key);
int main(void)
{
	char text[101];int step; char mode;
	printf("Enter text to cipher:\n");
	fgets(text,sizeof(text),stdin);
	printf("Enter key value to cipher with:\n");
	scanf("%d",&step);
	printf("To Encrypt press (e), to Decrypt press (d):\n");
	scanf(" %c",&mode);
	switch (mode)
	{
		case 'e':
			printf("Ciphered text is:\n");
			Encryption(text, step);
			break;
		case 'd':
			printf("Original text is:\n");
			Decryption(text, step);
			break;
		default:
			printf("Insert right choice\n");
	}

}

void Encryption(char *message,int key)
{
	int i=0;
	int cypherValue;
	char cypher;
	while (message[i]!='\0'&&strlen(message)-1>i)
	{
		if ((message[i]>='a')&&(message[i]<='z'))
		{
			cypherValue=((int)message[i]-'a'+key)%26+'a';
			cypher=(char)cypherValue;
			printf("%c",cypher);
		}
		else if ((message[i]>='A')&&(message[i]<='Z'))
		{
			cypherValue=((int)message[i]-'A'+key)%26+'A';
			cypher=(char)cypherValue;
			printf("%c",cypher);
		}
		else
		{
			printf("%c",message[i]);
		}
		i++;
	}
}
void Decryption(char *message,int key)
{
	int i=0;
	int decypherValue;
	char decypher;
	while (message[i]!='\0'&&strlen(message)-1>i)
	{
		if ((message[i]>='a')&&(message[i]<='z'))
		{
			decypherValue=(int)message[i]-key;
			decypher=(char)decypherValue;
			if (decypher<'a')
			{
				decypherValue=decypherValue-(int)'a'+(int)'z'+1;
				decypher=(char)decypherValue;
			}
			else if (decypher>'z')
			{
				decypherValue=decypherValue-(int)'z'+(int)'a'-1;
				decypher=(char)decypherValue;
			}
			printf("%c",decypher);
		}
		else if ((message[i]>='A')&&(message[i]<='Z'))
		{
			decypherValue=((int)message[i]-'A'-key)%26+'A';
			decypher=(char)decypherValue;
			if (decypher<'A')
			{
				decypherValue=decypherValue-(int)'A'+(int)'Z'+1;
				decypher=(char)decypherValue;
			}
			else if (decypher>'Z')
			{
				decypherValue=decypherValue-(int)'Z'+(int)'A'-1;
				decypher=(char)decypherValue;
			}
			printf("%c",decypher);
		}
		else
		{
			printf("%c",message[i]);
		}
		i++;
	}
}
