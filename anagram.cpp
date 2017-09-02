#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

int del_num(std::string, std::string);
void print_map(std::unordered_map<char,unsigned int>);


int main(int argc, char* argv[]){
	std::string a = "cdddd";
	std::string b = "cd";

	int num = del_num(a,b);
	std::cout << "Number of deletions to create anagram: " << num << std::endl;

	return 0;
}

int del_num(std::string a, std::string b){
	std::unordered_map<char, unsigned int> cnt_1;
	std::unordered_map<char, unsigned int> common;
	
	// Get total amount of characters
	int total = a.length() + b.length();

	// Put each character in cnt_1 map
	std::for_each(std::begin(a), std::end(a), [&cnt_1](char c) {
		cnt_1[c]++;
	});

	// If this character is also in cnt_1 map,
	// insert it to this map also
	std::for_each(std::begin(b), std::end(b), [&cnt_1, &common] (char c) {
		const auto& it = cnt_1.find(c);
		if( it != cnt_1.end()) common.insert(*it);        
	});

//	print_map(common);
	return total-common.size()*2;
	
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
