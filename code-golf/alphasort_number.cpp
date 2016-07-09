// Name: Alphasort Number 
// Author: Joe Greene
// Description: Given a non-negative integer (n), create a function that returns n in alphabetical 
//              order, according to the literal spelling of each digit in n.
// Compilation: Compile using c++11 specifications, e.g.
//   g++ ... -std=c++11
// References: 
// - http://codegolf.stackexchange.com/questions/84814/rearrange-a-number-into-alphabetical-order
//

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

// function definitions are below main
std::string get_str_name(int n);
int get_int(std::string str_name);

int main() {
    std::vector<std::string> number_strings;
    char num;
    
    // to properly get cin to work in a loop
    std::cin >> std::noskipws;
    
    // grab a character until new line not met
    while(std::cin >> num && num != '\n') {
        // move into bounds of 0 to 9
        num = num - '0';
        
        number_strings.push_back(get_str_name(num));
        std::cout << "\'" << number_strings.back() << "\' ";
    }
    
    std::cout << std::endl;
    
    // from <algorithm>
    std::sort(number_strings.begin(), number_strings.end());
    
    for(std::string number_string : number_strings) {
        std::cout << "\'" << number_string << "\' ";
    }
    
    std::cout << std::endl;
    
    for(std::string number_string : number_strings) {
        std::cout << get_int(number_string);
    }
    
    std::cout << std::endl;
    
    return 0;
}

// Convert integer input (0 <= n <= 9) to its string representation
// input: integer n (in range 0 to 9 inclusive)
// output: std::string representation of n
std::string get_str_name(int n) {
    static std::string num_list[] = {"zero","one","two","three","four",
                                     "five","six","seven","eight","nine"};
    
    // out of bounds check (from <algorithm>)
    n = std::max(0, n);
    n = std::min(9, n);
    
    return num_list[n];
}

// Converts std::string to its integer representation
// input: std::string str_name
// output: integer representation (of str_name)
int get_int(std::string str_name) {
    static std::unordered_map<std::string, int> num_list(
        {
            {"zero",0},{"one",1},{"two",2},{"three",3},{"four",4},
            {"five",5},{"six",6},{"seven",7},{"eight",8},{"nine",9}
        }
    );
    
    // error-checking (don't use num_list['invalid'] or else num_list constructs a new element)
    // more info here: http://www.cplusplus.com/reference/unordered_map/unordered_map/operator[]/
    if(num_list.find(str_name) == num_list.end()) {
        return 0;
    }
    
    return num_list[str_name];
}