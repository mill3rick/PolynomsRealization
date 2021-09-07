#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <utility>
#include <cmath>

using namespace std;

template <typename T>
class Polynomial{
public:
    Polynomial(vector<T>& koefs ){
        int i;
        for (i=0; i<koefs.size(); i++ ){
            if (koefs.at(i)!=0){
                pol.push_back(make_pair(i, koefs.at(i)));
            }
        }
    }

    Polynomial(T koef = T()){
        if (koef != 0){
            pol.push_back(make_pair(0,koef));
        }
    }

    Polynomial(T first, T last){
        for(T i=0; first+i != last; i++){
            if(*(first+i) != 0){
                pol.push_back(make_pair(i,*(first+i)));
            }
        }
    }

    Polynomial(const Polynomial<T>& polynomial) = default;

    const T operator [](size_t koeff){
        auto bg = 0;
        for(size_t i = 0;i<pol.size();i++){
            if(pol.at(i).first == (T)koeff) {
                bg = pol.at(i).second;
            }
        }
        return bg;
    }

    const T operator()(const T& solution){
        T res;
        for(size_t i = 0; i < pol.size(); i++){
            res += pol.at(i).second * pow(solution,pol.at(i).first);

        }
        return res;
    }

    Polynomial& operator = (const Polynomial& pervii)& = default;
    Polynomial& operator = (Polynomial&& pervii)& noexcept = default;

    const auto begin(){
        return pol.begin();
    }

    const auto end(){
        return pol.end();
    }

    const T Degree(){
        T jit;
        if (pol.empty()){
            return -1;
        }
        if (pol.at(pol.size() - 1).second == T()){
            return -1;
        }
        jit = pol.at(pol.size() - 1).first;
        return jit;
    }

    template <typename T1>
    friend const bool operator == (const Polynomial<T1>& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const bool operator == (const Polynomial<T1>& pervii, const  T1& vtoroi);
    template <typename T1>
    friend const bool operator == (const T1& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const bool operator != (const Polynomial<T1>& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const bool operator != (const Polynomial<T1>& pervii, const T1& vtoroi);
    template <typename T1>
    friend const bool operator != (const T1& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator + ( const Polynomial<T1>& pervii,  const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator + (const Polynomial<T1>& pervii,  const T1& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator + (const T1& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator += (Polynomial<T1>& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator += (Polynomial<T1>& pervii,const T1& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator -= (Polynomial<T1>& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator -= (Polynomial<T1>& pervii,const T1& vtoroi);
    template <typename T1>
    friend const Polynomial<T1>& operator - (const Polynomial<T1>& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator - (const Polynomial<T1>& pervii,const T1& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator - (const T1& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator *= ( Polynomial<T1>& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator *= ( Polynomial<T1>& pervii,const T1& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator * (const Polynomial<T1>& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator * (const Polynomial<T1>& pervii,const T1& vtoroi);
    template <typename T1>
    friend const Polynomial<T1> operator * (const T1& pervii,const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend Polynomial<T1> operator & (const Polynomial<T1>& pervii, const Polynomial<T1>& vtoroi);
    template <typename T1>
    friend ostream& operator << (ostream& os, const Polynomial<T1>& vtoroi);

private:
    void GetGood(){
        sort(pol.begin(),pol.end());
        for (int i = 0; i < pol.size()-1; ++i){
            if(pol.at(i).first == pol.at(i+1).first){
                pol.at(i).second = pol.at(i).second + pol.at(i+1).second;
                pol.erase(pol.begin()+i+1);
                --i;
            }
        }
        for (int i = 0; i < pol.size(); ++i){
            if(pol.at(i).second == 0){
                pol.erase(pol.begin()+i);
                --i;
            }
        }
    }
    vector<pair<int,T>> pol;
};

template <typename T>
const bool operator == (const Polynomial<T>& pervii, const Polynomial<T>& vtoroi){
    return pervii.pol == vtoroi.pol;
}

template <typename T>
const bool operator == (const Polynomial<T>& pervii,  const T& vtoroi){
    vector<pair<int,T>> qq;
    qq.push_back(make_pair(0,vtoroi));
    return pervii.pol == qq;
}

template <typename T>
const bool operator == (const T& pervii, const Polynomial<T>& vtoroi){
    vector<pair<int,T>> qq;
    qq.push_back(make_pair(0,pervii));
    return qq == vtoroi.pol;
}

template <typename T>
const bool operator != (const Polynomial<T>& pervii, const Polynomial<T>& vtoroi){
    return pervii.pol != vtoroi.pol;
}

template <typename T>
const bool operator != (const Polynomial<T>& pervii, const T& vtoroi){
    vector<pair<int,T>> qq;
    qq.push_back(make_pair(0,vtoroi));
    return pervii.pol != qq;
}

template <typename T>
const bool operator != (const T& pervii, const Polynomial<T>& vtoroi){
    vector<pair<int,T>> qq;
    qq.push_back(make_pair(0,pervii));
    return qq != vtoroi.pol;
}



template <typename T>
const Polynomial<T> operator + ( const Polynomial<T>& pervii,  const Polynomial<T>& vtoroi){
    Polynomial<T> next = pervii;
    for (int i = 0;i < vtoroi.pol.size(); ++i ){
        next.pol.push_back(vtoroi.pol.at(i));
    }

    next.GetGood();
    return next;
}

template <typename T>
const Polynomial<T> operator + (const Polynomial<T>& pervii, const T& vtoroi) {
    Polynomial<T> next = pervii;
    next.pol.push_back(make_pair(0, vtoroi));

    next.GetGood();
    return next;
}

template <typename T>
const Polynomial<T> operator + (const T& pervii, const Polynomial<T>& vtoroi){
    Polynomial<T> next = vtoroi;
    next.pol.push_back(make_pair(0, pervii));

    next.GetGood();
    return next;
}

template <typename T>
Polynomial<T> operator += ( Polynomial<T>& pervii,const Polynomial<T>& vtoroi){
    for (int i = 0;i < vtoroi.pol.size(); ++i ){
        pervii.pol.push_back(make_pair(vtoroi.pol.at(i).first, vtoroi.pol.at(i).second));
    }
    pervii.GetGood();
    return pervii;
}

template <typename T>
Polynomial<T> operator += (Polynomial<T>& pervii,const T& vtoroi){
    pervii.pol.push_back(make_pair(0, vtoroi));
    pervii.GetGood();
    return pervii;
}

template <typename T>
Polynomial<T> operator -= (Polynomial<T>& pervii,const Polynomial<T>& vtoroi){
    for (int i = 0;i < vtoroi.pol.size(); ++i ){
        pervii.pol.push_back(make_pair(vtoroi.pol.at(i).first, vtoroi.pol.at(i).second*-1));
    }
    pervii.GetGood();
    return pervii;
}

template <typename T>
Polynomial<T> operator -= (Polynomial<T>& pervii,const T& vtoroi){
    pervii.pol.push_back(make_pair(0, vtoroi*-1));
    pervii.GetGood();
    return pervii;
}

template <typename T>
const Polynomial<T>& operator - (const Polynomial<T>& pervii,const Polynomial<T>& vtoroi){
    Polynomial<T> next = pervii;
    for (int i = 0;i < vtoroi.pol.size(); ++i ){
        next.pol.push_back(make_pair(vtoroi.pol.at(i).first, vtoroi.pol.at(i).second*-1));
    }
    next.GetGood();
    Polynomial<T>* next_2 = new Polynomial<T>(next);
    return *next_2;
}

template <typename T>
const Polynomial<T> operator - (const Polynomial<T>& pervii,const T& vtoroi){
    Polynomial<T> next = pervii;
    next.pol.push_back(make_pair(0, vtoroi*-1));
    next.GetGood();
    return next;
}

template <typename T>
const Polynomial<T> operator - (const T& pervii,const Polynomial<T>& vtoroi){
    Polynomial<T> next = vtoroi;
    next.pol.push_back(make_pair(0, pervii*-1));
    next.GetGood();
    return next;
}

template <typename T>
Polynomial<T> operator *= ( Polynomial<T>& pervii, const Polynomial<T>& vtoroi){
    vector <pair <int,T>> pol_2;
    for(size_t i = 0; i < pervii.pol.size(); i++)
    {
        for(size_t j = 0; j < vtoroi.pol.size(); j++)
        {
            pol_2.push_back(make_pair(pervii.pol.at(i).first + vtoroi.pol.at(j).first, pervii.pol.at(i).second * vtoroi.pol.at(j).second));
        }
    }

    pervii.pol = pol_2;
    pervii.GetGood();
    return pervii;
}

template <typename T>
Polynomial<T> operator *= ( Polynomial<T>& pervii,const T& vtoroi){
    for (int i = 0; i < pervii.pol.size(); ++i){
        pervii.pol.at(i).second *= vtoroi;
    }
    pervii.GetGood();
    return pervii;
}

template <typename T>
const Polynomial<T> operator * (const Polynomial<T>& pervii,const Polynomial<T>& vtoroi){
    Polynomial<T> next;
    for(size_t i = 0; i < pervii.pol.size(); i++)
    {
        for(size_t j = 0; j < vtoroi.pol.size(); j++)
        {
            next.pol.push_back(make_pair(pervii.pol.at(i).first + vtoroi.pol.at(j).first, pervii.pol.at(i).second * vtoroi.pol.at(j).second));
        }
    }
    next.GetGood();
    return next;
}

template <typename T>
const Polynomial<T> operator * (const Polynomial<T>& pervii,const T& vtoroi){
    Polynomial<T> next;
    for(size_t i = 0; i < pervii.pol.size(); i++)
    {
        next.push_back(make_pair(pervii.pol.at(i).first, pervii.pol.at(i).second*vtoroi));
    }
    next.GetGood();
    return next;
}

template <typename T>
const Polynomial<T> operator * (const T& pervii,const Polynomial<T>& vtoroi){
    Polynomial<T> next;
    for(size_t i = 0; i < vtoroi.pol.size(); i++)
    {
        next.push_back(make_pair(vtoroi.pol.at(i).first, vtoroi.pol.at(i).second*pervii));
    }
    next.GetGood();
    return next;
}

template <typename T>
Polynomial<T> operator & (const Polynomial<T>& pervii, const Polynomial<T>& vtoroi){
    vector<pair<T,T>> kostil_ocherednoi = {{0, 1}};
    auto member = Polynomial<T>();
    member.pol = kostil_ocherednoi;
    for(int i = 0; i < pervii.pol.size(); i++){
        auto lol = Polynomial<T>();
        lol.pol = kostil_ocherednoi ;
        for(int j = 0; j < pervii.pol.at(i).first; j++){
            lol *= vtoroi;
        }
        member += lol * vtoroi.pol[i].second;
    }
    return member-1;
}
template <typename T>
ostream& operator << (ostream& os, const Polynomial<T>& vtoroi){
    if (!vtoroi.pol.empty()) {
        for (int i = (int)vtoroi.pol.size() - 1; i >= 0; --i) {
            if (vtoroi.pol.at(i).second < 0) {
                os << "-";
                if (abs(vtoroi.pol.at(i).second) != 1 && abs(vtoroi.pol.at(i).second) != 0 &&
                    vtoroi.pol.at(i).first != 1 && vtoroi.pol.at(i).first != 0) {
                    os << abs(vtoroi.pol.at(i).second) << "x^" << vtoroi.pol.at(i).first;
                } else if (abs(vtoroi.pol.at(i).second) != 1 && abs(vtoroi.pol.at(i).second) != 0 &&
                           vtoroi.pol.at(i).first == 0) {
                    os << abs(vtoroi.pol.at(i).second);
                } else if (abs(vtoroi.pol.at(i).second) != 1 && abs(vtoroi.pol.at(i).second) != 0 &&
                           vtoroi.pol.at(i).first == 1) {
                    os << abs(vtoroi.pol.at(i).second) << "x";
                } else if (abs(vtoroi.pol.at(i).second) == 1 && vtoroi.pol.at(i).first != 1 &&
                           vtoroi.pol.at(i).first != 0) {
                    os << "x^" << vtoroi.pol.at(i).first;
                } else if (abs(vtoroi.pol.at(i).second) == 1 && vtoroi.pol.at(i).first == 0) {
                    os << abs(vtoroi.pol.at(i).second);
                } else if (abs(vtoroi.pol.at(i).second) == 1 && vtoroi.pol.at(i).first == 1) {
                    os << "x";
                }
            }
            else {
                if (i != vtoroi.pol.size() - 1) {
                    os << "+";
                }
                if (vtoroi.pol.at(i).second != 1 && vtoroi.pol.at(i).second != 0 && vtoroi.pol.at(i).first != 1 &&
                    vtoroi.pol.at(i).first != 0) {
                    os << vtoroi.pol.at(i).second << "x^" << vtoroi.pol.at(i).first;
                } else if (vtoroi.pol.at(i).second != 1 && vtoroi.pol.at(i).second != 0 &&
                           vtoroi.pol.at(i).first == 0) {
                    os << vtoroi.pol.at(i).second;
                } else if (vtoroi.pol.at(i).second != 1 && vtoroi.pol.at(i).second != 0 &&
                           vtoroi.pol.at(i).first == 1) {
                    os << vtoroi.pol.at(i).second << "x";
                } else if (vtoroi.pol.at(i).second == 1 && vtoroi.pol.at(i).first != 1 && vtoroi.pol.at(i).first != 0) {
                    os << "x^" << vtoroi.pol.at(i).first;
                } else if (vtoroi.pol.at(i).second == 1 && vtoroi.pol.at(i).first == 0) {
                    os << vtoroi.pol.at(i).second;
                } else if (vtoroi.pol.at(i).second == 1 && vtoroi.pol.at(i).first == 1) {
                    os << "x";
                }
            }
        }
    }
    return os;
}

int main(){
    return 0;
};

