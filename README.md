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

## 📈 Enunciado

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
