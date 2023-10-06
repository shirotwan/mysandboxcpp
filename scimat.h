#include<iostream>
#include<cmath>
#include<vector>
#include<cctype>
#include"dyncmatx.h"

using namespace std;

template <class T> class scimat{
    private:
        T** mat; int r = 0; int c = 0;
        void initMat(){
            mat = new T*[r];
            for(int i = 0;i < r;i++){
                mat[i] = new T[c];
            }
        }
        void safe_reset(){mat = NULL; r = 0; c = 0;}
    public:
        scimat(T** mat,int r, int c):mat(mat),r(r),c(c){initMat();}
        scimat(T** mat,int ord):mat(mat){this->r = ord;this->c = this->r;initMat();}
        scimat(int r, int c):r(r),c(c){initMat();}
        ~scimat(){safe_reset(); delete mat;}

        T** get_mat(){return mat;} 
        T get_e_mat(int posr, int posc){return mat[posr][posc];}
        int get_row_len(){return r;} 
        int get_col_len(){return c;}

        virtual void set_e_mat(int posr, int posc,T val){mat[posr][posc] = val;}
        virtual void display_mat(){
            for(int u = 0;u < r;u++){
                for(int v = 0;v < c;v++){
                    cout << mat[u][v] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        virtual void swap_e(int e1,int e2, int f1,int f2){
            T temp1 = mat[e1][e2];
            T temp2 = mat[f1][f2];
            set_e_mat(e1,e2,temp2); set_e_mat(f1,f2,temp1);
        }
        virtual void t(){
            for(int i = 0;i < r;i++){
                for(int j = i;j < c;j++){
                    swap_e(i,j,j,i);
                }
            }
        }
        T* vec(){
            static vector<T> temp;
            for(int i = 0;i < r;i++){
                for(int j = 0;j < c;j++){
                    temp.push_back(mat[i][j]);
                }
            }
            return temp.data();
        }
        T* vec_row(int row_index){
            static vector<T> temp;
            for(int i = 0;i < c;i++){
                temp.push_back(mat[row_index][i]);
            }
            return temp.data();
        }
        T* vec_col(int col_index){
            static vector<T> temp;
            for(int i = 0;i < r;i++){
                temp.push_back(mat[i][col_index]);
            }
            return temp.data();
        }
        void show_vec(){
            T* init_vec = new T[r*c];
            init_vec = vec();
            for(int i = 0;i < r*c;i++){
                cout << init_vec[i] << " ";
            }
            cout << endl;
        }
        dyncmatx<T> Q(){
            static DECMAT matrix(r,c);
            float unic = 0;
            for(auto i = 0;i < c;i++){
                for(auto j = 0;j < r;j++){
                    unic += pow(mat[j][i],2);
                }
                unic = pow(unic,0.5);
                for(auto k = 0;k < r;k++){
                    matrix.sd_element(k,i,float(mat[k][i])/unic);
                }
                unic = 0;
            }
            return matrix;
        }
        DECMAT Tr(){
            static DECMAT mt(c,r);
            for(auto i = 0;i < c;i++){
                for(auto j = 0;j < r;j++){
                    mt.sd_element(i,j,mat[j][i]);
                }
            }
            return mt;
        }
};

template <typename U>
ostream& operator << (ostream& out, scimat<U>& mtx){
    static dyncmatx<U> dispM(mtx.get_row_len(),mtx.get_col_len());
    for(int i = 0;i < mtx.get_row_len();i++){
        for(int j = 0;j < mtx.get_col_len();j++){
            dispM.sd_element(i,j,mtx.get_e_mat(i,j));
        }
    }
    return out << dispM << endl;
}
