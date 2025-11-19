#include <iostream>
#include "baseconversion.h"
#include "root_finders.cpp"
#include <string>

using namespace std;
/**
 * Jefter
 */

 //funcao que cria f com dado 'a'
function<double(double)> f_a(double a){
    return [a](double d){
        return a * d - d*log(d);
    };

}

vector<Result> lista_resultados(vector<int> A){ //vetor de results com a1...an-
    vector<Result> ans;
    for (auto i : A){
        int top = pow(3,i);
        function<double(double)> f = f_a(i);
        Result aux = bisection(f, 1,top,1.0e-5,100,false);
        ans.push_back(aux);
    }
    return ans;
}

vector<string> resultToString (Result x){
    vector<string> v;
    v.push_back (to_string(x.root));
    v.push_back (to_string(x.residual));
    v.push_back (to_string(x.error));
    v.push_back (to_string(x.interations)); 
}

vector<vector<string>> quadro_comparativo(double a){
    
}




int main(int argc, char** argv){


    
}