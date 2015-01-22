
#include <iostream>
#include<vector>

int main(int argc, char *argv[])
{
    std::string input_expression;
    int num_of_inputs;
    std::cin >> num_of_inputs;

    std::string operators = "+ - * / ^";
    std::vector<char> expression_operators;

    for (int num_of_iter = 0 ;num_of_iter< num_of_inputs; num_of_iter++ ){
            std::cin >> input_expression;
    for(int idx_iterator = 0; idx_iterator< input_expression.length(); idx_iterator++){
        int asci_val = (int)input_expression[idx_iterator];
        //        std::streambuf_iterator
        if( (65 <= asci_val && 90 >= asci_val ) || (97 <= asci_val && 122 >= asci_val ) )
            std::cout << input_expression[idx_iterator] ;
        else if( expression_operators.size() > 0 && (operators.find(input_expression[idx_iterator]) <
                                                     operators.find(expression_operators.at(expression_operators.size() - 1)) )  ){
            if(expression_operators.at(expression_operators.size() - 1) != '(' ){
                std::cout <<  expression_operators.at(expression_operators.size() -  1) ;
                expression_operators.pop_back();
            }
            expression_operators.push_back(input_expression[idx_iterator]);
        }
        else if(input_expression[idx_iterator] == ')'){
            int empty_iterator = expression_operators.size() - 1;
            while(expression_operators.at(empty_iterator) != '('){
                std::cout << expression_operators.at(empty_iterator) ;
                expression_operators.pop_back();
                empty_iterator--;
            }
            expression_operators.pop_back();
        }
        else    expression_operators.push_back( input_expression[idx_iterator] );
    }
    for(int idx_iterator = expression_operators.size() -1 ; idx_iterator >=0 ; idx_iterator-- )
        std::cout <<  expression_operators.at(idx_iterator) ;
    std::cout << std::endl;
    }
    return 0;
}
