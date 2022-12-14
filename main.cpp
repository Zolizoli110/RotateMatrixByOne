#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'matrixRotation' function below.
 *
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY matrix
 *  2. INTEGER r
 */

void matrixRotation(vector<vector<int>> matrix, int r) {
  int maxRow = matrix.size() - 1;
  int maxCol = matrix[0].size() - 1;
  int row = 0;
  int col = 0;
  
  while (row < maxRow && col < maxCol){
    int num = r % (2 * (maxRow + maxCol + 2) - 4);

    for (int y = 0; y < num; y++){


      int prev = matrix[row][col + 1];
      for (int i = row; i <= maxRow; i++){
        int current = matrix[i][col];
        matrix[i][col] = prev;
        prev = current;
      }

      

      for (int i = col + 1; i <= maxCol; i++){
        int current = matrix[maxRow][i];
        matrix[maxRow][i] = prev;
        prev = current;

      }

      

      if(row <= maxRow - 1){
        for (int i = maxRow - 1; i >= row; i--){
          int current = matrix[i][maxCol];
          matrix[i][maxCol] = prev;
          prev = current;
        }

        
      }

      if(col <= maxCol - 1){
        for (int i = maxCol - 1; i >= col; i--){
          int current = matrix[row][i];
          matrix[row][i] = prev;
          prev = current;
        }   

        
      }
    }  
      col++;
      maxRow--;
      maxCol--;
      row++;
  }
  for(unsigned long int i = 0; i < matrix.size(); i++){
    for (unsigned long int j = 0; j < matrix[0].size(); j++){
      cout << matrix[i][j] << " ";
    }
    cout << "\n";
  }
}

int main()
{
  string first_multiple_input_temp;
  getline(cin, first_multiple_input_temp);

  vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

  int m = stoi(first_multiple_input[0]);

  int n = stoi(first_multiple_input[1]);

  int r = stoi(first_multiple_input[2]);

  vector<vector<int>> matrix(m);

  for (int i = 0; i < m; i++) {
    matrix[i].resize(n);

    string matrix_row_temp_temp;
    getline(cin, matrix_row_temp_temp);

    vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

    for (int j = 0; j < n; j++) {
      int matrix_row_item = stoi(matrix_row_temp[j]);

      matrix[i][j] = matrix_row_item;
    }
  }

  matrixRotation(matrix, r);

  return 0;
}

string ltrim(const string &str) {
  string s(str);

  s.erase(
      s.begin(),
      find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
      );

  return s;
}

string rtrim(const string &str) {
  string s(str);

  s.erase(
      find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
      s.end()
      );

  return s;
}

vector<string> split(const string &str) {
  vector<string> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos) {
    tokens.push_back(str.substr(start, end - start));

    start = end + 1;
  }

  tokens.push_back(str.substr(start));

  return tokens;
}
