# Métodos Numéricos I - Raízes de Equações

Repositório criado para melhor gerenciamento dos códigos desenvolvidos para o primeiro trabalho de métodos numéricos no semestre 2025.2.

## ⚙️ Requisitos

- Linguagem de implementação: C++
- Sistema Operacional: Linux

OBS: Dependendo do formato que projetarmos o nosso sistema, podemos fazer uso de outras linguagens e frameworks (informação já sanada pelo professor).

## 🧩 Organização da Entrega

A entrega final deve conter:

| Item | Descrição | Pontos |
|------|------------|------|
| **Apresentação** | Slides contendo Introdução, Metodologia, Exemplos e Conclusão | 3.0 |
| **Código-fonte** | Implementações em C/C++ | 3.0 |
| **Executável** | Versão compilada (estática ou com dependências incluídas) | 4.0 |
| **Documentação** | (Opcional) Manual ou relatório técnico | 0.0 |

---

## 📅 Status do Projeto

| Etapa | Descrição | Status |
|-------|------------|--------|
| Estrutura inicial do repositório | Organização e README | 🔄 Em andamento |
| Implementação dos métodos | Códigos base em C++ | ⏳ A iniciar |
| Testes e validação numérica | Verificação de precisão e convergência | ⏳ A iniciar |
| Preparação da apresentação | Slides e relatório final | ⏳ A iniciar |

---

## 📈 Temas e Enunciados

### Tema 1 - Bissecção, Posição Falsa e Newton-Raphson

**Função:**
> f(d) = a·d – d·ln(d)

**Descrição:**
Modelagem do deslocamento da extremidade de um jato supersônico. O cálculo incorreto do deslocamento pode causar falhas catastróficas.

**Requisitos principais:**

- Implementar os métodos:
  - Bissecção
  - Posição Falsa
  - Newton-Raphson
- Testar com:
  - a = 1
  - Isolamento (2, 3)
  - ε = 10⁻⁵
- Gerar:
  - Tabelas de resultados por método
  - Comparativo de precisão e iterações por método
  - Análise da variação de `a`

**Dados de entrada:**
- n (número de jatos)
- a (de cada jato)
- ε (precisão)

**Dados de saída:**
- Quadros resposta (com d e erro para cada jato e método)
- Quadro comparativo

### Tema 2 -Newton-Raphson, Newton Modificado e Secante

**Função:**
> f(d) = a·eᵈ – 4·d²

**Descrição:**
Modelagem de oscilações sísmicas. O deslocamento excessivo (d > 0,7 m) representa risco de amplificação perigosa.  

**Requisitos principais:**

- Implementar os métodos:
  - Newton-Raphson
  - Newton Modificado
  - Secante
- Testar com:
  - a = 1
  - d₀ = 0,5  
  - ε = 10⁻⁴
- Gerar:
  - Tabelas de resultados por método
  - Quadro comparativo dos métodos 
  - Análise da variação de `a`

**Dados de entrada:**
- n (número de valores de a)
- a (para cada n)
- ε (precisão)

**Dados de saída:**
- Quadros resposta (com d e erro para cada a e método)
- Quadro comparativo

### Tema 3 - Newton-Raphson, Newton Modificado com FL e Derivada Numérica de polinômios 

**Função:**
> f(d) = a₃·d³ – 9·a₂·d + 3

**Descrição:**
Simulação da oscilação de uma corda elástica. O deslocamento excessivo (d > 0,3 cm) pode causar ruptura.  

**Requisitos principais:**

- Implementar os métodos:
  - Newton-Raphson
  - Método de Newton com FL (para evitar f'(xk) = 0)
  - Cálculo da derivada numérica de f(d)  
- Testar com:
  - a₃ = 1  
  - a₂ = 1  
  - d₀ = 0,5  
  - λ = 0,05  
  - ε = 0,001  
- Gerar:
  - Tabelas de resultados por método
  - Quadro comparativo dos métodos 
  - Análise da variação de a₃ e a₂

**Dados de entrada:**
- n (número de valores de a)
- a (para cada n)
- ε (precisão)

**Dados de saída:**
- Quadros resposta (com d e erro para cada a e método)
- Quadro comparativo
