#include "EncDec.h"
#include <iostream>

using namespace std;

string EncDecString(string InputString, string Key)
{
//	char * StrPtr = InputString;
//	char * KeyPtr = Key;

	string ResultStr;
//	cout << "InputString length: " << InputString.length() << endl;

	unsigned int j = 0, i = 0;
	for(; i < InputString.length(); i++)
	{
		//xor(StrPtr, KeyPtr);
		//StrPtr ^ KeyPtr;
		ResultStr += (InputString[i] ^ Key[j]);
//		cout << "ResultStr[" << i << "] == " << ResultStr[i] << endl;
		if(j >= Key.length())
		{
			j = 0;
		}
		//++StrPtr;
		//++KeyPtr;
	}

//	cout << "ResultStr length: " << ResultStr.length() << endl;
	return(ResultStr);
}
