#include <iostream>
#include <string>
using namespace std;

// Function to demo erase
void eraseDemo(string str)
{
	// Deletes character at position 4
	str.erase(0,2); // it removes 2 character starting from index 0;
  str.erase(2,3); // it removes 3 character starting from index 2;

	cout << "After erase : ";
	cout << str;
}

// Driver code
int main()
{
	string str("Hello World!");
	cout<<str.substr(2)<<endl;
	// cout << "Before erase : ";
	// cout << str << endl;
	// eraseDemo(str);

	return 0;
}
