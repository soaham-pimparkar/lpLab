#include <iostream>
//#include <vector>
//#include <algorithm>
using namespace std;

// void firstFit (int memory[], int processes[], int m, int n){
//     for(int i : processes){
//         for(int j =0; j<m; j++){
//             if(memory[j] > i){
//                 cout<<endl<<"process "<<i<<" placed in memory block "<<j<<".";
//                 memory[j] -= i;
//             }
//         }
//     }
// }

void nextFit (int memory[], int processes[], int m, int n){
    int next_memory = 0;
    for(int i = 0; i<n; i++){
        for(int j =next_memory; j<m+next_memory; j++){
            if(memory[j%m] > processes[i]){
                cout<<endl<<"process "<<i<<" placed in memory block "<<j%m<<".";
                memory[j] -= processes[i];
                next_memory = j%m;
                break;
            }
        }
    }
}

void worstFit (int memory[], int processes[], int m, int n){
    
    for(int i = 0; i<n; i++){
        int best_memory = 0;
        for(int j =0; j<m; j++){
            if(memory[j] > processes[i]){
                //cout<<endl<<"process "<<i<<" placed in memory block "<<j<<".";
                if(memory[j]>=memory[best_memory]){
                    best_memory = j;
                }
                // memory[j] -= processes[i];
                // break;
            }
        }
        cout<<endl<<"process "<<i<<" placed in memory block "<<best_memory<<".";
        memory[best_memory] -= processes[i];
    }
}




int main(){

    int memory[] = {50,200,70,100,150};
    int processes[] = {25, 65, 105, 85, 15};
    int m = sizeof(memory)/sizeof(memory[0]);
    int n = sizeof(processes)/sizeof(processes[0]);

    bestFit(memory, processes, m, n);


    return 0;
}