#include <stdlib.h>
#include <stdexcept> //where out_of_range is
#include <new> //where bad_alloc is
#include <exception> // base class for all other exceptions

#include <string>
#include <iostream>
using std::cout;
using std::endl;

template <class T>
class vector {
	private:
		T *v;
		int s;
		int c;
	public:
		vector(){
			s=0;
			v=NULL;
			c = 0;
		}
	  
		~vector(){
			if(v != NULL)
				delete [] v;
			s = 0;
			c = 0;
		}
	  
		vector(vector& other) {
			this->s = other.s;
			this->c = other.c;
			if (other.v != NULL) {
				this->v = new T[c];
				for (int i = 0; i < other.s; i++) {
					this->v[i] = other.v[i];
				}
			}
			else
				this->v = NULL;
		}

		void operator=(vector<T>& other) {
			if (this != &other) {
				if (this->v != NULL) { //make sure the object has no memory allocated
					delete[] this->v;
				}
				this->s = 0;
				this->c = 0;

				this->s = other.s;
				this->c = other.c;
				if (other.v != NULL) {
					this->v = new T[c];
					for (int i = 0; i < other.s; i++) {
						this->v[i] = other.v[i];
					}
				}
				else
					this->v = NULL;
			}
		}

		int size() {
			return s;
		}
	  
		int capacity() {
			return c;
		}

		void push_back(T ele) {
			T *temp;
			if (this->c == 0) {
				temp = new T[1];
				temp[0] = ele;
				this->s = 1;
				this->c = 1;
				this->v = temp;
			}
			else {
				// v is not empty
				if (this->c == this->s) {
					//vector is full
					temp = new T[this->c * 2];
					for (int i = 0; i < this->s; i++)
						temp[i] = this->v[i];
					this->c = this->c * 2;
					temp[this->s] = ele;
					this->s++;
					delete[] this->v;
					this->v = temp;
				}
				else {
					//the vector is not full
					this->v[s] = ele;
					this->s++;
				}
			}
		}

		//Only perform address arithmetic
		T operator[](int index) {
			return this->v[index];
		}

		//Check to make sure not out of bounds
		T at(int index) {
			if(index >= this->s || index <0)
				throw std::out_of_range("out of my vector bounds");
			else 
				return this->v[index];
		}

};
