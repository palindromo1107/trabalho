Aqui está uma apresentação sobre os tipos de gráficos da estatística descritiva, com exemplos em dados agrupados e não agrupados, utilizando a linguagem R e planilhas eletrônicas, seguindo as regras da ABNT:

*Slide 1: Introdução*

- Título: "Gráficos Estatísticos: Uma Ferramenta Importante para Análise de Dados"
- Resumo: "Os gráficos estatísticos são uma forma eficaz de visualizar e entender dados. Nesta apresentação, vamos explorar os diferentes tipos de gráficos e suas aplicações em exemplos práticos."

*Slide 2: Gráfico de Barras*

- Título: "Gráfico de Barras"
- Descrição: "O gráfico de barras é utilizado para comparar categorias ou grupos."
- Exemplo: "Vendas de produtos por região"
- Código em R:
library(ggplot2)
vendas <- data.frame(Regiao = c("Norte", "Sul", "Leste", "Oeste"),
                     Vendas = c(100, 200, 300, 400))
ggplot(vendas, aes(x = Regiao, y = Vendas)) + 
  geom_bar(stat = "identity")

- Imagem do gráfico

*Slide 3: Gráfico de Pizza*

- Título: "Gráfico de Pizza"
- Descrição: "O gráfico de pizza é utilizado para mostrar a proporção de categorias."
- Exemplo: "Distribuição de gênero em uma empresa"
- Código em R:
library(ggplot2)
genero <- data.frame(Genero = c("Masculino", "Feminino"),
                     Frequencia = c(60, 40))
ggplot(genero, aes(x = "", y = Frequencia, fill = Genero)) + 
  geom_bar(stat = "identity") + 
  coord_polar("y")

- Imagem do gráfico

*Slide 4: Histograma*

- Título: "Histograma"
- Descrição: "O histograma é utilizado para mostrar a distribuição de uma variável contínua."
- Exemplo: "Idade dos funcionários de uma empresa"
- Código em R:
library(ggplot2)
idade <- data.frame(Idade = rnorm(100, mean = 30, sd = 5))
ggplot(idade, aes(x = Idade)) + 
  geom_histogram(bins = 10, color = "black", fill = "lightblue")

- Imagem do gráfico

*Slide 5: Gráfico de Dispersão*

- Título: "Gráfico de Dispersão"
- Descrição: "O gráfico de dispersão é utilizado para mostrar a relação entre duas variáveis contínuas."
- Exemplo: "Relação entre horas trabalhadas e salário"
- Código em R:
library(ggplot2)
trabalho <- data.frame(Horas = rnorm(100, mean = 40, sd = 5),
                       Salario = rnorm(100, mean = 5000, sd = 1000))
ggplot(trabalho, aes(x = Horas, y = Salario)) + 
  geom_point()

- Imagem do gráfico

*Slide 6: Gráfico de Caixa*

- Título: "Gráfico de Caixa"
- Descrição: "O gráfico de caixa é utilizado para mostrar a distribuição de uma variável contínua e detectar outliers."
- Exemplo: "Salários de funcionários por departamento"
- Código em R:
library(ggplot2)
salario <- data.frame(Departamento = c(rep("Vendas", 100), rep("Marketing", 100)),
                      Salario = c(rnorm(100, mean = 4000, sd = 500), rnorm(100, mean = 5000, sd = 500)))
ggplot(salario, aes(x = Departamento, y = Salario)) + 
  geom_boxplot()

- Imagem do gráfico

*Slide 7: Conclusão*

- Título: "Conclusão"
- Resumo: "Os gráficos estatísticos são uma ferramenta importante para análise de dados. Cada tipo de gráfico tem sua própria aplicação e pode ser utilizado para mostrar diferentes aspectos dos dados."

*Referências*

- ABNT NBR 14724:2011 - Informação e documentação - Trabalhos acadêmicos - Apresentação.
- R Core Team (2022). R: A language and environment for statistical computing. R Foundation for Statistical Computing, Vienna, Austria.

Espero que isso ajude! Lembre-se de personalizar os exemplos e seguir as regras da ABNT.