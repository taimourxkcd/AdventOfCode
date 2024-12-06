#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void firstProblem(std::vector<std::string> &lines)
{
    int solution = 0;
    vector<int> list1;
    vector<int> list2;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        vector<int> digits;

        string temp = "";
        for (int i = 0; i < line.size(); i++)
        {
            if(digits.size() == 2) break;
            if (line[i] != ' ' && digits.size() == 0)
            {
                temp += line[i];
            }
            if(line[i] == ' ' && digits.size() == 0)
            {
                digits.push_back(stoi(temp));

            }

            if (digits.size() > 0 && line[i] != ' ')
            {
                int temp_digit = stoi(line.substr(i, line.size()));
                digits.push_back(temp_digit);
            }
        }

        list1.push_back(digits[0]);
        list2.push_back(digits[1]);
        digits.clear();
    }

    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());

    for (int i = 0; i < list1.size(); i++)
    {
        int diff = abs(list1[i] - list2[i]);
        solution += diff;
    }

    std::cout << solution << std::endl;
}


void secondProblem(std::vector<std::string> &lines)
{
    int solution = 0;
    vector<int> list1;
    vector<int> list2;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        vector<int> digits;

        string temp = "";
        for (int i = 0; i < line.size(); i++)
        {
            if(digits.size() == 2) break;
            if (line[i] != ' ' && digits.size() == 0)
            {
                temp += line[i];
            }
            if(line[i] == ' ' && digits.size() == 0)
            {
                digits.push_back(stoi(temp));

            }

            if (digits.size() > 0 && line[i] != ' ')
            {
                int temp_digit = stoi(line.substr(i, line.size()));
                digits.push_back(temp_digit);
            }
        }

        list1.push_back(digits[0]);
        list2.push_back(digits[1]);
        digits.clear();
    }

    unordered_map<int, int> map;
    for(int n : list2){
        map[n]++;
    }

    for (int i = 0; i < list1.size(); i++)
    {
        if(map.find(list1[i]) != map.end()){
            int temp = list1[i] * map[list1[i]];
            solution += temp;
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

