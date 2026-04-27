#include <iostream>
#include <vector>
#include <map>

using namespace std;

constexpr static int LeftToRight = 1;
constexpr static int TopToDown = 2;
constexpr static int LeftToDown = 3;
constexpr static int DownToRight = 4;
constexpr static int TopToLeft = 5;
constexpr static int TopToRight = 6;

constexpr static int DirUp = 0;
constexpr static int DirRight = 1;
constexpr static int DirDown = 2;
constexpr static int DirLeft = 3;
constexpr static int DirError = -1;

bool isEndPostion(vector<vector<int>>& grid, int curRow, int curCol){
    if(grid.empty()){
        return true;
    }
    const int endRow = grid.size() - 1;
    const int endCol = grid[0].size() - 1;
    return curRow == endRow && curCol == endCol;
}

int findStartDir(int gridValue){
    int ret = DirError;
    switch (gridValue)
    {
    case LeftToRight:
        ret = DirLeft;
        break;
    case TopToDown:
        ret = DirUp;
        break;
    case LeftToDown:
        ret = DirLeft;
        break;
    case TopToLeft:
        ret = DirUp;
        break;
    case TopToRight:
        ret = DirUp;
        break;
    default:
        break;
    }
    return ret;
}

struct NextPos{
    bool success;
    int nextRow;
    int nextCol;
    int nextDir;
};

void checkNextPosData(NextPos &nextPos, vector<vector<int>>& grid){
    if(!nextPos.success){
        return;
    }

    if(grid.empty() || nextPos.nextRow < 0 || nextPos.nextCol < 0){
        nextPos.success = false;
        return;
    }

    if(nextPos.nextRow >= grid.size()){
        nextPos.success = false;
        return;
    }

    if(nextPos.nextCol >= grid[0].size()){
        nextPos.success = false;
        return;
    }
    return;
}

int colRowKey(int row, int col){
    return 10000*row + col;
}

NextPos findNext(vector<vector<int>>& grid, int row, int col, int enterDir, bool filterResult){
    const int gridValue = grid[row][col];
    NextPos nextPos;
    nextPos.success = true;

    switch (gridValue)
    {
    case LeftToRight:
        if(enterDir == DirLeft){
            nextPos.nextDir = DirLeft;
            nextPos.nextRow = row;
            nextPos.nextCol = col + 1;
        }else if(enterDir == DirRight){
            nextPos.nextDir = DirRight;
            nextPos.nextRow = row;
            nextPos.nextCol = col - 1;
        }else{
            nextPos.success = false;
        }
        break;
    case TopToDown:
        if(enterDir == DirUp){
            nextPos.nextDir = DirUp;
            nextPos.nextRow = row + 1;
            nextPos.nextCol = col;
        }else if(enterDir == DirDown){
            nextPos.nextDir = DirDown;
            nextPos.nextRow = row - 1;
            nextPos.nextCol = col;
        }else{
            nextPos.success = false;
        }
        break;
    case LeftToDown:
        if(enterDir == DirLeft){
            nextPos.nextDir = DirUp;
            nextPos.nextRow = row + 1;
            nextPos.nextCol = col;
        }else if(enterDir == DirDown){
            nextPos.nextDir = DirRight;
            nextPos.nextRow = row;
            nextPos.nextCol = col - 1;
        }else{
            nextPos.success = false;
        }
        break;
    case DownToRight:
        if(enterDir == DirDown){
            nextPos.nextDir = DirLeft;
            nextPos.nextRow = row;
            nextPos.nextCol = col + 1;
        }else if(enterDir == DirRight){
            nextPos.nextDir = DirUp;
            nextPos.nextRow = row + 1;
            nextPos.nextCol = col;
        }else{
            nextPos.success = false;
        }
        break;
    case TopToLeft:
        if(enterDir == DirUp){
            nextPos.nextDir = DirRight;
            nextPos.nextRow = row;
            nextPos.nextCol = col - 1;
        }else if(enterDir == DirLeft){
            nextPos.nextDir = DirDown;
            nextPos.nextRow = row - 1;
            nextPos.nextCol = col;
        }else{
            nextPos.success = false;
        }
        break;
    case TopToRight:
        if(enterDir == DirUp){
            nextPos.nextDir = DirLeft;
            nextPos.nextRow = row;
            nextPos.nextCol = col + 1;
        }else if(enterDir == DirRight){
            nextPos.nextDir = DirDown;
            nextPos.nextRow = row - 1;
            nextPos.nextCol = col;
        }else{
            nextPos.success = false;
        }
        break;
    default:
        break;
    }//end switch

    if(filterResult){
        checkNextPosData(nextPos,grid);
    }

    return nextPos;
}

bool realHasValidPath(vector<vector<int>>& grid){
    int col = 0;
    int row = 0;

    int dir = findStartDir(grid[row][col]);
    if(dir < 0){
        return false;
    }

    map<int, bool> visitedNode;

    if(isEndPostion(grid, row, col)){
        return true;
    }

    visitedNode[colRowKey(row, col)] = true;

    while(true){
        // cout << "row-col " << row << "  " << col << "  " << grid[row][col] << " dir " << dir << endl;

        auto nextPos = findNext(grid, row, col, dir, true);
        // cout << "nextPos " << nextPos.success << "   " << nextPos.nextRow << "  " << nextPos.nextCol << std::endl;
        if(nextPos.success){
            row = nextPos.nextRow;
            col = nextPos.nextCol;
            dir = nextPos.nextDir;

            if(visitedNode.find(colRowKey(row, col)) != visitedNode.end() 
                && !isEndPostion(grid,row, col)){
                return false;
            }
            visitedNode[colRowKey(row, col)] = true;

            if(isEndPostion(grid, row, col)){
                auto checkResult = findNext(grid, row, col, dir, false);
                return checkResult.success;
            }
        }else{
            break;
        }
    }//end while
    return false;
}

bool hasValidPath(vector<vector<int>>& grid) {
    if(grid[0][0] == DownToRight){
        auto copyGrid1 = grid;
        copyGrid1[0][0] = LeftToRight;

        auto copyGrid2 = grid;
        copyGrid2[0][0] = TopToDown;
        return realHasValidPath(copyGrid1) || realHasValidPath(copyGrid2);
    }else{
        return realHasValidPath(grid);
    }
}

int main(){
    // vector<vector<int>> grid = {
    //     {2,4,3},
    //     {6,5,2}
    // };

    // vector<vector<int>> grid = {
    //     {1,2,1},
    //     {1,2,1}
    // };

    // vector<vector<int>> grid = {
    //     {1,2}
    // };

    vector<vector<int>> grid = {
        {4,1},
        {6,1}
    };

    auto result = hasValidPath(grid);
    std::cout << "result = " << (result?"true":"false") << std::endl;
    return 0;
}


