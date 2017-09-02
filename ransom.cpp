#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::string ransom_note(std::vector<std::string>, std::vector<std::string>);
void print_map(std::unordered_map<std::string, unsigned int> m);

int main(int argc, char* argv[]){
	int n=6,m=4;

	std::vector<std::string> note;
	std::vector<std::string> magazine;

	note.push_back("give");
	note.push_back("me");
	note.push_back("grand");
	note.push_back("today");

	magazine.push_back("give");
	magazine.push_back("me");
	magazine.push_back("one");
	magazine.push_back("grand");
	magazine.push_back("today");
	magazine.push_back("night");

	std::cout << ransom_note(note, magazine) << std::endl;

	
	return 0;
}


std::string ransom_note(std::vector<std::string> n, std::vector<std::string> m){
	std::unordered_map<std::string, unsigned int> mag_cnt;
	std::unordered_map<std::string, unsigned int> useable;
	int cnt = 1;
	
	for(int i=0; i<m.size(); i++){
		mag_cnt.insert( std::make_pair<std::string, unsigned int>(m.at(i),cnt) );	
	}
	print_map(mag_cnt);
}

void print_map(std::unordered_map<std::string, unsigned int> m){
	std::cout << "Contents of map" << std::endl;
	for(auto& x: m){
		std::cout << x.first << ":\t" << x.second << std::endl;
	}

}
