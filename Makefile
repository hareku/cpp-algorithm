.PHONY: FORCE
FORCE:

main: FORCE
	g++ main.cpp -std=c++23 -I ./ac-library -DLOCAL

bundle.cpp: FORCE
	oj-bundle main.cpp >| bundle.cpp

ojd:
	-rm test/sample-*in test/sample-*out
	oj download $(URL)

.DEFAULT_GOAL := oj
oj: main
	oj test --tle 3
