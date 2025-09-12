
/**
 * 实现思路错误  
 * 应该用单调栈算法
 * 
 * X
 */

#include <iostream>
#include <vector>

using namespace std;

const char ZERO = '0';
const char ONE = '1';

int findSingleLineMax(vector<vector<char>>& matrix, int row_value){
    int max_value = 0;
    vector<char> &line = matrix[row_value];

    int counter = 0;
    for(int i = 0 ; i < line.size(); i++){
        if(line[i] == ZERO){
            counter = 0;
        }else if(line[i] == ONE){
            counter++;
        }//end if

        if(counter > max_value){
            max_value = counter;
        }
    }//end for i
    return max_value;
}

int findMaxCrossRect(vector<vector<char>>& matrix, int cross_line){
    const int row_count = matrix.size();
    const int col_count = matrix[0].size();

    const int up_index = cross_line;
    const int down_index = cross_line + 1;
    int connected_record[col_count];

    bool prior_connected = false;
    std::vector<std::pair<int,int>> records;

    for(int i = 0 ; i < col_count ;i++){
        if(matrix[up_index][i] == ONE && matrix[down_index][i] == ONE){
            if(prior_connected){
                records[records.size() - 1].second = i;
            }else{
                std::pair<int,int> record;
                record.first = i;
                record.second = i;
                records.emplace_back(record);
            }
            prior_connected = true;
        }else{
            prior_connected = false;
        }
    }//end for i

    // for(auto &p : records){
    //     std::cout << p.first << " ~ " << p.second << std::endl;
    // }//end for each

    if(records.empty()){
        return 0;
    }

    int max_rect_area = 0;

    for(auto& p : records){
        int cur_area = 0;
        int top = 0;

        for(int i = p.first; i <= p.second; i++){
            int index = up_index;
            int find_idx = index;
            while(index >= 0){
                if(matrix[index][i] == ZERO){
                    break;
                }else{
                    find_idx = index;
                }
                index--;
            }

            if(find_idx > top){
                top = find_idx;
            }
            
            // std::cout << "\t find_idx = " << find_idx << std::endl;
        }//end for i

        // std::cout << "top = " << top << std::endl;

        int bottom = row_count - 1;
        for(int i = p.first; i <= p.second; i++){
            int index = down_index;
            int find_idx = index;
            while(index < row_count){
                if(matrix[index][i] == ZERO){
                    break;
                }else{
                    find_idx = index;
                }
                index++;
            }//end while

            if(find_idx < bottom){
                bottom = find_idx;
            }
        }//end for i

        // std::cout << "\t bottom = " << bottom << std::endl;

        cur_area = (p.second - p.first + 1) * (bottom - top + 1);
        // std::cout << "cur_area = " << cur_area << std::endl;

        if(cur_area > max_rect_area){
            max_rect_area = cur_area;
        }
    }//end for each
    return max_rect_area;
}

int findMaxRect(vector<vector<char>>& matrix,int start,int end){
    if(start >= end){
        return 0;
    }

    const int row_count = end - start;
    if(row_count == 1){
        return findSingleLineMax(matrix, start);
    }else{
        const int mid = (start + end) >> 1;

        const int up_max = findMaxRect(matrix, start, mid);
        const int down_max = findMaxRect(matrix, mid, end);
        const int cross_middle_max = findMaxCrossRect(matrix, mid - 1);//todo

        int result = up_max;
        if(result < down_max){
            result = down_max;
        }
        if(result < cross_middle_max){
            result = cross_middle_max;
        }
        return result;
    }
}

int maximalRectangle(vector<vector<char>>& matrix) {
    const int row = matrix.size();
    int maximal_value = findMaxRect(matrix, 0, row);
    return maximal_value;           
}

void testCaseSingle(vector<vector<char>> &mat){
    const int row = mat.size();
    for(int i = 0 ; i < row ;i++){
        auto sub_result = findSingleLineMax(mat, i);
        cout << "line:" << i << " # : " << sub_result << endl;
    }//end for i
}

void testCaseCross(vector<vector<char>> &mat){
    findMaxCrossRect(mat, 1);
}

int main(){
    vector<vector<char>> mat = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    // vector<vector<char>> mat = {
    //     {1,0,1,0,0},
    //     {1,0,1,1,1},
    //     {1,1,1,1,1},
    //     {1,0,1,1,1},
    //     {1,1,1,1,1}
    // };

    auto result = maximalRectangle(mat);
    std::cout << "result = " << result << std::endl;

    // testCaseSingle(mat);
    // testCaseCross(mat);
    return 0;
}

