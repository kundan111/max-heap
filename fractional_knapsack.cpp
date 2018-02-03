//fractional knapsack 
//coded by: kundan111
//date: 31-01-18
//time-complexity: O(nlogn)
//space complexity: O(n)

#include <iostream>
#include <algorithm>
using namespace std;

struct data{
      float profit;
      float weight;
      float ratio;
    };
    
bool compare(data i1 , data i2){
    
    return (i1.ratio >= i2.ratio);
}


int main()
{
    
    
    int n;
    cin >> n;
    struct data input[n];
    
    for(int i=0 ; i < n ; i++){
        float profit;
        float weight;
        
        cin >> profit >> weight;
        
        input[i].profit = profit;
        input[i].weight = weight;
        input[i].ratio = (float)(profit/weight);
    }
    
    sort(input , input + n , compare);
    
    float capacity;
    cin >> capacity;
    
    float profit = 0;
    int i;
    for(i = 0 ; i < n ; i++){
        if(capacity > 0 && input[i].weight <= capacity){
            capacity = capacity - input[i].weight;
            profit = profit + input[i].profit;
        }
        else{
            break;
        }
    }
    
    if(capacity>0){
        profit = profit + (input[i].profit)*capacity/input[i].weight;
    }
    
    
    cout << profit << endl;
  
    return 0;
}
