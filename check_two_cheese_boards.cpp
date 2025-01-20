#include <iostream>
#include <vector>
#include <string>

using namespace std;

void buildBoards(vector<vector<short>> &board , int size){
    for(int i = 0 ; i < size ; i++){
        bool flag = (i % 2 == 0);
        for(int j = 0 ; j < size;j++){
            board[i][j] = flag?1:0;
            flag = !flag;
        }
    }//end for each
}

void printBoard(vector<vector<short>> &board , int size){
    for(auto &vec : board){
        for(auto &v : vec){
            cout << v << "  ";
        }
        cout << endl;
    }
}

void convertCoord(string &coord , int &outX, int &outY){
    char row = coord[0];
    char col = coord[1];

    switch(col){
        case '1':
            outX = 7;
            break;
        case '2':
            outX = 6;
            break;
        case '3':
            outX = 5;
            break;
        case '4':
            outX = 4;
            break;
        case '5':
            outX = 3;
            break;
        case '6':
            outX = 2;
            break;
        case '7':
            outX = 1;
            break;
        case '8':
            outX = 0;
            break;
        default:
            outX = -1;
            break;
    }

    switch(row){
        case 'a':
            outY = 0;
            break;
        case 'b':
            outY = 1;
            break;
        case 'c':
            outY = 2;
            break;
        case 'd':
            outY = 3;
            break;
        case 'e':
            outY = 4;
            break;
        case 'f':
            outY = 5;
            break;
        case 'g':
            outY = 6;
            break;
         case 'h':
            outY = 7;
            break;
        default:
            outY = -1;
            break;
    }
}

bool checkTwoChessboards(string coordinate1, string coordinate2) {
    const int size = 8;
    vector<vector<short>> board(size,vector<short>(size));
    buildBoards(board , size);

    int x1,y1;
    convertCoord(coordinate1 , x1 , y1);
    int x2,y2;
    convertCoord(coordinate2 , x2 , y2);

    if(x1 <0 || y1 < 0 || x2 < 0  || y2 < 0){
        return false;
    }
    return board[x1][y1] == board[x2][y2];
}


int main(){
    auto result = checkTwoChessboards("a1" , "h3");
    cout << "result : " << result << endl;
    return 0;
}