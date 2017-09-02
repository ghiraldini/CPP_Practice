#include <vector>
#include <iostream>
#include <iomanip>

void print(std::vector<int> a){
	for(int i=0; i<a.size(); i++)
		std::cout << a.at(i) << " ";
	std::cout << "" << std::endl;
	return;
}

std::vector<int> shift(std::vector<int> a, int n, int k){
	std::vector<int> s(n);
	int j=0;
	for(int i=k; i<=n; i++){
		s[i] = a.at(j++);
	}
	j--;
	for(int i=0; i<k; i++){
		s[i] = a.at(j++);
	}	
	return s;
}

/*
Input:
	5 (num of ints) 
	4 (num to shift)
	1 2 3 4 5 (array)
Output:
	5 1 2 3 4
*/

int main(int argc, char* argv[]){
	int n=8,k=3,t;
	std::vector<int> a;

//	std::cin >> n;
//	std::cin >> k;

	for(int i=1; i<=n; i++){
//		std::cin >> t;
		a.push_back(i);
	}
	

	std::cout << "Original: ";
	print(a);	

	std::vector<int> newVec = shift(a,n,k);

	std::cout << "Shifted: ";
	print(newVec);			

}
