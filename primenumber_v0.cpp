#include <iostream>
#include <cmath>

bool is_prime(long input);
void fillarray();
long prime_arr[3549]  = {};

int main(){
    int num_of_inputs;
    std::cin >> num_of_inputs;

    fillarray();
    for(int i=0; i< num_of_inputs; i++){
        long input_first,input_second;
        std::cin >> input_first;
        //        std::cout << input_first << std::endl;
        std::cin >> input_second;
        if(input_first == 1){
            input_first = 3;
            if(input_second == 1){
                std::cout << std::endl;
                return 0;
            }
            if(input_second >= 2)
                std::cout << 2 << std::endl;
        }
        if(input_first == 2){
            std::cout << 2 << std::endl;
            input_first = 3;
        }
        if(input_first%2 == 0)
            input_first += 1;

        for(long j=input_first; j<=input_second; j+=2){
            if(is_prime(j) ) std::cout << j << std::endl;
        }
        std::cout << std::endl;
    }
}

void fillarray(){
    prime_arr[0] = 2;
    int fil_idx=1;
    for(long i=3 ; i<33000; i+=2){
        long i_sqrt = sqrt(i);

        for(long j=0; j< fil_idx; j++){
            if(i%prime_arr[j] == 0  ) break;
            else if(prime_arr[j] > i_sqrt){
                prime_arr[fil_idx] = i;
                fil_idx++;
                break;
            }
        }
    }
}

bool is_prime(long input){

    long sqrt_number = sqrt(input);
    for(int i=0; i<3549; i++){
        if(prime_arr[i] <= sqrt_number){
            if(input %prime_arr[i] == 0) return false;
        }
        else  return true;
    }
    return true;
}
