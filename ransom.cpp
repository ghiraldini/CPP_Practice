#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool ransom_note(std::vector<std::string>, std::vector<std::string>);
void print_map(std::unordered_map<std::string, unsigned int> m);

int main(int argc, char* argv[]){
	int n=6,m=4;

	// True
	std::vector<std::string> note = {"elo", "lxkvg", "bg", "mwz", "clm", "w"};
	std::vector<std::string> magazine = {"apgo", "clm", "w", "lxkvg", "mwz", "elo", "bg", "elo", "lxkvg", "elo", "apgo", "apgo", "w", "elo", "bg"};
/*
	note.push_back("two");
	note.push_back("times");
	note.push_back("two");
	note.push_back("is");
	note.push_back("four");

	magazine.push_back("two");
	magazine.push_back("times");
	magazine.push_back("three");
	magazine.push_back("is");
	magazine.push_back("not");
	magazine.push_back("four");
*/
	std::cout << ransom_note(magazine, note) << std::endl;

	
	return 0;
}


bool ransom_note(std::vector<std::string> magazine, std::vector<std::string> ransom){
	std::unordered_map<std::string, unsigned int> note;
	std::unordered_map<std::string, unsigned int> mag;
	std::unordered_map<std::string, unsigned int> comm;
	bool ret = true;

	// Add magazine words to map
	auto updateMag = [&mag](std::string &myStr){
		mag.insert( std::pair<std::string,unsigned int> (myStr,mag[myStr]++) ); 
	};
	std::for_each(std::begin(magazine), std::end(magazine), updateMag);

	// Add ransom words to map & see if there are words that
	// are not included in magazine
	auto updateNote = [&note, &mag, &ret](std::string &myStr){
		note.insert( std::pair<std::string,unsigned int> (myStr,note[myStr]++) ); 
		const auto& it = mag.find(myStr);
		if( it == mag.end() ){
			ret = false;
		}
	};
	std::for_each(std::begin(ransom), std::end(ransom), updateNote);
	
	// Check if there are the same frequency of common words
	for(auto& x: note){
		if( (float)note[x.first] - (float)mag[x.first] > 0 ){
			ret = false;
		}
	}

	return ret;
}

void print_map(std::unordered_map<std::string, unsigned int> m){
	std::cout << "Contents of map" << std::endl;
	for(auto& x: m){
		std::cout << x.first << ":\t" << x.second << std::endl;
	}

}
