
#include <iostream>
#include <vector>

using namespace std;

template <class T>
vector<char> myunion(T* arr1, int size1, T* arr2, int size2);

template <class T>
bool helper(T lookFor, T* arr2, int size2);

int main()
{


	char array1[] = {'x' , 'b', 'a' , 't' , 'k' , 'm'};
	char array2[] = {'x' ,'b', 'a' , 't' , 'q'};

	vector<char> myVector = myunion(array1,  6,  array2, 5 );

	for(int i=0; i< myVector.size(); i++)
		cout << myVector[i] << ' ';

	cout << "\n";

	return 0;
}

template <class T>
vector<char> myunion(T* arr1, int size1, T* arr2, int size2)
{
	vector< T > temp;

	if(size1 == 0)
		return temp;

	temp = myunion( arr1 + 1, size1 - 1, arr2 , size2);

	if( helper(arr1[0] , arr2, size2) )
		temp.push_back(arr1[0]);

		return temp;

}


template <class T>
bool helper(T lookFor, T* arr2, int size2)
{

	if(size2 == 0)
		return false;

	else if( arr2[0] == lookFor )
		return true;

	else
		return helper(lookFor, arr2 + 1, size2 - 1); 

}