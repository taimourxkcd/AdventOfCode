#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;

void firstProblem(std::vector<std::string> &lines)
{
    int solution = 0;

    regex mul_regex(R"(mul\(\s*(-?\d+)\s*,\s*(-?\d+)\s*\))");
    // R here helps you to write regular expression without escaping backslackes\
    // mul(             : directly matches the given expression
    // \s*              : matches one or more whiespace 
    // (-?d+)           : () here is the capturing group. it kind of encapsulates the digit
    //  -?\             : this matches the optional minus sign - and ? means zero or 1 occurrence
    //  d+              : matches one or more digits from 0-9
    // \s*              : again matches one or more whitespaces
    // ,                : matches comma
    // \s*(-?\d+)\s*\   : the pattern repeats for the number 
    // )                : at the end we match the last closing brace
    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        std::sregex_iterator begin(line.begin(), line.end(), mul_regex);
        std::sregex_iterator end;
    
        for(auto it = begin; it != end; it++){
            int a = stoi((*it)[1].str());
            int b = stoi((*it)[2].str());
            solution += a * b;
        }
    }

    std::cout << solution << std::endl;
}
void secondProblem(std::vector<std::string> &lines)
{
    int solution = 0;

    bool is_enabled = true;
    regex mul_regex(R"(do\(\)|don't\(\)|mul\(\s*(-?\d+)\s*,\s*(-?\d+)\s*\))");

    // (do\(\)|don't\(\)|                : add this part in before the part 1 regex. 
    //                                   : this will match do and don't strings as well. 
    //                                   : '|' this is  used for the as OR operator
    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        std::sregex_iterator begin(line.begin(), line.end(), mul_regex);
        std::sregex_iterator end;

    
        for(auto it = begin; it != end; it++){
            string match = (*it).str();

            if(match == "do()")    is_enabled = true;
            else if(match == "don't()") is_enabled = false;
            else{
                if(is_enabled){
                    string s1 = (*it)[1].str();
                    string s2 = (*it)[2].str();
                    int a = stoi(s1);
                    int b = stoi(s2);
                    solution += a * b;
                }else{
                    // do nothing skip multiplication instructions
                }
            }


        }
    }

    std::cout << solution << std::endl;
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

    while (std::getline(myFile, line))
    {
        if (line.empty())
        {
            break;
        }

        lines.push_back(line);
    }

    firstProblem(lines);
    secondProblem(lines);

    return 0;
}




