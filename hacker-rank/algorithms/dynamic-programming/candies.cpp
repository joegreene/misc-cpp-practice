/*
    student_score: 3 1 2 2
    student_candy: 1 1 1 1 (initial)

    candy[n]   = 1                 if score[n] == 1
    candy[n]   = score[n+1]+1      if score[n] > score[n+1]
    candy[n+1] = score[n] + 1; ++n if score[n] < score[n+1]
    candy[n+1] = score[n]+1; ++n   if score[n] == score[n+1]
    
    (unsure about last three cases)
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int min_candy_count(vector<int> score) {
    vector<int> candy(score.size(), 1);
    int n;
    
    cout << "score: ";
    for(int s : score) {
        cout << s << " ";
    }
    cout << endl;
    
    for(n = 0; n < candy.size()-1; ++n) {
        cout << "scores: " << score[n] << " " << score[n+1] << endl; 
        if(score[n] == 1) {
           score[n] = 1; // don't really need this if-check here 
        }
        else if(score[n] > score[n+1]) {
            candy[n] = candy[n+1] + 1;
        }
        else if(score[n] < score[n+1]) {
            candy[n+1] = candy[n] + 1; // weird case
        }
        else { // score[n] == score[n+1]
            candy[n+1] = candy[n] + 1; // weird case
        }
        cout << "candies: " << candy[n] << " " << candy[n+1] << endl;
    }
    
    cout << "candy: ";
    for(int c : candy) {
        cout << c << " ";
    }
    cout << endl;
    
    return accumulate(candy.begin(), candy.end(), 0);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int> scores;
    int num;
    cin >> num;
    while(cin >> num) {
        scores.push_back(num);
    }
    
    cout << min_candy_count(scores);
    
    return 0;
}
