#include<stdio.h>
#include<string.h>

char key2[5][5] = {};
char et[100] = {},dt[100] = {};
int h=0,r=0,a,b;
int i_1,j_1,i_2,j_2;

int check_repeat_char(char k1)
{
int flag = 0;
for(int i = 0; i<5;i++)
{
	for(int j = 0; j<5;j++)
	{
		if(k1 == key2[i][j])
		{
			flag = 1;
			break;
		}
	}
}
return flag;
}

int get_ij(char k1, char k2)
{
	i_1 = 0,j_1 = 0,i_2 = 0,j_2 = 0;
    	for(int c = 0; c<5;c++)
	    for(int j = 0; j<5;j++)
	        if(k1 == key2[c][j])
	        {
	            i_1 = c;
	            j_1 = j;
	        }
	for(int c = 0; c<5;c++)
	    for(int j = 0; j<5;j++)
	        if(k2 == key2[c][j])
	        {
	            i_2 = c;
	            j_2 = j;
	        }
}

int convert_cipher(char k1, char k2)
{
    get_ij(k1, k2);
    if(i_1 == i_2)
    {
        et[h++] = key2[i_1][j_1+1];
        et[h++] = key2[i_2][j_2+1];
    }
    else if(j_1 == j_2)
    {
        et[h++] = key2[i_1+1][j_1];
        et[h++] = key2[i_2+1][j_2];
    }
    else 
    {
        et[h++] = key2[i_1][j_2];
        et[h++] = key2[i_2][j_1];
    }
    return 0;
}

int decrypt_cipher(char k1, char k2)
{
    get_ij(k1, k2);
    if(i_1 == i_2)
    {
        dt[r++] = key2[i_1][j_1-1];
        dt[r++] = key2[i_2][j_2-1];
    }
    else if(j_1 == j_2)
    {
        dt[r++] = key2[i_1-1][j_1];
        dt[r++] = key2[i_2-1][j_2];
    }
    else 
    {
        dt[r++] = key2[i_1][j_2];
        dt[r++] = key2[i_2][j_1];
    }
    return 0;
}


void main()
{

char key1[100] = {}, text[100] = {};

int i = 0,j = 0;

printf("Enter key as an string: ");
scanf("%s",key1);
printf("Enter plain text as an string: ");
scanf("%s",text);
int l = strlen(key1);

for(int  k = 0; k < l; k++)
{
	if(key1[k] == 'j')
		key1[k] = 'i';
	if((check_repeat_char(key1[k])) == 0)
	{
		key2[i][j++] = key1[k];
	}
	if(j>=5)
		i++;
	if(j==5)
		j = 0; 	
}

for(int ch = 97; ch <= 122; ch++)
{
	char k = (char)(ch);
	if(k == 'j')
		k = 'i';
	if((check_repeat_char(k)) == 0)
	{
		key2[i][j++] = k;
	}
	if(j>=5)
		i++;
	if(j==5)
		j = 0; 	
}

for(int i = 0; i<5;i++)
{	for(int j = 0; j<5;j++)
		printf("%c",key2[i][j]);
	printf("\n");
}

l = strlen(text);

for(int i = 0; i < l; i++)
{
char t1,t2;
t1 = text[i];

if(i == (l-1))
	t2 = 'x';
else if (t1 == text[i+1])
	t2 = 'x';
else
	t2 = text[++i];

printf("%c %c\n",t1,t2);
convert_cipher(t1,t2);
}

printf("Plain Text: %s\nCipher Text: %s\n",text,et);

for(int i = 0; i < l; i++)
{
char t1,t2;
t1 = et[i];
t2 = et[++i];


decrypt_cipher(t1,t2);
}
printf("Decrypted Text: %s",dt);
}