#include <iostream>
using namespace std;

int main() {
    int price_food_item_1;
    int price_food_item_2;

    cout<<"Enter price of food item 1: ";
    cin>>price_food_item_1;
    
    cout<<"Enter price of food item 2: ";
    cin>>price_food_item_2;

    cout<<"Your total bill is Rs."<<price_food_item_1+price_food_item_2<<" !";

    return 0;
}