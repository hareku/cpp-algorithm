a.out: FORCE
	g++ main.cpp -std=c++20 -I ./ac-library -DLOCAL

bundle.cpp: FORCE
	oj-bundle main.cpp >| bundle.cpp

FORCE:
.PHONY: FORCE
