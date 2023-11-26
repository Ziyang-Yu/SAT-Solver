#include "res.h"



std::vector<int> sat_solver(int k, tuple<int, std::vector<tuple<int, int>>> G){

    int n;
    std::vector<tuple<int, int>> E;

    n = get<0>(G);
    E = get<1>(G);

    
    // Create variables
    Minisat::Solver solver;
    std::vector<std::vector<Minisat::Var>> vars;
    for (int i = 0; i < n; i++){
        std::vector<Minisat::Var> temp;
        for (int j = 0; j < k; j++){
            Minisat::Var v = solver.newVar();
            temp.push_back(v);
        }
        vars.push_back(temp);
    }  // (n, k)

    // At least one vertex is the ith vertex in the vertex cover:
    for (int i = 0; i < k; i++){
        Minisat::vec<Minisat::Lit> clause;
        for (int j = 0; j < n; j++){
            clause.push(Minisat::mkLit(vars[j][i]));
        }
        solver.addClause(clause);
    }

    // No one vertex can appear twice in a vertex cover:
    for (int i = 0; i < n; i++){
        for (int j = 0; j < k; j++){
            for (int m = 0; m < k && m != j; m++){
                Minisat::vec<Minisat::Lit> clause;
                clause.push(~Minisat::mkLit(vars[i][j]));
                clause.push(~Minisat::mkLit(vars[i][m]));
                solver.addClause(clause);
            }
        }
    }

    // No more than one vertex appears in the mth position of the vertex cover:
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            for (int m = 0; m < n && m != j; m++){
                Minisat::vec<Minisat::Lit> clause;
                clause.push(~Minisat::mkLit(vars[j][i]));
                clause.push(~Minisat::mkLit(vars[m][i]));
                solver.addClause(clause);
            }
        }
    }

    // Every edge is incident to at least one vertex in the vertex cover:
    for (int i = 0; i < E.size(); i++){
        Minisat::vec<Minisat::Lit> clause;
        for (int j = 0; j < k; j++){
            clause.push(Minisat::mkLit(vars[get<0>((E)[i])-1][j]));
            clause.push(Minisat::mkLit(vars[get<1>((E)[i])-1][j]));
        }
        solver.addClause(clause);
    }

    // for (int i = 0; i < clauses.size(); i++){
    //     solver.addClause(clauses[i]);
    // }

    bool exist = solver.solve();

    if (exist){
        
        std::vector<int> res;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < k; j++){
                if (Minisat::toInt(solver.modelValue(vars[i][j])) == 0) res.push_back(i+1);
            }
        }
        return res;
    }
    else{
        std::vector<int> res;
        return res;
    }


}

string solution(tuple<int, std::vector<tuple<int, int>>> G){

    for (int k = 1; k <= get<0>(G); k++){
        std::vector<int> res = sat_solver(k, G);
        std::sort(res.begin(), res.end());
        if (res.size() != 0){
            string s = "";
            for (int i = 0; i < res.size(); i++){
                s += std::to_string(res[i]);
                if (i != res.size() - 1) s += " ";
            }
            return s;
        }
    }

}