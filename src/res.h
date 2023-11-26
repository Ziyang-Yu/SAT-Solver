
# include <iostream>
# include <string> 
# include <bits/stdc++.h>
#include <algorithm> 
#include <cctype>
#include <locale>

#include "../minisat/minisat/core/Solver.h"
#include "../minisat/minisat/core/SolverTypes.h"

using namespace std;

std::vector<int> sat_solver(int k, tuple<int, std::vector<tuple<int, int>>> G);
string solution(tuple<int, std::vector<tuple<int, int>>> G);
