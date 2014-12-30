#include<iostream>
#include<string>

#define size 26

using namespace std;
//Decrypting
void decrypt(string alphabets[], string word, string keyword)
{
	string str = word;
	for(int i = 0; i < keyword.length(); i++)
	{
		int x;
		for(x = 0; x < size; x++)
		{
			if(alphabets[0].at(x) == keyword.at(i)) break;
		}
		
		int y = alphabets[x].find(word.at(i));
		word.at(i) = alphabets[0].at(y);
	}
	
	cout << endl << "Entered   word " << str << endl;
	cout << "Decrypted word "<< word << endl;
}
//Encrypting
void encrypt(string alphabets[], string word, string keyword)
{
	string str = word;
	for(int i = 0; i < word.length(); i++)
	{
		int x;
		int y = alphabets[0].find(word.at(i));
		
		for(x = 0; x < size; x++)
		{
			if(alphabets[0].at(x) == keyword.at(i)) break;
		}
		
		word.at(i) = alphabets[x].at(y);
	}
	
	cout << endl << "Entered   word " << str << endl;
	cout << "Encrypted word "<< word << endl;
}

void process(int choice)
{
	string alphabets[size];
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	alphabets[0] = alphabet;
	//Obtaining alphabets
	for(int i = 1; i < size; i++)
	{
		string str = alphabets[i-1];
		
		char c = str.at(0);
		str.erase(0, 1);
		str.push_back(c);
		alphabets[i] = str;
	}
	/*for(int i = 0; i < 26; i++)
	{
		cout << alphabets[i] << endl;
	}*/
	
	string word;
label1:	cout << endl << "Enter 1 word without blank spaces! Letters should be latin." << endl;
	cin >> word;
	//Check is symbol in word is not latin letter
	for(int i = 0; i < word.length(); i++)
	{			
		if(word.at(i) < 97 || word.at(i) > 122)
		{
			cout << "Wrong word!" << endl;
			goto label1;
		} 
	}
	//Transition word to lowercase
	for(int i = 0; i < word.length(); i++)
	{			
		if(word.at(i) > 64 && word.at(i) < 91)
		{
			word.at(i) += 32;
		} 
	}

	string keyword;
	label2: cout << endl << "Enter keyword. Length of keyword canot be greater than length of word. Letters should be latin." << endl;
	cin >> keyword;
	
	//Check is symbol in keyword is not latin letter
	for(int i = 0; i < keyword.length(); i++)
	{			
		if(keyword.at(i) < 97 || keyword.at(i) > 122)
		{
			cout << "Wrong keyword!" << endl;
			goto label2;
		} 
	}
	
	//Transition keyword to lowercase
	for(int i = 0; i < keyword.length(); i++)
	{			
		if(keyword.at(i) > 64 && keyword.at(i) < 91)
		{
			keyword.at(i) += 32;
		} 
	}
	
	if(keyword.length() > word.length())
	{
		cout << "Length of keyword greater than length of word. Please enter another keyword." << endl;
		goto label2;
	}

	int quotient = word.length()/keyword.length();
	for(int i = 1; i < quotient; i++)
	{
		keyword += keyword;
	}

	int remainder = word.length()%keyword.length();
	if(remainder != 0)
	{
		string str = keyword;
		str.resize(remainder);
		keyword += str;
	}
	
	cout << endl << "Obtained key " << keyword << endl;

	switch(choice)
	{
		case 1: encrypt(alphabets, word, keyword);
		break;

		case 2: decrypt(alphabets, word, keyword);
		break;
	}
}

int main()
{
	cout << "[1] Encrypt" << endl << "[2] Decrypt" << endl;
	//Request to user
	int choice;
	cin >> choice;

	process(choice);

	system("PAUSE");
	return 0;
}