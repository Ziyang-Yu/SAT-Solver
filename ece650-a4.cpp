# include <iostream>
# include <string> 
# include <bits/stdc++.h>
#include <algorithm> 
#include <cctype>
#include <locale>

#include "minisat/minisat/core/Solver.h"
#include "minisat/minisat/core/SolverTypes.h"
#include "src/utils.h"
#include "src/split.h"
#include "src/res.h"
// # include "src/data/graph.h"
// # include "src/data/edge.h"
// # include "src/utils.h"

using namespace std;





int main(int argc, char** argv)
{   

    
    string input;
    int V;
    std::vector<tuple<int, int>> E;
    tuple<int, std::vector<tuple<int, int>>> G;

    tuple<char, string> args;

    while(!std::cin.eof()) {
        try{

            // handle input
            getline(cin,input);

            if (input.size() == 0) continue;
            
            // get first and second arguments
            // std::cout << "before get_args" << endl;
            args =  get_args(input);
            // std::cout << "after get_args" << endl;
            // std::cout << "args: " << get<0>(args) << " " << get<1>(args) << endl;
            // std::cout << "type(args): " << typeid(args).name() << endl;
            // std::cout << "type(args 0): " << typeid(get<0>(args)).name() << endl;
            // std::cout << "type(args 1): " << typeid(get<1>(args)).name() << endl;
            // std::cout << "get<0>(args) == 'V': " << (get<0>(args) == 'V') << endl;

            if (get<0>(args) == 'V'){
                // std::cout << "after if " << endl;
                E.clear();
                // std::cout << "before V" << endl;
                V = get_args_v(get<1>(args));
                // std::cout << "after V" << endl;
            }
            else if (get<0>(args) == 'E'){

                // Get second arg
                if (V == 0) throw std::string("Invalid input");
                if (E.size() != 0) throw std::string("Invalid input");
                E = get_args_e(get<1>(args));
                // std::cout << "Delimater Here" << endl;
                
                // std::cout << "V: " << V << endl;
                // std::cout << "E: " << E << endl;
                // std::cout << "before make_tuple" << endl;
                G = make_tuple(V, E);
                // std::cout << "after make_tuple" << endl;



                string res = solution(G);
                cout << res << endl;

                V = 0;
                E.clear();
                G = make_tuple(V, E);
            }
            else{
                throw std::string("Invalid input");
            }

        }
        catch (string e) {
            std::cerr << "Error: " << e << endl;
        }
    }
    return 0;

}
