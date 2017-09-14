#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
#include <assert.h>

class MyQueue {
  
    public:
        std::stack<int> stack_newest_on_top, // in
			stack_oldest_on_top; // out   

	// enqueue - Push to top of stack
        void push(int x) {
		//std::cout << "Pushing " << x << std::endl;
		stack_newest_on_top.push(x);							
        }

	// dequeue - Remove head of queue
        void pop() {
		if(stack_oldest_on_top.empty()){
			//std::cout <<  "Old is empty, filling with new on top" << std::endl;
		    	while(!stack_newest_on_top.empty()){
				stack_oldest_on_top.push( stack_newest_on_top.top() );
				stack_newest_on_top.pop();			
			}		
		}
		stack_oldest_on_top.pop(); // remove head		
        }

	// print value at head of queue
        int front() {
		if(stack_oldest_on_top.empty()){
			//std::cout <<  "Old is empty, filling with new on top" << std::endl;
		    	while(!stack_newest_on_top.empty()){
				stack_oldest_on_top.push( stack_newest_on_top.top() );
				stack_newest_on_top.pop();			
			}		
		}
		return stack_oldest_on_top.top();
        }
};

// NEWEST ON TOP
//	PUSH	PUSH	POP	PUSH	PUSH	PUSH	
//	--------------------------------------------
//	76	33	33	23	91	21
//		76		33	23	91
//					33	23
//						33
				
int main(int argc, char* argv[]){
	MyQueue q1;
	int q, num;
	std::string line,key;
	std::vector<int> ans,
			 sol;

	
	
	std::ifstream in("solution.txt");
	if(in.is_open()){
		while(std::getline(in,line)){
			std::stringstream ss(line);
			ss >> num;
			sol.push_back(num);
		}			
	}
	in.close();
	
	
	in.open("sample_queue.txt");
	if(in.is_open()){
		while(std::getline(in,line)){
			std::stringstream ss(line);
			ss >> key;
			if(key == "1"){
				ss >> q;
				q1.push(q);
			}
			if(key == "2"){
				q1.pop();
			}
			if(key == "3"){
				//std::cout << q1.front() << std::endl;			
				ans.push_back(q1.front());
			}
			
		}
	}
	in.close();

	for(int i=0; i<sol.size(); i++){
//		std::cout << i << std::endl;
		assert( ans.at(i) == sol.at(i) );
	}

	return 0;
}
