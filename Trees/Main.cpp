#include <iostream>
#include <list>
#include <string>
#include <assert.h>
#include "Tree.h"

int main(void)
{
	Tree tree;
	string val;
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
				  cout << "enter value\t";
				  cin >> val;
				  tree.addRoot(val);
				  break;
			case 'e':
				  cout << "bye " << "\n";
				  break;
			default: 
				  cout << "error ";  
				  break;
		}
	} while (ch != 'e');
	tree.print(tree.getRoot(), 4);
	return 1;
}