#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;

int main (){
   vector<int> v;   //Our vector class
   std::vector<int> stdv; //Standard vector

   //Compare operation of our vector to std
   v.push_back(23);
   stdv.push_back(23);

   cout << "Our vector size: " << v.size() << endl;
   cout << "Our vector capacity: " << v.capacity() << endl;
   cout << "STL vector size: " << stdv.size() << endl;

   vector<int> v2 = v;   //using copy constructor
   cout << "Our vector2 size: " << v2.size() << endl;


   vector<int> v3;
   v3 = v; //using assignment operator overload
   cout << "Our vector3 size: " << v3.size() << endl;

   try {
	   cout << v[0] << endl;
	   cout << v.at(0) << endl;
	   cout << v.at(-1) << endl;
	   cout << v.at(10000) << endl;
   }

   catch (std::out_of_range &e) {
	   cout << e.what() << endl;
   }

   //adding more ints
   for (int i = 0; i < 10; i++) {
	   v.push_back(i+5);
	   cout << "Our vector size: " << v.size() << endl;
	   cout<< "Our vector capacity: " << v.capacity() << endl;
	   cout << "-------------------------" << endl;
   }

   return 0;
}

