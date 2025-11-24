#include "root_finders.cpp"
#include <iomanip>

using namespace std;

/*

- fa retorna a função dada de acordo com o valor de 'a', dfa retorna a derivada de fa.

- os métodos com '2' no final são adaptações dos métodos originais, seja adicionando um critério de parada que não
tinha ou só tirando o bool responsável pelos prints

- os métodos com 'results' no fim do nome retornam o Results, mas são principalmente uma modificação dos métodos com '2' no fim
nos quais recebem um vetor nos argumentos e adiciona os resultados de cada iteração nesse vetor

- resultToString transforma Result em string

*/

vector<string> resultToString (Result x){
    vector<string> v;
    v.push_back (to_string(x.root));
    v.push_back (to_string(x.residual));
    v.push_back (to_string(x.error));
    v.push_back (to_string(x.interations)); 

    return v;
}

function<double(double)> fa(double a){
    return [a](double d){
        return a*d - d*log(d);
    };

}

function<double(double)> dfa(double a){
    return [a](double d){
        return a - log(d) - 1;
    };

}

Result bisection_results(const function<double(double)>& f, double a, double b, double epsilon, int max_inter, vector<vector<string>>& results){
    double x;
    // Checagem se o intervalo fornecido é válido
    if(f(a) * f(b) >= 0){
        throw invalid_argument("Intervalo inválido: f(a) e f(b) possuem o mesmo sinal!");
    }
    for(int k = 0; k <= max_inter; k++){
        x = 0.5 * (a+b);
        if((b - a) < epsilon){
            results.push_back(resultToString({x, k, true, abs(f(x)), abs(b-a)}));
            return {x, k, true, abs(f(x)), abs(b-a)};
        }
        results.push_back(resultToString({x, k, false, abs(f(x)), abs(b-a)}));

        // Escolha dos extremos do intervalo da próxima interação
        if(f(x) * f(a) > 0){
            // se f(x) e f(a) possuem o mesmo sinal
            a = x;
            
        }else{
            b = x;
        }
    }

    results.push_back(resultToString({x, max_inter, false, abs(f(x)), abs(b-a)}));
    return {x, max_inter, false, abs(f(x)), abs(b-a)};
}

Result false_position_results(const function<double(double)>& f, double a, double b, double epsilon, int max_inter, vector<vector<string>>& results){
    double x;
    // Checagem se o intervalo fornecido é válido
    if(f(a) * f(b) >= 0){
        throw invalid_argument("Intervalo inválido: f(a) e f(b) possuem o mesmo sinal!");
    }
    for(int k = 0; k <= max_inter; k++){
        x = (a*f(b) - b*f(a))/(f(b) - f(a));
        
        // Checa qual condição de parada atinge primeiro
        if(abs(f(x)) < epsilon){
            results.push_back(resultToString({x,k,true,f(x),abs(f(x))}));
            return {x, k, true, f(x), abs(f(x))};
        }else if(abs(b-a) < epsilon){
            results.push_back(resultToString({x,k,true,f(x),abs(b-a)}));
            return {x, k, true, f(x), abs(b-a)};
        }

        // Salva no vetor os dados da iteração atual
        if(abs(f(x)) < abs(b-a)){
            results.push_back(resultToString({x,k,false,f(x),abs(f(x))}));
        }else{
            results.push_back(resultToString({x,k,false,f(x),abs(b-a)}));
        }
        
        // Escolha dos extremos do intervalo da próxima interação
        if(f(x) * f(a) > 0){
            // se f(x) e f(a) possuem o mesmo sinal
            a = x;
        }else{
            b = x;
        }
    }
    // Compara qual erro é menor
    if(abs(f(x)) < abs(b-a)){
            results.push_back(resultToString({x,max_inter,false,f(x),abs(f(x))}));
            return {x, max_inter, false, f(x), abs(f(x))};
        }else{
            results.push_back(resultToString({x,max_inter,false,f(x),abs(b-a)}));
            return {x, max_inter, false, f(x), abs(b-a)};
        }
}

Result newton_raphson_results(const function<double(double)>& f, const function<double(double)>& df, double x0, double epsilon, int max_inter, vector<vector<string>>& results){
    double x;
    if (abs(f(x0)) < epsilon){
        results.push_back(resultToString({x0, 0, true, f(x0), abs(f(x0))}));
        return {x0, 0, true, f(x0), abs(f(x0))};
    }
    results.push_back(resultToString({x0, 0, false, f(x0), abs(f(x0))}));
    for(int k = 1; k <= max_inter; k++){
        x = x0 - f(x0)/df(x0); // xk = xk-1 - f(xk-1)/f'(xk-1)
        // Verificação de qual critério de parada usar
        if(abs(f(x)) < epsilon){
            results.push_back(resultToString({x, k, true, f(x), abs(f(x))}));
            return {x, k, true, f(x), abs(f(x))};
        }else if(abs(x - x0) < epsilon){
            results.push_back(resultToString({x, k, true, f(x), abs(x - x0)}));
            return {x, k, true, f(x), abs(x - x0)};
        }

        if(abs(x-x0) < f(x)){
            results.push_back(resultToString({x, k, false, f(x), abs(x-x0)}));
        }else{
            results.push_back(resultToString({x, k, false, f(x), abs(f(x))}));
        }

        x0 = x;
    }

    if(abs(x-x0) < f(x)){
        results.push_back(resultToString({x, max_inter, false, f(x), abs(x-x0)}));
        return {x, max_inter, false, f(x), abs(x-x0)};
    }else{
        results.push_back(resultToString({x, max_inter, false, f(x), abs(f(x))}));
        return {x, max_inter, false, f(x), abs(f(x))};
    }
}

Result bisection_2(const function<double(double)>& f, double a, double b, double epsilon, int max_inter){
    double x;
    // Checagem se o intervalo fornecido é válido
    if(f(a) * f(b) >= 0){
        throw invalid_argument("Intervalo inválido: f(a) e f(b) possuem o mesmo sinal!");
    }
    for(int k = 0; k <= max_inter; k++){
        x = 0.5 * (a+b);
        if((b - a) < epsilon){
            return {x, k, true, abs(f(x)), abs(b-a)};
        }
        // Escolha dos extremos do intervalo da próxima interação
        if(f(x) * f(a) > 0){
            // se f(x) e f(a) possuem o mesmo sinal
            a = x;
            
        }else{
            b = x;
        }
    }
    return {x, max_inter, false, abs(f(x)), abs(b-a)};
}

Result false_position_2(const function<double(double)>& f, double a, double b, double epsilon, int max_inter){
    double x;
    // Checagem se o intervalo fornecido é válido
    if(f(a) * f(b) >= 0){
        throw invalid_argument("Intervalo inválido: f(a) e f(b) possuem o mesmo sinal!");
    }
    for(int k = 0; k <= max_inter; k++){
        x = (a*f(b) - b*f(a))/(f(b) - f(a));
        
        // Checa qual condição de parada atinge primeiro
        if(abs(f(x)) < epsilon){
            return {x, k, true, f(x), abs(f(x))};
        }else if(abs(b-a) < epsilon){
            return {x, k, true, f(x), abs(b-a)};
        }
        
        // Escolha dos extremos do intervalo da próxima interação
        if(f(x) * f(a) > 0){
            // se f(x) e f(a) possuem o mesmo sinal
            a = x;
        }else{
            b = x;
        }
    }
    if(abs(f(x)) < abs(b-a)){
            return {x, max_inter, false, f(x), abs(f(x))};
        }else{
            return {x, max_inter, false, f(x), abs(b-a)};
        }
}

Result newton_raphson_2(const function<double(double)>& f, const function<double(double)>& df, double x0, double epsilon, int max_inter){
    double x;
    if (abs(f(x0)) < epsilon){
        return {x0, 0, true, f(x), abs(f(x0))};
    }
    for(int k = 1; k <= max_inter; k++){
        x = x0 - f(x0)/df(x0); // xk = xk-1 - f(xk-1)/f'(xk-1)
        // Verificação de qual critério de parada usar
        if(abs(f(x)) < epsilon){
            return {x, k, true, f(x), abs(f(x))};
        }else if(abs(x - x0) < epsilon){
            return {x, k, true, f(x), abs(x - x0)};
        }

        x0 = x;
    }

    if(abs(x-x0) < f(x)){
        return {x, max_inter, false, f(x), abs(x-x0)};
    }else{
        return {x, max_inter, false, f(x), abs(f(x))};
    }
}

vector<vector<string>> quadro_resposta(int n, int option){
    vector<vector<string>> V;
    vector<string> v;
    Result a_n;

    if(option == 1){
        for(int i = 1; i <= n; ++i){
            a_n = bisection_2(fa(i),pow(2,i),pow(3,i),pow(10,-5),50);
            v = resultToString(a_n);
            V.push_back(v);
        }
    }else if(option == 2){
        for(int i = 1; i <= n; ++i){
            a_n = false_position_2(fa(i),pow(2,i),pow(3,i),pow(10,-5),50);
            v = resultToString(a_n);
            V.push_back(v);
        }
    }else if(option == 3){
        for(int i = 1; i <= n; ++i){
            a_n = newton_raphson_2(fa(i),dfa(i),pow(2.5,i),pow(10,-5),50);
            v = resultToString(a_n);
            V.push_back(v);
        }
    }

    return V;
}

vector<vector<string>> quadro_comparativo(){
    vector<vector<string>> V;
    vector<string> vb, vfp, vnr;

    vb.push_back("[2,3]");
    vfp.push_back("[2,3]");
    vnr.push_back("x0 = 2.5");

    for(int i = 0; i < 4; ++i){
        vb.push_back(resultToString(bisection_2(fa(1), 2, 3, pow(10,-5), 100))[i]);
        vfp.push_back(resultToString(false_position_2(fa(1), 2, 3, pow(10,-5), 100))[i]);
        vnr.push_back(resultToString(newton_raphson_2(fa(1), dfa(1), 2.5, pow(10,-5), 100))[i]);
    }

    V.push_back(vb);
    V.push_back(vfp);
    V.push_back(vnr);

    return V;
}

int main(){
    cout<<fixed<<setprecision(60);

    // Teste item D
    /*vector <vector<string>> Resultados;
    Result x = newton_raphson_results(fa(1),dfa(1),pow(2.5,1),pow(10,-5),30,Resultados);

    for(int i = 0; i < Resultados.size();++i){
        cout<<"iteração: "<<Resultados[i][3]<<"\n";
        cout<<"x: "<<Resultados[i][0]<<"\n";
        cout<<"f(x): "<<Resultados[i][1]<<"\n";
        cout<<"erro: "<<Resultados[i][2]<<"\n";
        cout<<"================\n\n";
    }

    x = newton_raphson(fa(1),dfa(1),pow(2.5,1),pow(10,-5),30,true);*/

    // Teste item E
    /*vector<vector<string>> V = quadro_resposta(20,1);

    for(int i=0; i< V.size(); ++i){
        cout<<"a"<<i+1<<":\n";
        for(int j = 0; j<4; ++j){
            cout<<V[i][j]<<"\n";
        }
        cout<<"\n";
    }*/

    // Teste item F
    /*vector<vector<string>> V = quadro_comparativo();

    for(int i = 0; i < 3; ++i){
        switch(i){
            case 0:
                cout<< "Método da Bisseção\n";
                break;
            case 1:
                cout<< "Método da Posição Falsa\n";
                break;
            case 2:
                cout<< "Método de Newton-Raphson\n";
                break;
        }

        cout << "Dados Iniciais: " << V[i][0] << "\n";
        cout << "Raiz Encontrada(x'): " << V[i][1] << "\n";
        cout << "f(x'): " << V[i][2] << "\n";
        cout << "Erro: " << V[i][3] << "\n";
        cout << "Iterações: " << V[i][4] << "\n\n";
    }*/
}