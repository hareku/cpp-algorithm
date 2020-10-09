a.out: FORCE
	g++ main.cpp -std=c++14 -I ./ac-library -DLOCAL

bundle.cpp: FORCE
	oj-bundle main.cpp >| bundle.cpp

FORCE:
.PHONY: FORCE
