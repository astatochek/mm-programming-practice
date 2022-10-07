#include <iostream>

//Найти кол-во подмассивов (из подряд идущих элементов) с суммой не превосходящих k в массиве натуральных чисел

using namespace std; 
 
int main() 
{  
	int n, k, res = 0;

	cin >> n >> k;

	int* A = new int[n];

	for (int i = 0; i < n; i++)
		cin >> A[i];

	int j = 0, i = -1, s = 0;

	 
	while(i < n-1) 
	{ 
		i++;
		s += A[i]; 
		while((s > k) && (i > j))
		{
			s -= A[j];
			j++;
		} 

		if (s <= k)
			res += (i-j+1);
	}  

	cout << res;

}
