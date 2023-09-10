#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <locale>
#include <string>
using namespace std;

template <class T> class polyn{
    private:
        vector<T>poly;
        string poly_out = "";
        void buildpoly(){
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
        void upload_poly(vector<T> in){poly.clear();poly.insert(poly.end(),in.begin(),in.end());buildpoly();}
        string getout_poly(){return poly_out;}
};

typedef polyn<int> pli; typedef polyn<double> pld;
template<typename T>
ostream& operator << (ostream& out, polyn<T>& cw){return out << cw.getout_poly();}