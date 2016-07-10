// Name: Bidirectional Map 
// Author: Joe Greene
// Description: Implementation of a bidirectional map data type
// Compilation: Compile using c++11 specifications, e.g.
//   g++ ... -std=c++11
//

#pragma once

#include <unordered_map>
#include <vector>

namespace jag {
    
    template <typename X, typename Y>
    class BidirectionalMap {
        private:
            std::unordered_map<X, Y>
        public:
            BidirectionalMap() {
                // to-do
            }
            ~BidirectionalMap() {
            
            }
            // to-do
    };
}
