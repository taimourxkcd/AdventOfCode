#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void findIfSafe(vector<int> digits, bool& isSafe){
        bool increasing = false;
        bool decreasing = false;
        if((digits[1] - digits[0]) > 0) increasing = true;
        else decreasing = true;

        for (int i = 0; i < digits.size() - 1; i++)
        {
            if(increasing){
                if(digits[i+1] - digits[i] < 1 || digits[i+1] - digits[i] > 3){
                    isSafe = false;
                    break;
                }

            }else{
                if(digits[i+1] - digits[i] > -1 || digits[i+1] - digits[i] < -3){
                    isSafe = false;
                    break;
                }
                
            }
        }    

}

void firstProblem(std::vector<std::string> &lines)
{
    int solution = 0;
    vector<int> list1;
    vector<int> list2;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        vector<int> digits;

        stringstream ss(line);
        int num;
        while (ss >> num) {
            digits.push_back(num);
        }

        bool isSafe = true;
        findIfSafe(digits, isSafe);


        if (isSafe){
            solution++;
        }

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

        stringstream ss(line);
        int num;
        while (ss >> num) {
            digits.push_back(num);
        }


        bool isSafe = true;
        findIfSafe(digits, isSafe);

        if (!isSafe)
        {
            for (int i = 0; i < digits.size(); ++i)
            {
                std::vector<int> modifiedDigits = digits;
                modifiedDigits.erase(modifiedDigits.begin() + i);
                bool tempSafe = true;
                findIfSafe(modifiedDigits, tempSafe);

                if (tempSafe)
                {
                    isSafe = true;
                    break;
                }
            }
        }

        if (isSafe)
        {
            solution++;
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




