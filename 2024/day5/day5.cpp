#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <map>
#include <unordered_map>
#include <algorithm>

using namespace std;


vector<int> locate_valid_lists(vector<pair<int, int>>& pairs, vector<vector<int>>& page_vec){

    vector<int> validate_middles;

    for(const auto &update : page_vec){
        bool is_valid = true;
        for(const auto &[first, second] : pairs){
            auto it_first  = find(update.begin(), update.end(), first);
            auto it_second = find(update.begin(), update.end(), second);

            if(it_first != update.end() && it_second != update.end()){
                if(it_first > it_second){
                    is_valid = false;
                    break;
                }
            }
        }

        if(is_valid){
            validate_middles.push_back(update[update.size() / 2]);
        }
    }

    return validate_middles;
}


void firstProblem(std::vector<std::string> &lines)
{
    unordered_map<int, vector<int>> map;
    vector<vector<int>> updates;
    vector<int> temp;
    int solution = 0;
    bool found_empty_line = false;
    vector<pair<int, int>> pairs;

    for (int i = 0; i < lines.size(); i++){
        string line = lines[i];
        if(line.size() == 0){
            found_empty_line = true;
            continue;
        }
        if(found_empty_line){
            int m = 0, n = 0;
            int line_size = line.size(); // for debugging
            while(n < line.size()){
                while(line[n] != ','){
                    if(n == line.size() ){
                        break;
                    }
                    char ch = line[n]; // for debugging
                    n++;

                }
                int digit = stoi(line.substr(m, n));
                temp.push_back(digit);
                m = n + 1;
                n++;
            }
            updates.push_back(temp);
            temp.clear();                                 
        }else{
            int j = 0;
            while(line[j] != '|'){
                j++;
            }
            int k = j+1;
            int digit1 = stoi(line.substr(0, j));        
            while(j < line.size()){
                j++;
            }
            int digit2 = stoi(line.substr(k, j));                
            pairs.push_back(make_pair(digit1, digit2));

        }
    }
    
    vector<int> vaidated_data = locate_valid_lists(pairs, updates);
    for(int n : vaidated_data){
        solution += n;
    }

    cout << solution << endl;
}


int main()
{
    std::ifstream myFile;

    myFile.open("input.txt");

    if (!myFile.is_open())
    {
        std::cout << "Unable to open file" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<std::string> lines;


    while (std::getline(myFile, line)){
        lines.push_back(line);
    }

    firstProblem(lines);

    return 0;
}