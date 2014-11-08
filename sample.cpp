#include <iostream>
#include <ctime>

int main(){
    int numOfPairs = 0;
    std::cin >> numOfPairs  ;

    for(int i=0; i<numOfPairs; i++){
        int first,second,revFirst = 0, revSecond = 0;
        std::cin >> first;
        std::cin >> second;
        while (first >= 10) {
            revFirst = (revFirst*10 ) + (first%10) ;
            first /= 10;
        }
        revFirst = (revFirst*10 ) + (first%10) ;
        while (second >= 10) {
            revSecond = (revSecond*10 ) + (second%10) ;
            second /= 10;
        }
        revSecond = (revSecond*10 ) + (second%10) ;
        int result = revFirst + revSecond, revResult = 0 ;
        while (result >= 10) {
            revResult = (revResult*10 ) + (result%10);
            result /= 10;
        }
        revResult = (revResult*10 ) + (result%10) ;
        std::cout << revResult << std::endl;
    }
}
