#include <iostream>
#include <string>
#include <stack>
#include <vector>

bool is_balanced(std::string);
bool is_pair(char l, char r);
void print_stack(std::stack<char,std::vector<char>> s);

int main(int argc, char* argv[]){
	std::string test_1 = "{[()]}"; 		// YES
	std::string test_2 = "{[(])}"; 		// NO
	std::string test_3 = "{{[[(())]]}}";	// YES

	std::string a = "}][}}(}][))]"; 	// NO
	std::string b = "[](){()}";		// YES
	std::string c = "()";			// YES
	std::string d = "({}([][]))[]()"; 	// YES
	std::string e = "{)[](}]}]}))}(())("; 	// NO

//	std::cout << "Balanced: " << is_balanced(test_3) << std::endl;
	std::cout << "Balanced: " << is_balanced(a) << std::endl;
	std::cout << "Balanced: " << is_balanced(b) << std::endl;
	std::cout << "Balanced: " << is_balanced(c) << std::endl;
	std::cout << "Balanced: " << is_balanced(d) << std::endl;
	std::cout << "Balanced: " << is_balanced(e) << std::endl;

	return 0;
}



bool is_balanced(std::string expression) {
	std::stack< char, std::vector<char> > brack_stack;
	int pops=0, pushes=0;

	for (std::string::const_iterator i=expression.begin(); i < expression.end(); i++){
		if( *i == '{'  ||
		    *i == '['  ||
		    *i == '(' ) {			
			// push to stack;
			brack_stack.push(*i);
			pushes++;
		} else if ( *i == '}'  ||
			    *i == ']'  ||
			    *i == ')' ) {			
			// pop from stack
			if(brack_stack.empty()) // catch if 1st element
				return false;
			
			char c = brack_stack.top();
			std::cout << "Comparing: " << c << " & " << *i << std::endl;
			if(!is_pair(c,*i))
				return false;
			if(!brack_stack.empty()){
				brack_stack.pop();
				pops++;
			}
		}	
		
	}
	if(pops != pushes) return false;
	return true;
}

void print_stack(std::stack<char,std::vector<char>> s){
	std::cout << "Stack: ";
	while(!s.empty()){
		std::cout << s.top();
		s.pop();
	}
	std::cout << "" << std::endl;
}

bool is_pair(char l, char r){
	const std::string P1 = "{}";
	const std::string P2 = "[]";
	const std::string P3 = "()";

	std::string candidate = "";
	candidate = l;
	candidate += r;

	if(candidate == P1 || candidate == P2 || candidate == P3)
		return true;

	return false;
}















