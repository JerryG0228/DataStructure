//
//  Lab02-1.cpp
//  Lab02
//
//  Modifieid by Jeman Park on 2023/09/25.
//

#include <iostream>
#include "binary_search.h"
using namespace std;


int main() {
    /* Feel free to edit codes below (test with more cases) */
    
    // Assume that all numbers in list are "unique" (no duplicated items)
    int list[10] = {1, 2, 3, 4, 5, 7, 9, 10, 11, 12};
    
    // 6 is not in list -> result = -1
    int result = binary_search(list, 10, 6);
    cout << result << endl;
    
    // 7 is in list -> result = 5 (index of "7")
    result = binary_search(list, 10, 7);
    cout << result << endl;
    
    
    // 5 is in list -> result = 4 (index of "5")
    result = binary_search_min(list, 10, 5);
    cout << result << endl;
    
    // 6 is not in list -> result = 5 (minimum number which is bigger than 6 = "7")
    // index of "7" = 5
    result = binary_search_min(list, 10, 7);
    cout << result << endl;
    
    
    
    
    // 10 is in list -> result = 7 (index of "10")
    result = binary_search_max(list, 10, 10);
    cout << result << endl;
    
    // 14 is not in list -> result = 9 (maximum number which is less than 14 = "12")
    // index of "12" = 9
    result = binary_search_max(list, 10, 14);
    cout << result << endl;
    
    return 0;
}
