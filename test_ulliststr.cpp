#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr List; 

  // //test for push_back
  // List.push_back("aa");

  // cout << List.front() << endl;
  // cout << List.back() << endl;
  // cout << List.get(0) << endl;

  // List.push_back("bbb");
  // List.push_back("cc");

  // cout << List.get(1) << endl;
  // cout << List.get(2) << endl;

  // //test for push_front
  // List.push_front("front test");
  // cout << List.front() << endl;

  // List.push_front("front test 2");
  // cout << List.front() << endl;
  // cout << List.get(1) << endl;

  // List.push_front("front test 3");
  // cout << List.front() << endl;

  // //test for pop_back and pop_front
  // List.pop_back();
  // cout << List.back() << endl;
  // List.pop_front();
  // cout << List.front() << endl;


  List.push_front("768");
  cout << List.front() << endl;

  List.push_front("1024");
  cout << List.get(0) << endl;
  cout << List.get(1) << endl;


  List.push_front("1536");
  cout << List.get(0) << endl;
  cout << List.get(1) << endl;
  cout << List.get(2) << endl;


  // std::vector<std::string> contents{"768", "1024", "1536"};

  // 	ULListStr * list = new ULListStr();

  // 		for(std::vector<std::string>::const_reverse_iterator valuesIter = values.crbegin(); valuesIter != values.crend(); ++valuesIter)
	// 	{
	// 		list->push_front(*valuesIter);
	// 	}

  //   cout << list.get(0) << endl;

}
