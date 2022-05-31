#include <iostream>
#include <algorithm> 

class Interval{
    private:   
    public:
        int inf_0 = -1;
        int sup_0 = -1;

        Interval(): inf(0), sup(0) {}
        Interval(int inf, int sup){
            if(inf>sup){
                int inf_temp = inf;
                inf=sup;
                sup=inf_temp;
            }
            this->inf_0 = inf;
            this->sup_0 = sup;
        }
        friend Interval operator + (const Interval& inval_1, const Interval& inval_2){
            return Interval(inval_1.inf_0 + inval_2.inf_0, inval_1.sup_0 + inval_2.sup_0); 
        }
        Interval& operator += (const int dig){
            this-> inf_0 += dig;
            this-> sup_0 += dig;
            return *this;
        }

        friend std::ostream& operator << (std::ostream& stream, const Interval& inval_1){
           return stream << "[" << inval_1.inf_0 <<  "," << inval_1.sup_0 << "]" << std::endl;
        }
};

Interval operator * (const Interval& inval_1, const Interval& inval_2){
    int test_arr[4];
    test_arr[0] = inval_1.inf_0 * inval_2.inf_0;
    test_arr[1] = inval_1.inf_0 * inval_2.sup_0;
    test_arr[2] = inval_1.sup_0 * inval_2.inf_0;
    test_arr[3] = inval_1.sup_0 * inval_2.sup_0;

    int min = *std::min_element(test_arr, test_arr + 4);
    int max = *std::max_element(test_arr, test_arr + 4);
    
    return Interval(min,max);
}

int main(){
    Interval in1(3,5);
    Interval in2(4,6);
    Interval in3;

    in3 = in1 * in2;
    std:: cout << in1;
}