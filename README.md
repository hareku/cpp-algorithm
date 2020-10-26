# Algorithm library (C++)

## Setup

### 1. Clone this repository

```bash
# clone with submodules
$ git clone --recurse-submodules https://github.com/hareku/cpp-algorithm
```

### 2. Open with `VSCode Remote Container` or Install dependencies

You can easily start with [VSCode Remote Container](https://code.visualstudio.com/docs/remote/containers) without installing dependencies.

If you develop locally or want to use other editors, install some dependencies. Check out [Dockerfile](.devcontainer/Dockerfile).

### 3. Build `main.cpp` and run it

```bash
# create main.cpp
$ cp main.template.cpp main.cpp

# build main.cpp
$ make a.out

# execute binary
$ ./a.out

# bundle `main.cpp` and including libraries for submission (e.g AtCoder)
$ make bundle.cpp
$ cat bundle.cpp # bundled code
```

## How to use algorithm library

Example code for `lib/math/divisors.hpp`

```cpp
#include <bits/stdc++.h>
#include "lib/math/divisors.hpp"
using namespace std;

int main() {
  int N; cin >> N;
  vector<long long> divisors = lib::math::divisors(N);

  for(int i = 0; i < int(divisors.size()); ++i) {
    cout << divisors[i] << endl;
  }

  return 0;
}
```

## How to test

This library is tested by [Verification Helper](https://github.com/online-judge-tools/verification-helper).

```bash
# run all tests
$ oj-verify all

# run specific test
$ oj-verify run test/math/primes.test.cpp
```
