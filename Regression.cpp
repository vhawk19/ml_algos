#include<bits/stdc++.h>
typedef std::pair<double,double> d_pair;
//using namespace std;
d_pair type_linear(const std::vector<double>& x, const std::vector<double>& y) {
    const auto n    = x.size();
    const auto s_x  = std::accumulate(x.begin(), x.end(), 0.0);
    const auto s_y  = std::accumulate(y.begin(), y.end(), 0.0);
    const auto s_xx = std::inner_product(x.begin(), x.end(), x.begin(), 0.0);
    const auto s_xy = std::inner_product(x.begin(), x.end(), y.begin(), 0.0);
    const auto a    = (n * s_xy - s_x * s_y) / (n * s_xx - s_x * s_x);
    const auto b    = ((s_xx*s_y-s_x*s_xy)*1.0/(n*s_xx-s_x*s_x)*1.0);
    d_pair temp(a,b);
    return temp;
}
int main(){
    int n;
    double temp;
    std::vector<double>x,y;
    std::cin>>n;
    for(int i=0;i<n;i++){
        std::cin>>temp;
        x.push_back(temp);
    }
    for(int i=0;i<n;i++){
        std::cin>>temp;
        y.push_back(temp);
    }
    d_pair result=type_linear(x,y);
    std::cout << result.first<<"x + "<<result.second << '\n';
    return 0;
}
