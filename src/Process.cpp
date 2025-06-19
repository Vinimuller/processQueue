#include "../inc/classes/Process.h"


// // Example usage
// int main() {
//     std::cout << "\n\n" << "------- Start -------" << "\n\n";

//     FIFO<Process*> processQueue;
//     processQueue.push(new Writing_Process("1+1", 1));
//     processQueue.push(new Writing_Process("3*4", 2));
//     processQueue.push(new Writing_Process("4/4", 3));
//     processQueue.push(new Writing_Process("20-5", 4));
//     processQueue.push(new Reading_Process(processQueue, 5));

//     while(processQueue.getSize() > 0){
//         executeNextProcess(processQueue);
//     }

//     return 0;
// }
