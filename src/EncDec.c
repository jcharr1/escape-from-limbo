#include "types.h"
#include "EncDec.h"

void EncDecString(char * InputString, const char * Key, 
						char * OutputString)
{
	//char * StrPtr = InputString;
	//char * KeyPtr = Key;

	char ResultStr[1000] = {'\0'};

	unsigned int j = 0, i = 0;

//	ResultStr = (char *)malloc(sizeof(char) * strlen(InputString));
	for(; i < strlen(InputString); i++)
	{
//		slen = strlen(InputString);
		//xor(StrPtr, KeyPtr);
		//StrPtr ^ KeyPtr;
		if(InputString[i] != '\n')
		{
			ResultStr[i] = (InputString[i] ^ Key[j]);
		}
		else
		{
			ResultStr[i] = '\n';
		}
//		cout << "ResultStr[" << i << "] == " << ResultStr[i] << endl;
		if(j >= strlen(Key))
		{
			j = 0;
		}
		//++StrPtr;
		//++KeyPtr;
	}

//	cout << "ResultStr length: " << ResultStr.length() << endl;
	strncpy(OutputString, ResultStr, strlen(InputString));
//	free(ResultStr);
}
