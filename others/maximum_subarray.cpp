#include<iostream>
#include<vector>
typedef int ElemType;
ElemType find_max_subarray(const std::vector<ElemType> &vec, size_t &max_sum_beg, size_t &max_sum_end){
    ElemType cur_sum=0, max_sum=-INT_MAX;
    size_t cur_sum_beg=0;
    for(size_t i=0;i<vec.size();i++){
        cur_sum += vec[i];
        if(cur_sum>max_sum){
            max_sum=cur_sum;
            max_sum_beg=cur_sum_beg;
            max_sum_end=i;
        }
        if(cur_sum<=0){
            cur_sum=0;
            cur_sum_beg=i+1;
        }
    }
    return max_sum;
}
int main(){
    std::vector<ElemType> ivec{13,3,25,20,21,16,23,18,20,7,12,5,22,15,4,7};
    size_t ix1, ix2;
    std::cout<<find_max_subarray(ivec,ix1,ix2)<<'\n';
    std::cout<<ix1<<','<<ivec[ix1]<<'\t'<<ix2<<','<<ivec[ix2];
}
