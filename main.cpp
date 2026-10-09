#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<double> buildVector(double start_price, double end_price, double step_size){
    std::vector<double> spotPrices{};
    for (double start{start_price}; start < end_price; start+= step_size){
        spotPrices.push_back(start);
    }
    return spotPrices;

}
double payOff(double spot, double strike, bool isCall){
    if(isCall){
        double payoff = spot - strike;
        return std::max(payoff,0.0);
        
    }
    else{
        double payoff = strike - spot;
        return std::max(payoff,0.0);
    }
}

int main(){
    double strike_price{};
    char option_type{};
    double start_price{};
    double end_price{};
    double step_size{};

    std::cout<<"Enter the strike price,option type and start price,end price and step size for the options prices you want to test.";
    std::cin >> strike_price >> option_type >> start_price >> end_price >> step_size;
    bool isCall{};
    if (option_type == 'c'){
        isCall = true;

    }else{
        isCall = false;
    }
    
    std::vector<double> results{};
    for(double spot:buildVector(start_price,end_price,step_size) ){
        double payoffValue =  payOff(spot,strike_price,isCall);
        results.push_back(payoffValue);
    

    }
    return 0;
}