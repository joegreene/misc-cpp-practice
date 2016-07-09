// Name: Disjoint Set 
// Author: Joe Greene
// Description: Implementation of a disjoint set data type
// Compilation: Compile using c++11 specifications, e.g.
//   g++ ... -std=c++11
//

#pragma once

//#include <unordered_map>
#include <set>
#include <vector>

namespace jag {
    
    using std::vector;
    using set_type = std::set; // or std::unordered_map
    
    template <typename T>
    class DisjointSet {
        private:
            vector< set_type<T> > _sets;
        public:
            DisjointSet() {
                // to-do
            }
            // make sets per item in arr
            DisjointSet(const vector<T>& arr) {
                for(T& item : arr) {
                    _sets.push_back(set_type<T>())
                    _sets.back().
                }
            }
            ~DisjointSet() {
                // to-do
            }
            
            void create_set(const T& x) {
                _sets.push_back(set_type<T>());
                _sets.back().insert(x);
            }

            void merge_sets(const T& x, const T& y) {
                for() {
                    
                }
            }
            
            const set_type& find_set(const T& x) {
                
            }
    };
}
