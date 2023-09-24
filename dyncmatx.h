#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

template <class T> class dyncmatx{
    private:
        int d_r,d_c;
        vector<vector<T>> dyn;
        void initDyn(){
            for(int i = 0;i < d_r;i++){
                vector<T> t1;
                for(int j = 0;j < d_c;j++){
                    t1.push_back(0u);
                }
                dyn.push_back(t1);
            }
        }
    public:    
        dyncmatx(){}
        dyncmatx(vector<vector<T>> dyn): dyn(dyn){}
        dyncmatx(int d_r,int d_c): d_r(d_r),d_c(d_c){initDyn();}
        dyncmatx(vector<vector<T>> dyn,int d_r,int d_c): dyn(dyn),d_r(d_r),d_c(d_c){initDyn();}
        ~dyncmatx(){d_c = 0;d_r = 0; initDyn();}

        
        vector<vector<T>> get_dyncmatx(){return &dyn;}
        void sd_element(int row, int col, T val){
            dyn.at(row).at(col) = val;
        }
        T gd_element(int row, int col){
            return dyn.at(row).at(col);
        }
        
        int r_len(){return d_r;}
        int c_len(){return d_c;}

        T** dyn_to_2ptr(){
            T** res = new T*[d_r];
            for(int i = 0;i < d_r;i++){
                res[i] = new T [d_c];
            }
            for(int i = 0,i < d_r;i++){
                for(int j = 0;j < d_c;j++){
                    res[i][j] = gd_element(i,j);
                }
            }
            return res;
        }
        
        void show_dyn(){
        for (int i = 0; i < dyn.size(); i++) {
        for (int j = 0; j < dyn[i].size(); j++)
            cout << dyn[i][j] << " ";
        cout << endl;}
        } 
};

template <typename U>
ostream& operator << (ostream& out, dyncmatx<U>& din){
    din.show_dyn(); return out << endl;
}

typedef dyncmatx<float> DECMAT;
typedef dyncmatx<int> INTMAT;
typedef dyncmatx<double> CMAT;