#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <locale>
#include <string>
#include <cmath>
using namespace std;

template <class T> class polyn{
    private:
        vector<T>poly;
        string poly_out = "";
        void buildpoly(){
        poly_out = "";
            for(auto i = 0;i < poly.size();i++){
                poly_out += to_string(poly.at(i));
                if(i != poly.size() - 1){
                    if(i == poly.size() - 2)
                    poly_out += " X + ";
                    else{
                        poly_out += " X(";
                        poly_out += to_string(poly.size() - 1 - i);
                        poly_out += ") + ";
                    }
                }
            }
        }
    public:
        polyn(vector<T> poly):poly(poly){buildpoly();}
        ~polyn(){string poly_out = ""; poly.clear();}
        void upload_poly(vector<T> in){string poly_out = "";poly.clear();poly.insert(poly.end(),in.begin(),in.end());buildpoly();}
        string getout_poly(){return poly_out;}
        polyn<T>& operator+(polyn<T>& cw);
        polyn<T>& operator-(polyn<T>& kd);
};

typedef polyn<int> pli; typedef polyn<double> pld;
template<typename T>
ostream& operator << (ostream& out,polyn<T>& msg){return out << "P(x) = " << msg.getout_poly() << " " << endl;}
template<typename T>
polyn<T>& polyn<T>::operator+(polyn<T>& cw){
    int pmax_size,pmin_size;
    vector<T>poly_max; vector<T>poly_min;
    pmax_size = max((this->poly).size(),(cw.poly).size()); pmin_size = min((this->poly).size(),(cw.poly).size());
    if((this->poly).size() >= (cw.poly).size()){
        poly_max.insert(poly_max.end(),(this->poly).begin(),(this->poly).end());
        poly_min.insert(poly_min.end(),(cw.poly).begin(),(cw.poly).end());
    }
    else{
        poly_max.insert(poly_max.end(),(cw.poly).begin(),(cw.poly).end());
        poly_min.insert(poly_min.end(),(this->poly).begin(),(this->poly).end());
    }
    vector<T> res(pmax_size,0);(this->poly).clear();
    for(int u = 0;u < pmax_size;u++){
        res.at(pmax_size-u-1) = (u >= pmin_size)?poly_max.at(pmax_size-u-1):poly_max.at(pmax_size-u-1)+poly_min.at(pmin_size-u-1);
    }
    this->upload_poly(res);res.clear();
    return *this;
}

template<typename T>
polyn<T>& polyn<T>::operator-(polyn<T>& kd){
    int pmax_size,pmin_size;
    vector<T>poly_max; vector<T>poly_min;
    pmax_size = max((this->poly).size(),(kd.poly).size()); pmin_size = min((this->poly).size(),(kd.poly).size());
    if((this->poly).size() >= (kd.poly).size()){
        poly_max.insert(poly_max.end(),(this->poly).begin(),(this->poly).end());
        poly_min.insert(poly_min.end(),(kd.poly).begin(),(kd.poly).end());
    }
    else{
        poly_max.insert(poly_max.end(),(kd.poly).begin(),(kd.poly).end());
        poly_min.insert(poly_min.end(),(this->poly).begin(),(this->poly).end());
    }
    vector<T> res(pmax_size,0);(this->poly).clear();
    for(int u = 0;u < pmax_size;u++){
        res.at(pmax_size-u-1) = (u >= pmin_size)?poly_max.at(pmax_size-u-1):poly_max.at(pmax_size-u-1)-poly_min.at(pmin_size-u-1);
    }
    this->upload_poly(res);res.clear();
    return *this;
}