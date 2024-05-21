// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi1(int n, char from_rod, char to_rod,
                  char aux_rod,int &count)
{
    if (n == 0) {
        return;
    }
  
    towerOfHanoi1(n - 1, from_rod, aux_rod, to_rod,count);
    count++;
    towerOfHanoi1(n - 1, aux_rod, to_rod, from_rod,count);
}
void towerOfHanoi(int n, char from_rod, char to_rod,
                  char aux_rod)
{
    if (n == 0) {
        return;
    }
    
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout<< (int)(from_rod-'A'+1)<<" "<< (int)(to_rod-'A'+1) << endl;
    
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int N;
    cin>>N;
     int count=0;
    // A, B and C are names of rods
    towerOfHanoi1(N,'A','C','B',count);
    cout<<count<<endl;
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}

// This is code is contributed by rathbhupendra
