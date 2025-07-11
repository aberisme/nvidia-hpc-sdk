#include <iostream>
#include <chrono>

using namespace std;

int main() {
	int a[300000] = {0};
	int sumpair[150000] = {0};
	
	// ground truth total of a
	int sum = 0;

	// initialize a
	for(int i = 0; i < 300000; i++) {
		a[i] = i + 1;
		sum += i; // total of all values of a
	}

	auto start = std::chrono::high_resolution_clock::now();
	
	#pragma acc data copyin(a, sumpair), copyout(sumpair)
	{
		#pragma acc parallel
		{
			#pragma acc loop independent
			for(int i = 0; i < 150000; i++) { // sum of pairs
					  
				sumpair[i] = a[i*2] + a[(i*2)+1];

			}
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = end - start;
	auto duration_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(duration);

	int sum2 = 0; // for checking of sumpairs
	for(int i = 0; i < 150000; i++) {
		sum2 += sumpair[i];
	}
	
	cout << "Time Duration: " << duration_ns.count() << " ns --- [PARALLEL] --- ";
	cout << "Ground Sum: " << sum << " ... Sum of Pairs: " << sum2 << endl;

	return 0;
}
