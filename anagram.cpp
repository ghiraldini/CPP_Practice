#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

int del_num(std::string, std::string);
void print_map(std::unordered_map<char,unsigned int>);


int main(int argc, char* argv[]){
	std::string a = "fcrxzwscanmligyxyvym";
	std::string b = "jxwtrhvujlmrpdoqbisbwhmgpmeoke";

	std::string c = "bugexikjevtubidpulaelsbcqlupwetzyzdvjphn";
	std::string d = "lajoipfecfinxjspxmevqxuqyalhrsxcvgsdxxkacspbchrbvvwnvsdtsrdk";

	int num = del_num(a,b);
	if( num == 30 )
		std::cout << "Correct!" << std::endl;
	else
		std::cout << "WRONG!  " << num << std::endl;
	
	int num2 = del_num(c,d);
	if( num2 == 40 )
		std::cout << "Correct!" << std::endl;
	else
		std::cout << "WRONG!  " << num2 << std::endl;
		

	return 0;
}


int del_num(std::string a, std::string b){
	std::unordered_map<char, unsigned int> cnt_1;
	std::unordered_map<char, unsigned int> cnt_2;
	std::unordered_map<char, unsigned int> comm;
	std::unordered_map<char, unsigned int> commb;
	
	// Get total amount of characters
	int total = a.length() + b.length();

	// Put each character from string 'a' in cnt_1 map
	auto update_a = [&cnt_1](const char& c) { 
		cnt_1.insert( std::pair<char,unsigned int>(c,cnt_1[c]++) );
	};
	std::for_each(a.begin(), a.end(), update_a);

	// Put each character from string 'b' in cnt_2 map
	auto update_b = [&cnt_2](const char& c) { 
		cnt_2.insert( std::pair<char,unsigned int>(c,cnt_2[c]++) );
	};
	std::for_each(b.begin(), b.end(), update_b);

	// Build map of commona chars and count
	// Chars that are in string 'b' but not in string 'a'
	int notComm=0;
	std::for_each(std::begin(b), std::end(b), [&cnt_1, &comm, &notComm] (char c) {
		const auto& it = cnt_1.find(c);		
		if( it != cnt_1.end() ) 
			comm.insert(*it);    
		else 
			notComm++;   
	});

	// Count Chars that are in string 'a' but not in string 'b'
	int notComm2=0;
	std::for_each(std::begin(a), std::end(a), [&cnt_2, &commb, &notComm2] (char c) {
		const auto& it = cnt_2.find(c);		
		if( it == cnt_2.end() ) 			
			notComm2++;   
	});	

	// Characters that are in both strings
	// Get the difference in frequency
	int sum=0;
	for(auto& x: comm){
		int diff_1 = comm[x.first] - cnt_1[x.first];
		int diff_2 = comm[x.first] - cnt_2[x.first];
		sum += abs(abs(diff_1) - abs(diff_2));
	}		
		

	return sum+notComm+notComm2;	
}


void print_map(std::unordered_map<char,unsigned int> m){
	std::cout << "Map Contents" << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "Letter\tCount" << std::endl;
	for (auto& x: m)
		std::cout << x.first << ":\t" << x.second << std::endl;
	std::cout << "----------------------" << std::endl;

	return;
}
