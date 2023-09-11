#include<iostream>
#include<vector>
#include<cctype>
#include<cmath>
using namespace std;

template <class T> class stats{
    private:
        vector<T>data;
    public:
        stats(vector<T> data):data(data){}
        ~stats(){data.clear();}
        int finder(vector<T> in,T dato){int temp=0; for(T & e: in){temp += (dato == e)?1:0;}return temp;}
        vector<T> fil(){
            vector<T> temp; temp.push_back(data.at(0));
            for(T & e:data){for(int u = 0;u < data.size();u++){if(data.at(u) != e && finder(temp,e)==0) temp.push_back(e);}}
            return temp;temp.clear();
        }
        T getmoda(){
            vector<T> temp(fil()); int n = 0; vector<int> reg (temp.size(),0);
            for(int u = 0;u < temp.size();u++){reg.at(u) = finder(data,temp.at(u));}
            for(int & v : reg){n = max(n,v);}
            for(int u = 0;u < reg.size();u++){if(reg.at(u) == n){reg.clear();return temp.at(u);break;temp.clear();}}
            runtime_error("No hay moda"); return 0;
        }
        vector<T> ordvec(){
            vector<T> ord(data);T temp;
            for(int u = 0;u < ord.size() - 1;u++){
                for(int v = u+1;v < ord.size();v++){if(ord.at(u)>ord.at(v)){temp = ord.at(u); ord.at(u) = ord.at(v); ord.at(v) = temp;}}
            }return ord;ord.clear();
        }
        float getma(){float res=0;for(int u=0;u<data.size();u++){res += data.at(u);} return res/(data.size());}
        float getmg(){float res=1;for(int u=0;u<data.size();u++){res *= data.at(u);} return pow(res,pow(data.size(),-1));}
        float getmh(){float res=0;for(int u=0;u < data.size();u++){res += pow(data.at(u),-1);} return data.size()/res;}
        T getmediana(){return T((data.size()%2==0)?((ordvec().at(data.size()/2)+ordvec().at(data.size()/2-1))/2):(ordvec().at((data.size()+1)/2-1)));}
        float getvar(){float var;for(auto & e:data){var +=pow(e - getma(),2);}return var/data.size();}
        float getds(){return pow(getvar(),0.5);}
        float get_pearsondesv(){return 3*(getma()-getmediana())/getds();}
        float get_desvratio(){return getma()/getds();}
};
typedef stats<float> stcc;
typedef stats<int> stdc;