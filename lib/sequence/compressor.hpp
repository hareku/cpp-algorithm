#ifndef LIB_SEQUENCE_COMPRESSOR_HPP
#define LIB_SEQUENCE_COMPRESSOR_HPP 1

#include <bits/stdc++.h>

namespace lib::sequence {

// compressor converts values to sequential numbers.
template <class T> struct compressor {
  public:
    void add(T x) {
        data.push_back(x);
    }

    std::unordered_map<T, int> compress() {
        std::sort(data.begin(), data.end());

        int id = 0;
        std::unordered_map<T, int> val2key;
        for(auto v : data) {
            val2key[v] = id;
            ++id;
        }
        return val2key;
    }

  private:
    std::vector<T> data;
};

}  // namespace lib::sequence

#endif  // LIB_SEQUENCE_COMPRESSOR_HPP
