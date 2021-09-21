#include <iostream>
#include <list>
#include <string>
#include <assert.h>
#include "Tree.h"

int main(void)
{
	Tree t;
	string val, father;
	char ch;

	do
	{
		cout << "Choose one of the following:" << endl;
		cout << "n: New tree:" << endl;
		//... additional options
		cout << "e: exit:" << endl;
		cin >> ch;
		switch (ch)
		{
			case 'n':
				  cout << "enter value of country "; cin >> val; t.addRoot(val); break;
			case 'e':
				  cout << "bye "; 
				  break;
			default: 
				  cout << "error ";  
				  break;
		}
	} while (ch != 'e');
}