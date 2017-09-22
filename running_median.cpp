#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <assert.h>


void addNum(int a, 
		std::priority_queue<int, std::vector<int> > *mins,
		std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){
	if(mins->empty() || a < mins->top()){		
		mins->push(a);
	} else {
		maxs->push(a);
	}
}

void rebalance(	std::priority_queue<int, std::vector<int> > *mins,
		std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){

	if(mins->size() > maxs->size()){
		if( mins->size() - maxs->size() >= 2){		
			maxs->push( mins->top() );
			mins->pop();
		}
	} else {
		if( maxs->size() - mins->size() >= 2){		
			mins->push( maxs->top() );
			maxs->pop();
		}
	}	
}

double getMedian( std::priority_queue<int, std::vector<int> > *mins, 
		  std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){ 

	if( mins->size() == maxs->size() ){
		return (double)(mins->top() + maxs->top()) / 2.0;
	} else {
		if(mins->size() > maxs->size())
			return (double)mins->top();	
		else
			return (double)maxs->top();
	}	

}

double get_median(int a,
               	std::priority_queue<int, std::vector<int> > *mins,
	            std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){
    std::cout.precision(1);	
	addNum(a, mins, maxs);	
	rebalance(mins, maxs);
	//std::cout << std::fixed << getMedian(mins, maxs) << std::endl;
	return getMedian(mins, maxs);
}

int main(int argc, char* argv[]){

	std::vector<double> sol;
	std::string line;
	std::string num;
	std::ifstream in("median_sol.txt");
	if(in.is_open()){
		while(std::getline(in,line)){
			std::stringstream ss(line);
			ss >> num;
			sol.push_back(stod(num));
		}
	}
	in.close();


	std::vector<int> sample(1000);
	std::vector<double> my_ans;

	std::priority_queue<int, std::vector<int> > mins;
	std::priority_queue<int, std::vector<int>, std::greater<int> > maxs;
	
	int i=0;
	in.open("median_sample.txt");
	if(in.is_open()){
		while(std::getline(in,line) ){
			std::stringstream ss(line);
			ss >> num;
			sample[i] = stoi(num);
			my_ans.push_back( get_median(sample[i], &mins, &maxs)) );			
			i++;
		}
	}
	in.close();
	std::cout << "Ans size: " << my_ans.size() << " Sol size: " << sol.size() << std::endl;
	std::cout.precision(1);
	for(int i=0; i<sol.size(); i++){
		std::cout << std::fixed << my_ans.at(i) << " == " << sol.at(i) << std::endl;
		//std::cout << i << std::endl;
		assert( sol.at(i) == my_ans.at(i) );
	}


	return 0;
}





/*
-------------------------------------------------------------
		WORKING CODE FROM HACKERRANK
-------------------------------------------------------------
void addNum(int a, 
		std::priority_queue<int, std::vector<int> > *mins,
		std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){
	if(mins->empty() || a < mins->top()){
		mins->push(a);
	} else {
		maxs->push(a);
	}
}

void rebalance(	std::priority_queue<int, std::vector<int> > *mins,
		std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){

	if(mins->size() > maxs->size()){
		if( mins->size() - maxs->size() >= 2){		
			maxs->push( mins->top() );
			mins->pop();
		}
	} else {
		if( maxs->size() - mins->size() >= 2){		
			mins->push( maxs->top() );
			maxs->pop();
		}
	}	
}

double getMedian( std::priority_queue<int, std::vector<int> > *mins, 
		  std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){ 

	if( mins->size() == maxs->size() ){
		return (double)(mins->top() + maxs->top()) / 2.0;
	} else {
		if(mins->size() > maxs->size())
			return (double)mins->top();	
		else
			return (double)maxs->top();
	}	

}

void get_median(int a,
               	std::priority_queue<int, std::vector<int> > *mins,
	            std::priority_queue<int, std::vector<int>, std::greater<int> > *maxs){
    std::cout.precision(1);	
	addNum(a, mins, maxs);	
	rebalance(mins, maxs);
	std::cout << std::fixed << getMedian(mins, maxs) << std::endl;
}


int main(){
  	std::priority_queue<int, std::vector<int> > mins;
	std::priority_queue<int, std::vector<int>, std::greater<int> > maxs;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
       get_median(a[a_i], &mins, &maxs);       
    }
    return 0;
}

*/



