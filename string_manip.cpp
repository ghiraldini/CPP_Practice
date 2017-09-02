#include <iostream>
#include <string>


bool isPalidrone(std::string str){

	for (std::string::const_iterator i=str.begin(), j=str.end()-1; i <= j; i++, j--){
		std::cout << *i << " " << *j << std::endl;
		if(*i != *j){			
			return false;
		}
		
	}
	return true;
}


int main(int argc, char* argv[]){
	std::string arg1 = argv[1];

	if(isPalidrone(arg1))
		std::cout << "Yes!" << std::endl;
	else
		std::cout << "Nope :(" << std::endl;

	return 0;
}
