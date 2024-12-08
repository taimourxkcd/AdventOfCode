#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>

using namespace std;




// did not pass all the test cases. 
// maybe its couting duplicates or something.
void firstProblemFirstSolution(std::vector<std::string> &lines)
{
    vector<vector<char>> words_matrix(lines.size());
    int solution = 0;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        for(int j = 0; j < line.size(); j++){
            char ch = line[j];
            words_matrix[i].push_back(line[j]);
        }

    }

    int rows = words_matrix.size();
    int cols = words_matrix[0].size();
    int word_length = 4;

        // count in rows. 
   for (int i = 0; i < rows; i++){
        for(int j = 3; j <= cols - word_length; j++){
            if(words_matrix[i][j]     == 'X' &&
               words_matrix[i][j+1]   == 'M' &&
               words_matrix[i][j+2]   == 'A' &&
               words_matrix[i][j+3]   == 'S'
            ){
                solution++;
            }
        }
    }

    // count in columns. 
    for (int i = 0; i <= rows - word_length; i++){
        for(int j = 0; j < cols; j++){
            if(words_matrix[i][j]     == 'X' &&
               words_matrix[i+1][j]   == 'M' &&
               words_matrix[i+2][j]   == 'A' &&
               words_matrix[i+3][j]   == 'S'
            ){
                solution++;
            }
        }
    }

    
        // check in the main diagonal
        for(int i = 0; i <= rows - word_length; i++){
            for(int j = 0; j <= cols - word_length; j++){
                if(words_matrix[i][j]        == 'X' &&
                    words_matrix[i+1][j+1]   == 'M' &&
                    words_matrix[i+2][j+2]   == 'A' &&
                    words_matrix[i+3][j+3]   == 'S'
                    ){
                        solution++;
                    }                  

            }
        }        

        // check in the antidiagonal
        for(int i = 0; i <= rows - word_length; i++){
            for(int j = word_length - 1; j < cols - word_length; j++){
                if(words_matrix[i][j]        == 'X' &&
                    words_matrix[i+1][j-1]   == 'M' &&
                    words_matrix[i+2][j-2]   == 'A' &&
                    words_matrix[i+3][j-3]   == 'S'
                    ){
                        solution++;
                    }                  

            }
        }        
        // count in rows. 

   for (int i = 0; i < rows; i++){
        for(int j = 3; j <= cols - word_length; j++){
            if(words_matrix[i][j]     == 'S' &&
               words_matrix[i][j+1]   == 'A' &&
               words_matrix[i][j+2]   == 'M' &&
               words_matrix[i][j+3]   == 'X'
            ){
                solution++;
            }
        }
    }

    // count in columns. 
    for (int i = 0; i <= rows - word_length; i++){
        for(int j = 0; j < cols; j++){
            if(words_matrix[i][j]     == 'S' &&
               words_matrix[i+1][j]   == 'A' &&
               words_matrix[i+2][j]   == 'M' &&
               words_matrix[i+3][j]   == 'X'
            ){
                solution++;
            }
        }
    }

    
        // check in the main diagonal
        for(int i = 0; i <= rows - word_length; i++){
            for(int j = 0; j <= cols - word_length; j++){
                if(words_matrix[i][j]        == 'S' &&
                    words_matrix[i+1][j+1]   == 'A' &&
                    words_matrix[i+2][j+2]   == 'M' &&
                    words_matrix[i+3][j+3]   == 'X'
                    ){
                        solution++;
                    }                  

            }
        }        

        // check in the antidiagonal
        for(int i = 0; i <= rows - word_length; i++){
            for(int j = word_length - 1; j < cols - word_length; j++){
                if(words_matrix[i][j]        == 'S' &&
                    words_matrix[i+1][j-1]   == 'A' &&
                    words_matrix[i+2][j-2]   == 'M' &&
                    words_matrix[i+3][j-3]   == 'X'
                    ){
                        solution++;
                    }                  

            }
        }        


  
    std::cout << solution << std::endl;
}


bool isSafe(int x, int y, int cols, int rows){
    return x >= 0 && x < rows && y >= 0 && y < cols;
}
// using the direction vector solution here b/c above did not work
void firstProblemSecondSolution(std::vector<std::string> &lines)
{
    vector<vector<char>> words_matrix(lines.size());
    vector<string> grid = {};
    int solution = 0;
    
    // directions
    // right
    // up
    // down
    // left
    // top - right
    // botton - right
    // top - left
    // bottom - left
    int rowDir[] = {0, -1, 1, 0, -1, 1, -1, 1 };
    int colDir[] = {1, 0, 0, -1, 1, 1, -1, -1 };


    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        grid.push_back(line);

    }

    int rows = grid.size();
    int cols = grid[0].size();
    string word = "XMAS";
    int word_length = word.size();
    

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            char current_char = grid[i][j];
            if(current_char == word[0]){
                // check all 8 directions
                for(int dir = 0; dir < 8; dir++){
                    int x = i, y = j;
                    bool found = true;

                    for(int k = 1; k < word_length; k++){
                        x += rowDir[dir];
                        y += colDir[dir];

                        if(!isSafe(x, y, rows, cols) || 
                        grid[x][y] != word[k]){
                            found = false;
                            break;
                        }
                    }
                if(found) solution++;
                }

            }
        }
    }


  
    std::cout << solution << std::endl;
}




void problem_2(std::vector<std::string> &lines)
{
    vector<string> grid;
    int solution = 0;

    for (int i = 0; i < lines.size(); i++)
    {
        string line = lines[i];
        grid.push_back(line);
    }

    int rows = grid.size();
    int cols = grid[0].size();

    for(int row = 1; row < rows - 1; row++){
        for(int col = 1; col < cols - 1; col++){
            
            if(grid[row][col] != 'A') continue;

            // here we are creating a string based on the indexes we are porviding
            string topLeftRight    = {grid[row - 1][col - 1], grid[row][col], grid[row+1][col+1]};
            string bottomLeftRight = {grid[row - 1][col + 1], grid[row][col], grid[row+1][col-1]};

            if( (topLeftRight == "MAS" || topLeftRight == "SAM") && (bottomLeftRight == "MAS" || bottomLeftRight == "SAM")) solution++;


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

    firstProblemFirstSolution(lines);
    firstProblemSecondSolution(lines);
    problem_2(lines);

    return 0;
}