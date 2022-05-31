#include<iostream>
#include<iomanip>
#include <vector>
#include<valarray>
#include<numeric>

using namespace std;

// check of a calcuate sum is given in vector v_sum
bool check_sum_func(vector<int> &v_sum,int check_sum){
    int test{};
    for(int i=0;i<v_sum.size();i++){
        if(check_sum==v_sum[i]){
            return true;
        }
    }
    return false;
}
// solve the problem step by step
void sol(int (*arr)[3],vector<int> &v_sum, vector<int> &v_list, int row, int col, int status,int back_row, int back_col){
    bool check_sum=false;int sum_mid{};
    for(row=0;row<3;row++){
        v_list.push_back(arr[row][col]);
        back_row=row;back_col=col;
        if(row==2){
            sum_mid=accumulate(v_list.begin(),v_list.end(),0);
            check_sum=check_sum_func(v_sum,sum_mid);
            if(check_sum==false){v_sum.push_back(sum_mid);}
            else{
                v_list.pop_back();
                row=back_row;
                col=back_col;
                row-=1;
                col+=1;
            }
        }
    }
    // v_list.clear();
    if(pow(2,2)==v_list.size()){status=1;}
    for(int i=0;i<v_list.size();i++){
        cout << "sum: " << v_list[i] << endl;
    }
}
// controls the solving of the problem and finally outputs the min_sum
void assign(int (*arr)[3], int m, int n){
    vector<int>v_sum;vector<int>v_list;
    int row{},col{},sum{},sum_min{},status{},back_row{},back_col{};
    while(status!=1){
        sol(arr,v_sum,v_list,row,col,status,back_row,back_col);
    }
    sum_min = *min_element(v_sum.begin(),v_sum.end());
    cout << "low sum = " << sum_min << endl;
}
int main(){
  int m{3},n{3};
  int arr[3][3] = 
    {{75},
    {95, 9},
    {17, 4, 82}};
    // {18, 35, 87, 10}};
    assign(arr,m,n);
}

