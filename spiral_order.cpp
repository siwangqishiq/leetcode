#include <iostream>
#include <vector>

using namespace std;

void countMatrix(vector<vector<int>> &matrix, vector<int> &order ,bool isRow,int axis,
	int start , int end){

	
	
	if(start == end)
		return;

	int nextStart = -1;
	int nextEnd = -1;
	int nextAxis = -1;

	if(isRow){
		if(start < end)	{
			for(int i = start ; i <= end ;i++ ){
				order.push_back(matrix[axis][i]);
			}//end for i

			nextAxis = end;
			nextStart = axis + 1;
			nextEnd = matrix[0].size() - 1 - axis;

			cout << "start = " << start << "  end =" << end << "  axis = "<< axis << endl;
		}else{
			for(int i = start;i>= end;i--){
				order.push_back(matrix[axis][i]);
			}//end for i	

			nextAxis = end;
			nextStart = axis - 1;
			nextEnd = matrix.size() - 1 - axis;

			cout << "start = " << start << "  end =" << end << "  axis = "<< axis << endl;
		}
	}else{
		if(start < end)	{
			for(int i = start ; i <= end ;i++ ){
				order.push_back(matrix[i][axis]);
			}//end for i

			nextAxis = end;
			nextStart = axis - 1;
			nextEnd = matrix[0].size() - 1 - axis;

			cout << "start = " << start << "  end =" << end << "  axis = "<< axis << endl;
		}else{
			for(int i = start;i >= end;i--){
				order.push_back(matrix[i][axis]);
			}//end for i	

			nextAxis = end;
			nextStart = axis + 1;
			nextEnd = matrix[0].size() - 1 - axis;

			cout << "start = " << start << "  end =" << end << "  axis = "<< axis << endl;
		}
	}

	countMatrix(matrix , order, !isRow , nextAxis , nextStart , nextEnd);
}

vector<int> spiralOrder(vector<vector<int>> &matrix){
	vector<int> order;
	countMatrix(matrix , order , true , 0 , 0 , matrix[0].size() -1 );
	return order;
}


int main(){
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
	vector<int> result = spiralOrder(matrix);

	for(int &v : result){
		cout << v << " ";
	}//end for each
	cout << endl;

	return 0;
}
