
# include "split.h"


tuple<char, string> get_args(string input){


    input = trim(input);
    
    // Get first arg
    char first = (input)[0];
    if (first != 'E' && first != 'V'){
        throw std::string("Invalid input");
    }
    
    // Get second arg
    string second = (input).substr(1);
    second = trim(second);
    
    
    if(second.length() == 0) throw std::string("Invalid input");

    // Set args
    return make_tuple(first, second);
}




int get_args_v(string input){

    // remove whitespace in the front and back
    input = trim(input);

    // std::cout << "input: " << input << endl;
    if (!is_number(input)) throw std::string("Invalid input");
    
    // set V
    return std::stoi(input);
}


std::vector<std::tuple<int, int>> get_args_e(string input){

    std::vector<std::tuple<int, int>> E;
    // remove whitespace in the front and back
    input = trim(input);

    if ((input)[0] != '{' || (input)[(input).length()-1] != '}'){
        throw std::string("Invalid input");
    }
    // std::cout << "1111111111111111" << endl;
    // remove whitespace
    (input).erase(std::remove_if((input).begin(), (input).end(), ::isspace), (input).end());

    // std::vector<std::tuple<int, int>> edges;

    // {(0,6),(2,6),(3,4),(4,5),(5,6),(5,7),(6,7)}

    std::smatch match;
    // std::cout << "before regex" << endl;
    regex r_whole("\\{\\<\\d+,\\d+\\>(,\\<\\d+,\\d+\\>)*\\}");
    // std::cout << "after regex" << endl;
    if (!std::regex_match(input, r_whole)) throw std::string("Invalid input");
    // std::cout << "after regex match" << endl;



    regex r_tuple("\\<\\d+,\\d+\\>");

    while (std::regex_search(input, match, r_tuple) == true) {
        
        string node_0 = match.str(0).substr(1, match.str(0).find(',')-1);
        string node_1 = match.str(0).substr(match.str(0).find(',')+1, match.str(0).length()-1-(match.str(0).find(',')+1));

        // std::cout << "node_0: " << node_0 << endl;
        // std::cout << "node_1: " << node_1 << endl;

        input = input.substr(match.str(0).length()+1, input.length()-(match.str(0).length()+1));
        
        // std::cout << "after input: " << input << endl;

        if (!is_number(node_0) || !is_number(node_1)) throw std::string("Invalid input");
        (E).push_back(make_tuple(stoi(node_0), std::stoi(node_1)));
        // std::cout << "after push_back" << endl;
        // if (input.length() == 0) break;

    }

    // std::cout << "after while" << endl;

    return E;
}
