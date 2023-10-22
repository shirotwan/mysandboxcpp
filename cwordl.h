#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <iterator>
#include <iostream>
#include <cctype>
using namespace std;

typedef class cwordl{
    protected:
        string s_msg; char* c_msg;
        vector<string> temp_disp_s; vector<char> temp_disp_char;
    private:
        vector<string> v_split; vector<char> c_ptr_in;
        
        void initS_Char(){c_msg = new char[s_msg.length()+1];c_msg = new char[s_msg.length()];c_msg = (char*)(s_msg.c_str()); //strcpy(c_msg,s_msg.c_str()); unsafe
        }
        void initC_VChar(){for(int i = 0;i < s_msg.length();i++){c_ptr_in.push_back(tolower(c_msg[i]));}}
        void cleanCache(){s_msg = ""; delete c_msg;}

        void cstrct_s(){initS_Char(); initC_VChar(); cleanCache();}
        void depurar(){
            for(int i = 0;i < c_ptr_in.size();i++){
                if(c_ptr_in.at(i) == '.' || c_ptr_in.at(i) == ',' || c_ptr_in.at(i) == '!' || c_ptr_in.at(i) == ',' || c_ptr_in.at(i) == ';' || c_ptr_in.at(i) == '?' || c_ptr_in.at(i) == '\x22' || c_ptr_in.at(i) == ':'){
                    c_ptr_in.erase(c_ptr_in.begin()+i);
                }
            }
        }

        void initCdisp(){for(auto & e : c_ptr_in){temp_disp_char.push_back('[');temp_disp_char.push_back(e);temp_disp_char.push_back(']');temp_disp_char.push_back(' ');}temp_disp_char.push_back('\0');}
        void initSdisp(){for(string & s : v_split){temp_disp_s.push_back("[");temp_disp_s.push_back(s);temp_disp_s.push_back("]");temp_disp_s.push_back(" ");}}
    public:
        ~cwordl(){v_split.clear(); c_ptr_in.clear();}
        cwordl(string s_msg):s_msg(s_msg){cstrct_s(); depurar();splitwords();}
        cwordl(vector<char> c_ptr_in):c_ptr_in(c_ptr_in){depurar();splitwords();}
        cwordl(cwordl const & input){this->v_split = input.v_split; this->c_ptr_in = input.c_ptr_in;}

        vector<char> getsplitc(){return c_ptr_in;}
        vector<string> getsplits(){return v_split;}

        string get_disp_c_info(){initCdisp(); return temp_disp_char.data(); temp_disp_char.clear();}
        string get_disp_s_info(){
            string res = "";
            if(!v_split.empty()){for(string & s:temp_disp_s){res += s;}}
            else{runtime_error("NULL SPLIT, CAN'T GET ANY RESULTS");}
        return res;}

        string to_str_char(int inf,int sup){
        vector<char> temp; temp.insert(temp.begin(),make_move_iterator(c_ptr_in.begin()+inf),make_move_iterator(c_ptr_in.begin()+sup));
        temp.push_back('\0');char* res = temp.data(); return res;}

        string to_str_char(){
        vector<char> temp; temp.insert(temp.begin(),c_ptr_in.begin(),c_ptr_in.end());temp.push_back('\0');
        char* res = temp.data(); return res;}

        virtual void splitwords(){
            int inf,sup; inf = 0;
            for(int i = 0;i < c_ptr_in.size();i++){
                sup = i;
                if(c_ptr_in.at(i) == ' '){
                    if(to_str_char(inf,sup) != ""){v_split.push_back(to_str_char(inf,sup));} inf = sup + 1;}}
            v_split.push_back(to_str_char(inf,sup+1));
        initSdisp();}

        virtual void unsplit(){v_split.clear();}
        string ltr(){splitwords(); return "{ " + get_disp_s_info() + "}";}
        cwordl& operator+(cwordl& cw);
}cwordl;

ostream& operator << (ostream& out, cwordl& cw){
    if(!(cw.getsplits().empty())){return out << "{ " << cw.get_disp_s_info() << "}" << endl;}
    else{return out << "{ " << cw.get_disp_c_info() << "}" << endl;}
}
cwordl& cwordl::operator+(cwordl& cw){
            if(!(cw.getsplits().empty()) && !(this->getsplits().empty())){
                vector<string> copy_2nd(cw.v_split);
                (copy_2nd).insert((copy_2nd).begin()," ");
                (this->v_split).insert((this->v_split).end(),(copy_2nd).begin(),(copy_2nd).end());
                this->initSdisp(); copy_2nd.clear();
            }
            else{
                vector<char> copy_3rd(cw.c_ptr_in);
                (copy_3rd).insert((copy_3rd).begin(),' ');
                (this->c_ptr_in).insert((this->c_ptr_in).end(),(copy_3rd).begin(),(copy_3rd).end());
                this->initCdisp(); copy_3rd.clear();
            }
    return *this;
}
typedef cwordl cw;
