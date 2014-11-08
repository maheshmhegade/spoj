#include <iostream>

int main(){
    int number,  counter =0, num_of_inputs;
    std::cin >> num_of_inputs;
    for(int i=0; i< num_of_inputs; i++){
        std::cin >> number;
        counter = 0;
        while(number > 0){
            counter  +=  (number /= 5);
        }
        std::cout << counter << std::endl ;
    }
}
