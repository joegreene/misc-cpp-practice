#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;

template<typename T>
void print_vector(string type, vector<T> v) {
    cout << type;
    for(T item : v) {
        cout << item << " ";
    }
    cout << endl;
}

unsigned long long min_candy_count(vector<unsigned long long> score) {
    if(score.size() == 1) {
        return 1;
    }
    
    vector<unsigned long long> candy(score.size(), 1);
    unsigned long long n, i, continue_point, candy_counter = 1, sum = 0;
    
    //print_vector("score: ", score);
    
    for(n = 0; n < candy.size()-1; ++n) {
        if(score[n] < score[n+1]) {
            //cout << "less than: " << score[n] << " " << score[n+1] << endl;
            candy[n+1] = candy[n] + 1;
        }
        else if(score[n] > score[n+1]) { // annoying case if we have decreasing subsequence
            //cout << "greater than: " << score[n] << " " << score[n+1] << endl;
            
            // scan until end of decreasing subsequence (which can be the end of the vector)
            for(i = n; score[i] > score[i+1] && i < candy.size()-1; ++i) {}

            // save continuation point (last element of decreasing subsequence)
            continue_point = i-1;
            
            // go backwards until start of decreasing subsequence
            for(; i > n; --i) {
                candy[i] = candy_counter;
                candy_counter++;
            }
            candy[i] = max(candy[i], candy_counter);
            
            // continue from end of decreasing subsequence
            n = continue_point;
            
            // reset candy_counter
            candy_counter = 1;

            //print_vector("score (lt): ", score);
            //print_vector("candy (lt): ", candy);


        }
        else { // score[n] == score[n+1]
            //cout << "equals: " << score[n] << " " << score[n+1] << endl;
            candy[n+1] = 1;
        }
    }
    
    //print_vector("candy: ", candy);
    
    // accumulate fails for super large sums apparently, so this needs to be done manually
    for(unsigned long long c : candy) {
        sum += c;
    }
    
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<unsigned long long> scores;
    unsigned long long num;
    cin >> num;
    while(cin >> num) {
        scores.push_back(num);
    }
    
    cout << min_candy_count(scores);
    
    return 0;
}
