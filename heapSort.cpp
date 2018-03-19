//compare naiive sorting algorithm with heapsort

#include <iostream>
#include <queue>

using namespace std;

void selectionSort(int* a, int N){
	//Precondition: unsorted array
	//Post condition: sorted array in ascending order
	for(int i =0; i<N; i++){ // N times
		int minElem = a[i];
		int index=i;
		for(int j = i+1; j<N;j++){ // 
			//Constant time
			if(a[j]<minElem){
				minElem = a[j];
				index = j;
			}
		}
		int tmp = a[i];
		a[i] = a[index];
		a[index]=tmp;
	}

}
/*
N-1 + N-2 + N -3  +.    N-(N-1)
= N*N - (1+2 + 3+ ...(N))
= N^2 -  N(N+1)/2
= N^2 - N^2/2 -N/2
= N^2/2 - N/2

*/
//Big - O N^2
void heapSort(int* a, int N){
	//Precondition: unsorted array
	//Post condition: sorted array in ascending order 
	// using priority_queue
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int j = 0; j<N;j++){ // 
		pq.push(a[j]);
	}
	for(int j = 0; j<N;j++){ // 
		a[j]=pq.top();
		pq.pop();
	}


}




int main(){
	int arr1[]={7, 23, 15, 96, 42, -10, 112, 0, 360, 80};
	int arr2[]={7, 23, 15, 96, 42, -10, 112, 0, 360, 80};

	cout<<"Original array\n";
	for( auto item: arr1){
		cout<<item<<" ";
	}
	cout<<endl;
	selectionSort(arr1, 10);

	cout<<"Output of selectionSort\n";
	for( auto item: arr1){
		cout<<item<<" ";
	}
	cout<<endl;

	heapSort(arr2, 10);

	cout<<"Output of heapSort\n";
	for( auto item: arr2){
		cout<<item<<" ";
	}
	cout<<endl;


}
