#include<iostream>
#include<iomanip>
#include <vector>
#include<valarray>
#include<numeric>

using namespace std;
int high(int& row, int& col, int (*arr_check)[4]){
    return row,col;
}
int low(int& row, int& col, int (*arr_check)[4]){
    if(arr_check[4])
    return row,col;
}
int check(int& row, int& col,int (*arr_check)[4],int& step){
        int b{};
        if(step==1){row,col = low(row,col,arr_check);}
        if(step==2){row,col = high(row,col,arr_check);}
    return row,col; 
}
void find(int (*arr)[4], int m, int n, int (*arr_check)[4]){
    vector<int>v;
    int count{1},count_2{},row{},col{},step{1};
    while(count!=8){
        v.push_back(arr[0][0]);
        while(count_2!=3){
            row,col = check(row,col,arr_check,step);
            count_2+=1;
            v.push_back(arr[row][col]);
        }
        for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
        }
        cout << "Sum = " << accumulate(v.begin(),v.end(),0) << endl;
        v.clear();
        count+=1;count_2=0;
        if(count==4){
            step=2;
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout << arr_check[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
  int j{4},i{4};
  int arr[4][4] = 
    {{75},
    {95, 9},
    {17, 4, 82},
    {18, 35, 87, 10}};
int arr_check[4][4] = 
    {{-1},
    {0, 1},
    {0, 1, 2},
    {0, 1, 2, 3}};

    find(arr,i,j,arr_check);
}
