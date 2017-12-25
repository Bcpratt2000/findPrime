//g++ Main.cpp -o Main -lpthread -std=gnu++11

#include <iostream>
#include <thread>
#include <future>

#define NUM_THREADS 1024

using namespace std;

class Util{
	public:
	static int isPrime(int number){
		for(int i = 2; i < number/2; i++){
			if(!(number%i)){
				return 0;
			}	
		}
	return number;
	}
};

int main(){
	future<int> threads[NUM_THREADS];
	int tempInt;

	for(int i=1; i<1000000000;){
		for(int t=0; t<NUM_THREADS; t++){
			threads[t] = async(launch::async, Util::isPrime, i);
			i++;
		}
		for(int t=0; t<NUM_THREADS; t++){
			tempInt = threads[t].get();
			if(tempInt != 0){
				cout << tempInt << endl;
			}
		}
	}
	return 0;
}
