#include<iostream>
#include<cmath>
#include<vector>

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
        int get_row_len(){return &r;} 
        int get_col_len(){return &c;}

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
            return temp.data(); temp.clear();
        }
        T* vec_row(int row_index){
            static vector<T> temp;
            for(int i = 0;i < c;i++){
                temp.push_back(mat[row_index][i]);
            }
            return temp.data(); temp.clear();
        }
        T* vec_col(int col_index){
            static vector<T> temp;
            for(int i = 0;i < r;i++){
                temp.push_back(mat[i][col_index]);
            }
            return temp.data(); temp.clear();
        }
        void show_vec(){
            T* init_vec = new T[r*c];
            init_vec = vec();
            for(int i = 0;i < r*c;i++){
                cout << init_vec[i] << " ";
            }
            cout << endl;
        }
        float** Q(){
            float** res = new float*[r];
            for(int i = 0;i < r;i++){
                res[i] = new float[c];
            }
            for(int i = 0;i < c;i++){
                T* temp_vt = vec_col(i);
                float* temp_f = static_cast<float*>(temp_vt);
                float su = 0;
                for(int j = 0;j < r;j++){
                    su += float(temp_f[j]);
                }
                for(int j = 0;j < r;j++){
                    temp_f[j] /= su;
                }
                for(int j = 0;j < r;j++){
                    res[j][c] = temp_f[j];
                }
            }
            return res;
        }
};


