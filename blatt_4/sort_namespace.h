namespace sortieren{
        void swap(auto* a, auto* b){
        auto t=*a;
        *a=*b;
        *b=t;
    }
    auto partition (auto *arr, auto low, auto high){
        auto pivot=arr[high];  
        auto i=(low-1); 
    
        for (int j=low;j<=high-1;j++){
            if (arr[j] <= pivot){
                i++;   
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[i+1], &arr[high]);
        return (i+1);
    }

    void quickSort(auto* arr, int low, int high){
        if(low<high){
            auto pi=partition(arr, low, high);
    
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    void printArray(auto* arr, int size){
        std::cout << "array sorted: ["; 
        for(int i=0;i<size;i++){
            std::cout << arr[i] << " ";     
        }
        std::cout << "]" << std::endl;     
    }
    void printArray_before(auto* arr, int size){
        std::cout << "array unsorted: [";
        for(int i=0;i<9;i++){
            std::cout << arr[i] << " ";     
        } std::cout << "]" << std::endl;
    }
} 

namespace sortieren_und_rechnen{
    int sort_and_calc_int(std::vector<int>& v){  
        int total{};
        total=accumulate(v.begin(),v.end(),0); 
        return total;
    }
    double sort_and_calc_dou(std::vector<double>& v){  
        double total{1};
        for(int i=0;i<v.size();i++){
            total*=v[i];   
        }
        return total;  
    }
    int sort_and_calc_char(std::vector<int>& v){  
        int total{};
        total=accumulate(v.begin(),v.end(),0); 
        return total;
    }
}