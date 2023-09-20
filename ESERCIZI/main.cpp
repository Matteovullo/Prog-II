#include <iostream>
#include "Stack_2.h"

using namespace std;

int main(){
    Stack<int> s;
    s.push(10);
	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
    std::cout << s << std::endl;
}