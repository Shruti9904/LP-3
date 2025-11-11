#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item{
    double profit;
    double weight;
};

bool compare(Item a,Item b){
    double r1 = a.profit/a.weight;
    double r2 = b.profit/b.weight;
    return r1>r2;
}

double fractionalKnapsack(vector<Item> items,double maxWeight,int n){
    sort(items.begin(),items.end(),compare);

    double maxProfit = 0.0;
    double remainingWeight = maxWeight;

    for(int i=0;i<n;i++){
        if(items[i].weight <= remainingWeight){
            //take whole item
            remainingWeight-= items[i].weight;
            maxProfit+=items[i].profit;
        }else{
            maxProfit+= (remainingWeight/items[i].weight)*items[i].profit;
            break; //knapsack is full
        }
    }

    return maxProfit;
}

int main(){
    int n;
    cout<<"Enter total no of items: ";
    cin>>n;

    vector<Item> items(n);

    cout<<"Enter price and weight of each item: "<<endl;
    for(int i=0;i<n;i++){
        cin>>items[i].profit>>items[i].weight;
    }

    double maxWeight;
    cout<<"Enter maximum capacity of knapsack:";
    cin>>maxWeight;

    cout<<"Maximum profit: "<<fractionalKnapsack(items,maxWeight,n);

}