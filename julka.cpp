#include <iostream>
void find_diff(int* input_total_arr, int* input_diff_arr, int* twice_min_arr, int length1, int length2);

int main(int argc, char *argv[])
{
    std::string input_total, input_diff  ;

    int counter = 10;
    while (counter-- >  0){
        std::cin >> input_total;
        std::cin >> input_diff;
        //    input_total = "6666";
        //    input_diff = "4444";

        int twice_min_arr[1000];
        int input_total_arr[1000], input_diff_arr[1000];
        for(int idx=0; idx < input_total.length() ; idx++)
            input_total_arr[idx] = input_total[idx] - '0';
        for(int idx=0; idx < input_diff.length() ; idx++)
            input_diff_arr[idx] = input_diff[idx] - '0';


        find_diff(input_total_arr, input_diff_arr, twice_min_arr, input_total.length() , input_diff.length());

        int person_one_share[1000], person_two_share[1000] ;
        int idx_one = 0;
        for(int idx=0; idx < input_total.length(); idx++){
            if(idx == 0) person_one_share[idx_one] = (twice_min_arr[idx] / 2);
            else person_one_share[idx_one] = (((10 *(twice_min_arr[idx-1] % 2)) + twice_min_arr[idx] )/ 2);
            idx_one++;
        }

        for(int idx=0; idx < input_total.length() ; idx++)
            input_total_arr[idx] = input_total[idx] - '0';

        find_diff(input_total_arr, person_one_share , person_two_share , input_total.length() , idx_one);

//        if(input_total[0] == '0') std::cout << '0' ;
        bool  can_print = false;
        for(int  idx = 0; idx < input_total.length()  ; idx++){
            if(person_two_share [idx] != 0) can_print = true;
            if(can_print)  std::cout << person_two_share [idx] ;
        }
        std::cout << std::endl;

//        if(input_total[0] == '0') std::cout << '0' ;
        can_print = false;
        for(int  idx = 0; idx < input_total.length()  ; idx++){
            if(person_one_share [idx] != 0) can_print = true;
            if(can_print)  std::cout << person_one_share [idx] ;
        }
        std::cout << std::endl;
    }

    return 0;
}

void find_diff(int* input_total_arr, int* input_diff_arr, int* twice_min_arr, int length1, int length2){

    int idx_diff = length2 -1 ;
    for(int idx = length1 - 1; idx >= 0; idx-- ){
        if(input_total_arr[idx] >= input_diff_arr[idx_diff] && (idx_diff >= 0)){
            twice_min_arr[idx] =  input_total_arr[idx] - input_diff_arr[idx_diff] ;
            idx_diff--;
        }
        else if(idx != 0 && (idx_diff >= 0)){
            twice_min_arr[idx] =  (10 + input_total_arr[idx]) - input_diff_arr[idx_diff] ;
            idx_diff--;
            int backtrace_idx = idx - 1;
            while(input_total_arr[backtrace_idx] == 0){
                input_total_arr[backtrace_idx] = 9;
                backtrace_idx--;
            }
            if(input_total_arr[backtrace_idx] != 0) input_total_arr[backtrace_idx] = input_total_arr[backtrace_idx] - 1;
        }
        else if( idx >= 0 && idx_diff < 0){
            int backtrace_idx = idx;
            while (backtrace_idx >= 0){
                twice_min_arr[backtrace_idx] = input_total_arr[backtrace_idx];
                backtrace_idx--;
            }
            break;
        }
    }
}
