""" 
Tipos de data em python: int, float, chr, str, tuple, list, range, bool, dict
"""


from bibliotecas.biblio import *
# alo()     #importando funções do arquivo biblio em bibliotecas para este


""" num = int(input('Digite um num natural: '));

centena = 0;
dezena = 0;
unidade = 0;

if(num//100 != 0):
    centena = num//100;
    num = num - centena*100;

if(num//10 != 0):
    dezena = num//10;
    num = num - dezena*10;

if(num != 0):
    unidade = num;

print(centena, 'centenas,', dezena,'dezenas,', unidade,'unidades'); """



""" #importando algumas funções apenas

from math import pi
from math import sin

x = sin(pi)
print("%d" %x)

#ou importando com outra nomenclatura

import math as m

x = m.sin(m.pi / 2);
print("%d" %x); 

# além disso podemos importar desta maneira

from math import *
# deste modo todas as funções são importadas sem precisarem ser referenciadas

x = sin(pi/2); print("%d" %x); """


""" import random as r
lista = ['alo', 1, 'bla', 2, 6.7];
print(r.choice(lista)); #escolhe um elemento de uma sequência
print(r.randint(0, 100)); #retorna um inteiro dentro de um intervalo, os pontos inicial e final estão na sequência
print(r.uniform(0, 5)); #retorna um real dentro do intervalo
print(r.randrange(0, 101, 2)); #escolhe um inteiro dentro do range de intervalos e passo definidos, nesse caso serão os pares """


""" lista = [] 
for i in range(5):
    lista += input('Digite listas: ') #adicionando listas a uma lista"""   

""" lista2 = []
for j in range(5):
    lista2 += [input('Digite elementos: ')] #adicionando elementos a uma lista(pode usar o append)"""   


""" array = [3, 1, 2, 2]
array.sort()  #ordena os elementos
print(len(array))   #printa o tamanho da lista(qtd de elementos)
array.remove('2')   #remove o elemento desejado da lista
array.reverse()     #inverte a ordem da lista( 1, 2, 3 -> 3, 2, 1)
#dá para verificar todos esse módulos e funções relacionadas a listas colocando o '.' dps dela """


""" array = [2, 2, 2, 2, 2, 1 , 2, 3, 2]; #vou retirar todos os dois em excesso, deixando um apenas

while array.count(2) != 1:
    array.remove(2);

array.sort();
print(array); """


""" vetor = [1, 5, 3, 2, 5];
vetor.pop(1); #retira o elemento do vetor que está na posição 1, segunda posição e retorna o elemento retirado
print(vetor.index(3)); #retorna o index, posição, do elemento no vetor, ao menos o primeiro deles
#em index podemos tbm determinar o início e a parada com em range
print(vetor);
vetor.insert(1, 5); #inserindo o 5 novamente na posição 1, não altera nenhum dos outros valores
print(vetor);

vetor_copia = []
vetor_copia = vetor.copy(); #copiando vetor para vetor_copia
print(vetor_copia);
vetor.clear(); #limpa todos os elementos da lista
print(vetor);
print(vetor_copia);

#cópia é diferente de uma atribuição, isso pq na cópia os endereços das listas são
#diferentes, apenas os valores em cada endereço q foram copiados, n os endereços

lista = [1, 2, 3];
copia = lista;
copia2 = lista.copy();
print(copia, copia2);

lista.clear();
print(copia);
print(copia2);
#os valores em lista foram limpos, com isso os de copia tbm, pois os endereços estão ligados """


""" #ordenando palavras por ordem alfabetica

palavra = "bla"
palavra2 = "blo"
lista = []
lista += [palavra2]
lista += [palavra]
print(lista)
lista.sort()
print(lista) """


""" #lista do nums pares até o 100
lista = list(range(0, 101, 2)); # transforma o tipo de data range em tipo lista
print(lista); """

""" def funn(n1, n2): #definindo funções
    return n1*2, n2*2 #retorno da função, pode n retornar nada

a = funn(int(input('')), int(input(''))); # a será uma tupla, pois recebe dois valores
print(a); 

#tuplas diferentemente de listas não podem ter seus elementos alterados
#podemos ter tuplas dentro de listas e o contrário
#posso usar tuplas para armazenar mais de um valor a uma variável
#e assim usar os valores armzenados pelos seus index's
print(a[0], a[1]) """


""" #coisa interessante de tuplas
b = (1, 2); x, y = b; #pode colcocar os () -> (x, y)
print(b, x, y)
b = (); x = 10; y = 5;
b = x, y; print(b, x, y) #pode colcocar os () -> (x, y) """


""" #tipo de data tuple
a = tuple([1, 20]); #converte o tipo list para tuple
print(a);
b = list(a);
print(b);

#slice de tuplas e listas
a += 1, 2, 3, 4
b += 1, 2, 3, 4
print(a[2:5], b[2:4]) #printa uma subtupla e sublista  q vai de um range(2, 5) e (2, 4) 
#os módulos de listas index e count servem para as tuplas"""


""" #gerando uma matriz 4x4 através de valores aleatórios, sem repetições
import random as r

mat = [];
nums_escolhidos = [];
c = 0;
for i in range(4):
    linha = [];
    for j in range(4):
        c = 0;
        while(not c):
            num = r.randint(0, 15);
            if(nums_escolhidos.count(num) == 0):
                linha += [num];
                nums_escolhidos += [num];
                c = 1;
    mat += [linha];

for k in range(4):
    print(mat[k]); """

""" def fat(valor): #função recursiva, fatorial de um valor
    if(valor == 1):
        return 1;
    else:
        return valor * fat(valor - 1);
alo = fat(5);
print(alo); """


""" a = chr(97); #transforma um int em um char
print(a);
b = ord(a); #transformar um char em um int
print(b); """
 

""" #módulos de strings
palavra = "ALO alo, jurema?";
alo = palavra.split(', '); #divide a string original em uma lista de substrings, as partes que estavam entre elas são apagdas, por padrão é ' '
alo2 = alo[0].split(); #dividindo novamente, o critério de divisão é o ' '
print(alo, alo2);
print(alo2[0].isupper(), alo2[1].isupper(), alo[0].islower(), alo[1].islower());#checa se há apenas letra minúsculas(islower), ou apenas maiúculas(isupper)
print(alo2[0].isalpha(), alo[1].isalpha()); #checa se todos os caracteres são letras do alfabeto, a '?' não, logo dá falso
print(palavra.lower()); #transforma todas as letras maiusculas em minusculas
print(palavra.upper()); #transforma todas as  ''    minusculas em maiusculas 
print(palavra.find('lo', 0, len(palavra))); #retorna a posição da primeira substring encontrada - O módulo index é idêntico, mas retorna erro se n achar nada"""


""" arq = open('teste.txt', 'w'); #igual a C, cria um arquivo ou sobresceve

arq.write('ALO ALO\n');

arq.close();

arq = open('teste.txt', 'r'); #também é igual, abre leitura arquivos já criados

print(arq.read());

arq.close();

arq = open('teste.txt', 'a'); #cria um arquivo ou continua a editar o existente

arq.write('teu cu\n');

arq.close(); 
#existem outros modos, mas esses são os principais, podemos adicionar '+' ou 'b' após os modos acima (+ -> vai poder ler e escrever, b -> trabalha com bytes)
"""


""" arq = open('Python/teste.txt', 'w');

arq.write('alo');
a = (arq.tell()); #armazena onde está o cursor dps de escrever 'alo\n'
arq.write('teu cu ''e sem fazer bico ''kenga');

arq.close();

arq = open('Python/teste.txt', 'r');

arq.seek(a); #vai começar a ler o arquivo dps da posição armazenada
for i in arq:   # i são as linhas do arquivo
    print(i);

arq.close(); """


""" nMat = {69 : 'Luan'}; #dicionarios são um novo tipo de data, aramazenam chaves e seus respectivos valores, 69 é a chave, Luan o valor
print(nMat[69]);
#para adicionar novas chaves basta fazer uma atribuição com a nova chave desejada dentro dos []
nMat[24] = 'Mateu';
print(nMat[24]);
#para saber se a chave está no dicionário, ou o valor, pode-se usar a função 'in'
print(69 in nMat);
print('Luan' in nMat.values()); #apenas nMat vai buscar a correspondência com base nas chaves, por isso o '.values()'
print(nMat.items()); #items serão ambas chaves e valores.
#dá para usar o 'for' para percorrer um dicionário
for num in nMat: #num será as chaves dentro do dicionário, para chaves tbm pode usar o '.keys()'
    print(num, nMat[num]);


#dá pra deletar chaves e seus valores
del nMat[24];
print(nMat);
#ou adicionar dicionários uns aos outros
dic = {35 : 'teu cu', 27 : 'antonha'};
for num in dic:
    nMat[num] = dic[num];
print(nMat); """


""" #algumas paradas a mais sobre funções
def alo(i = 0, *nums): #i é esta pré definida, quando o usuário n colocar nennhum valor i será 0, e nums um vetor vazio
    soma = 0;          #nums recebe quantos valores forem colocados como argumentos
    for j in nums:
        soma += j
    return i+soma;

print(alo()); #i=0 e nums=[]
print(alo(2, 97, 2, 2, 56)); """


""" class teucu:
    def __init__(self, n = '', m = 18): #é o método construtor da classe, define os atributos do objeto
        self.nome = n; self.idade = m;
        print('Construtor chamado com sucesso!!');
    def imprime(self):
        print(self.nome, self.idade);

alo = teucu('anderson'); # se n colocar argumentos o nome será uma string '' e a idade 18, por padrão
print(alo.nome, alo.idade);
alo.idade = 90; # mudando o atributo de idade
alo.imprime(); # chamando um método do objeto que faz a mesma coisa que a linha anterior """


""" class haha:
    def __init__(self, nome, peso, cao):
        self.nome = nome; self.peso = peso; self.cao = cao;
    def treinar_cao(self):
        self.cao.daPata();
        self.cao.latir();

class cachorro:
    def __init__(self, nome, cor_pelo):
        self.nome = nome; self.cor_pelo = cor_pelo;
    def daPata(self):
        print('%s levantou a pata!' %(self.nome));
    def latir(self):
        print('AU AU CARAIO');

rex = cachorro('Rex', 'preto'); luan = haha('Luan', 57, rex);
print(luan.nome, luan.peso, luan.cao.nome, luan.cao.cor_pelo);
luan.treinar_cao(); """


""" #cod para achar o ponto no centro de um retângulo, onde ponto e retângulo são obejetos de suas respectivas classes
class ponto:
    def __init__(self, x = 0, y = 0):
        self.x = x; self.y =y;
    def imprimePonto(self):
        print('valor em x = %g e valor em y = %g' %(self.x, self.y));
    
class retan:
    def __init__(self, comprimento = 0, altura = 0):
        self.comprimento = float(comprimento); self.altura = float(altura);
    def encontraCentro(self):
        return (self.comprimento)/2, (self.altura)/2;

flag = 0;
while(flag == 0):
    comprimento = float(input('Digite o comprimento do retângulo: ')); altura = float(input('Digite a alutra do retângulo: '));
    centro = ponto();
    retangulo = retan(comprimento, altura);
    centro.x, centro.y = retangulo.encontraCentro();
    centro.imprimePonto();

    if(int(input('Deseja encontrar o centro de outro retângulo? (caso não digite -1): ')) == -1):
        flag = 1; """


""" class classe_superior: #superclasse cujos objetos possuem dois atributos e um método
    __raiz = 'antepassados' # raiz é um atributo pertencente à classe, não aos objetos, os atributos dos objetos são definidos no construtor
                            # além disso é um atributo privado, por causa de '__' antes do nome da variável, atributos privados só existem dentro
                            # do escopo da classe, logo não conseguimos chamá-los fora, mesmo que eles estejam aqui
    def __init__(self, atr1, atr2):
        self.atr1 = atr1; self.atr2 = atr2;
    def func(self):
        print('funcaozinha')
    def principal(self):
        print('honrados sejam meus %s' %classe_superior.__raiz) # função de herança para todas subclasses desta
                                        # como __raiz é um atributo da classe, para chamá-lo temos que colocar desta maneira
    def secundaria(self):
        pass # secundaria é uma função que existe na superclasse, mas, por algum motivo decidimos n escrevê-la no momento,
             # então sobrescreveremos ela nas subclasses desta

class classe(classe_superior): #subclasse cujos objetos possuem três atributos e dois métodos
    def __init__(self, atr1, atr2, atr3):
        super(classe, self).__init__(atr1, atr2) # puxa o método contrutor da superclasse
        self.atr3 = atr3    # além disso os objetos da subclasse possuem

# em classe sobreescrevemos o método func, assim como o construtor, para adicionar algo excluisvo à subclasse
# quando o método é sobrescrito o que prevalece é o da própria subclasse, então para que possamos continuar com o conteúdo 
# do método func na classe_superior utilizamos a funçãozinha super
# a função super não precisa necessariamente de argumentos no python 3, então poderia ficar: super().__init__(atr1, atr2) acima
    def func(self):
        super().func()  # puxa o método func da superclasse
        print('mas na subclasse')   # e adiciona algo exclusivo da subclasse
    def func2(self):
        print('funcao exclusiva da subclasse')
    def secundaria(self):
        print('agora secundaria tem alguma utilidade')
    def __str__(self):
        return 'os atributos são em ordem: %s, %s, %s' %(self.atr1, self.atr2, self.atr3)
        # o método __str__ é um método especial que define uma string de retorno para ser printada, ou utilizada como uma string

obj = classe_superior(56, 'lmao')
obj_inf = classe(25, 'ksk', [1, 0, 0])

print(obj.atr1, obj.atr2)
obj.func()
print(obj_inf.atr1, obj_inf.atr2, obj_inf.atr3)
obj_inf.func(); obj_inf.func2();
obj.principal(); obj_inf.principal();
obj.secundaria(); obj_inf.secundaria();

print(obj_inf) # acontecerá o print do método __str__ """

""" flag = True
while flag:
    try:    
        x = int(input())
        print(x)
        flag = False
    except ValueError: # colocar o erro especificado é uma opção, mas se quisermos abrangir para qualquer tipo de excceção basta n colocar nada, apenas excpet
        print('tente novamente...')
# estrutura para trabalhar com erros possíveis, caso o usuário coloque algo q n pode ser transformado em int, strings por exemplo, há uma exceção(ValueError)
# outros tipos de erro são: FileNotFoundError, quando tentamos abrir um arquivo com 'r' que n existe, IndexError, quando utilizamos um índice fora do range de uma lista, tupla, etc... """


""" # teste de leitura de arquivo, algo q pode ler uma sequência de números q representam as posições de cada início das próximas 
    # linhas, independemente do que esteja em cada uma, um código que pode ajudar no caso de querer guardar informações em um txt
    # para usá-las novamente.
a  = open('Python/teste.txt', 'r')
g = a.readline()
g = g.split()
for ind in range(len(g)):
    g[ind] = int(g[ind])

pos = pos_ant = a.tell()    # guardando a posição da segunda linha
a.read() # indo para o final do arquivo
pos_final = a.tell()    # pegando o tamanho do arquivo, no final dele
a.seek(pos_ant) # voltando para a posição q estava antes

g = []; t = [];
while pos != pos_final:
    line = a.readline()
    g += [pos]
    t += [line]
    pos = a.tell()

print(t, g)

a.close()

a = open('Python/teste.txt', 'w')

for i in g:
    a.write('%d ' %i)
a.write('\n')
for j in t:
    a.write('%s' %j)

a.close() """


""" from struct import * # módulo que trabalha com as funções pack, unpack, encode e decode
a = open("Python/corno.bin", "wb");
nome = "luan"; y = [10, 50]
estru = pack("2f 4s", y[0], y[1], nome.encode()); # encode -> codifica nome para a forma de bytes, pack -> cria uma struct com 2 float e 4 chars
a.write(estru);

a.close();

a = open("Python/corno.bin", "rb");
caraio = a.readline();
caraio = unpack("2f 4s", caraio); # unpack -> desempacota a struct que escrevemos anteriormente, o formato deve ser o mesmo usado para a codificação
print(caraio);
print(caraio[2].decode());  # decode -> transforma a string em bytes para caracteres
a.close(); """


""" #funções em python são tratadas como objetos, portanto:
#conseguimos passar funções para variáveis que não são funções definidas

def hello(text):
    print(text)

hi = hello #passando o endereço da função hello, logo hi passará a fazer a mesma coisa q hello
hi("alo")

#consehuimos também passar retornar funções como argumentos

def divisor(x):
    def dividendo(y):
        return y / x
    return dividendo #retorna o endereço da função, onde x = ao valor recebido por divisor

bla = divisor(2) #bla será uma função dividendo, mas cujo x está definido para 2
print(bla(8)) """


"""#utilização da função lambda
multiplicação = lambda x, y:x*y #é uma forma de fazer uma função rápida com parâmetros(antes de :) e retorno(depois de :)
print(multiplicação(2, 2)) """


""" from tkinter import *

def clique():
    print(entrada_texto.get())

janela = Tk() #iniciando nossa janela
janela.geometry("820x450")  #dimensionando ela
janela.title("prog du lan") #dando um título

imagem = PhotoImage(file="puck_yoda.png")    #carregando uma imagem
label = Label(janela, text="prog du lan", font=("Arial", 15, "italic"),
             fg = "black", bg = "white", relief=RAISED, bd=5,
             padx=5, pady=5, image=imagem, compound="top")
#uma label é uma região onde colocamos texto ou imagens
#para defini-la colocamos a janela na qual estará e então podemos acrescentar diversos argumentos para personalizá-la
#text -> é o texto q será escrito na label, font -> fonte do texto
#fg -> cor do texto, bg -> cor de fundo da label, relief -> forma da borda da label(relevo), bd -> tamanho da borda
#padx -> distância horizontal da borda da label pro conteúdo, pady -> o mesmo para y
#image -> imagem a ser exibida na label, compound -> forma de exibição do texto junto com a imagem.

label.pack(side=RIGHT) # "printa" a label, outra opção é label.place() que leva os argumentos x e y para a posição da label

botao = Button(janela, text="clica ai poh",
                font=("Consolas", 15), image=imagem,
                compound="top", command=clique,
                fg = "black", bg="white", 
                activebackground= "white", activeforeground= "black",
                state=ACTIVE)
#activebackground é a cor do fundo do botão quando clicado e activeforeground a cor da letra clicada
#state é o "estado" do botão, pode ser disabled tbm, aí o botão n pode mais ser "clicado"

botao.pack(side=RIGHT) # "printa" o botao, pode usar place() tbm

#Entry são locais de entrada do texto do usuário
entrada_texto = Entry(janela, background="white", foreground="black",
                        font=("Consolas", 50))
entrada_texto.pack(side=LEFT)

janela.iconphoto(True, imagem)   #adicionando a imagem ao icone da janela

janela.config(background="white")   #configurando o fundo para cor preta

janela.mainloop()   #roda a janela """


""" #janela com delete, backspace e printar
from tkinter import *

def printar():
    print(entrada.get())

def apagar():
    entrada.delete((len(entrada.get()))-1, END)

def deletar():
    entrada.delete(0, END)

window = Tk()

entrada = Entry(window, font=("Consolas", 30), show="*")#mostra apenas "*", mas guarda o conteúdo original
entrada.pack(side=LEFT)

dele = Button(window, text="deletar", command=deletar)
dele.pack(side=RIGHT)
backs = Button(window, text="voltar", command=apagar)
backs.pack(side=RIGHT)
printed = Button(window, text="printar", command=printar)
printed.pack(side=RIGHT)

window.mainloop() """


""" #janela com botao de checklist
from tkinter import *

def checador():
    if (x.get()): #x.get() pega o valor da variavel x
        print("você concorda")
    else:
        print("você não concorda")

janela = Tk()

x = BooleanVar() #criando uma variavel booleana para ser utlizada nas condições do checkbutton

cheque = Checkbutton(janela, text="Você concorda com isto?\n",
                    font=("Consolas", 30),
                    variable=x, #variavel para as condições, poderia ser de outro tipo, junta das respostas, por exemplo int e respostas 0 e 1
                    onvalue=True, #valor de x para o checkbutton marcado
                    offvalue=False) #valor de x para o checkbutton não marcado
cheque.pack(side=LEFT)

bot = Button(janela, text="submit", command=checador)
bot.pack(side=RIGHT)

janela.mainloop() """


""" #cod com radiobuttons, botões checklits em grupo
from tkinter import *

def printar():
    print(opcao.get())

choices = ["escolha 1", "escolha 2", "escolha 3"]

janela = Tk()

opcao = IntVar()

for index in range(1, len(choices)+1):
    bot = Radiobutton(janela, text=choices[index-1], #pegando o texto das listas
                      variable=opcao, #variavel dos radiobuttons
                      value=index,  #valor assumido a cada clique
                      command=printar) 
    bot.pack(anchor="w") #anchor fixa o texto ao oeste, neste caso

janela.mainloop() """


""" #janela com escala
from tkinter import *

def submit():
    print("The temperature is:", scale.get(), "degrees C")
    if scale.get() == 100:
        print("too hot ma boy")
    elif scale.get() == 0:
        print("bru, fucking freezing")
    else:
        pass

window = Tk()

scale = Scale(window,
              from_=100, #max
              to=0, #min
              length=600,
              orient=VERTICAL, #orientation of scale
              font = ('Consolas',20),
              tickinterval = 10, #adds numeric indicators for value
              showvalue = 0, #hide current value
              resolution = 2, #increment of slider
              troughcolor = '#69EAFF', #slider color
              fg = '#FF1C00',
              bg = '#111111')
scale.set(0) #set current value of slider at 0 Cº
                            #((scale['from']-scale['to'])/2)+scale['to'] -> set at the middle
scale.pack()

button = Button(window,text='submit',command=submit)
button.pack()

window.mainloop() """


""" # listbox = A listing of selectable text items within it's own container

def submit():

    foods = []

    for index in listbox.curselection():
        foods += [listbox.get(index)]

    print("You have ordered: ")
    for food in foods:
        print(food)

def add():
    listbox.insert(listbox.size(),entryBox.get())
    listbox.config(height=listbox.size())

def delete():
    foods = list(listbox.curselection()) #transformando de uma tupla pra uma lista, que pode ser alterada
    foods.sort(reverse = True) #ordenando reversamente para que os últimos sejam os elementos de menores índices, para que
                               #não hajam mudanças nos index's durante o delete
    for food in foods:
        listbox.delete(food)

    listbox.config(height=listbox.size())

from tkinter import *

window = Tk()

listbox = Listbox(window,
                  bg="#f7ffde",
                  font=("Constantia",35),
                  width=12,
                  selectmode=MULTIPLE) #SINGLE para o caso de querer apenas uma seleção por vez
listbox.pack()

listbox.insert(1,"pizza") #elementos padrões
listbox.insert(2,"pasta")
listbox.insert(3,"garlic bread")
listbox.insert(4,"soup")
listbox.insert(5,"salad")

listbox.config(height=listbox.size()) #tamanho ajustável à quantidade de elementos

entryBox = Entry(window)
entryBox.pack()

frame = Frame(window) #local onde os botões ficarão
frame.pack()

submitButton = Button(frame,text="submit",command=submit)
submitButton.pack(side=LEFT)

addButton = Button(frame,text="add",command=add)
addButton.pack(side=LEFT)

deleteButton = Button(frame,text="delete",command=delete)
deleteButton.pack(side=LEFT)

window.mainloop() """


""" #janela que abre uma caixa de mensagem
from tkinter import *
from tkinter import messagebox #importa um módulo dentro de tkinter

def click():
    #mostra apenas uma caixa de informação com um "ok"
    #messagebox.showinfo(title='This is an info message box',message='You are a person')

    #mostra uma aviso
    #messagebox.showwarning(title='WARNING!',message='You have A VIRUS!!!!')

    #mostra um erro
    #messagebox.showerror(title='ERROR!',message='something went wrong :(')

    #mostra uma caixa com duas opções "ok" ou "cancel" que retorna verdadeiro ou falso
    #if messagebox.askokcancel(title='ask ok cancel',message='Do you want to do the thing?'):
        #print('You did a thing!')
    #else:
        #print('You canceled a thing! :(')

    #mostra uma caixa com duas opções "retry" ou "cancel" que retorna verdadeiro ou falso
    #if messagebox.askretrycancel(title='ask retry cancel',message='Do you want retry the thing?'):
        #print('You retried a thing!')
    #else:
        #print('You canceled a thing! :(')

    #mostra uma caixa com duas opções "ok" ou "cancel" que retorna verdadeiro ou falso
    #if messagebox.askyesno(title='ask yes or no',message='Do you like cake?'):
        #print('I like cake too :)')
    #else:
        #print('Why do you not like cake? :(')

    #mostra uma caixa com duas opções "yes" ou "no" que retorna "yes" ou "no"
    #answer = messagebox.askquestion(title='ask question',message='Do you like pie?')
    #if(answer == 'yes'):
        #print('I like pie too :)')
    #else:
        #print('Why do you not like pie? :(')

    #mostra uma caixa com 3 opções "yes", "no" ou "cancel" que retorna verdadeiro, falso ou none
    answer = messagebox.askyesnocancel(title=' Yes no cancel',message='Do you like to code?',icon='question')
    if(answer==True):
        print("You like to code :)")
    elif(answer==False):
        print("Then why are you watching a video on coding?")
    else:
        print("You have dodged the question ")

window = Tk()

button = Button(window,command=click,text='click me')
button.pack()

window.mainloop() """


""" #janela com seletor de cores do windows
from tkinter import *
from tkinter import colorchooser #importa um módulo dentro de tkinter

def click():
    color = colorchooser.askcolor() #assign color to a variable
    colorHex = color[1]         #assigns element at index 1 to a variable, the index 0 is the RGB value
    window.config(bg=colorHex) #change background color

window = Tk()
window.geometry("420x420")
button = Button(text='click me',command=click)
button.pack()
window.mainloop() """


""" #janela com área para digitação
from tkinter import *

def submit():
    input = text.get("1.0",END) #"1.0" -> index inicial, END -> final do texto
    print(input)

window = Tk()
text = Text(window,
            bg="light yellow",
            font=("Ink Free",25),
            height=8, #quantidade de linhas
            width=20, #quantidade de letras por linha
            padx=20,
            pady=20,
            fg="purple")
text.pack()
button = Button(window,text="submit",command=submit)
button.pack()
window.mainloop() """


""" #colocando widgets em um frame, mantendo-os unidos sempre em um espaço delimitado
from tkinter import *

window = Tk()

frame = Frame(window,bg="pink",bd=5,relief=SUNKEN)
frame.pack()

Button(frame,text="W",font=("Consolas",25),width=3).pack(side=TOP)
Button(frame,text="A",font=("Consolas",25),width=3).pack(side=LEFT)
Button(frame,text="S",font=("Consolas",25),width=3).pack(side=LEFT)
Button(frame,text="D",font=("Consolas",25),width=3).pack(side=LEFT)

window.mainloop() """


""" #janela que abre arquivos
from tkinter import *
from tkinter import filedialog

def openFile():
    filepath = filedialog.askopenfilename(initialdir="C:\\Users\\luang\\Documents", #diretório inicial
                                title="Open file okay?",
                                filetypes= (("text files","*.txt"), #podemos selecionar o tipo de arquivo a ser procurado
                                ("all files","*.*")))
    file = open(filepath,'r')
    print(file.read())
    file.close()

window = Tk()
button = Button(text="Open",command=openFile)
button.pack()
window.mainloop() """


"""#janela que salva algo em um arquivo 
from tkinter import *
from tkinter import filedialog

def saveFile():
    file = filedialog.asksaveasfile(initialdir="C:\\cod\\Python",
                                    defaultextension='.txt',
                                    filetypes=[
                                        ("Text file",".txt"),
                                        ("HTML file", ".html"),
                                        ("All files", ".*"),
                                    ])
    if file is None: #evita a excessão de quando não se salva nada
        return
    filetext = str(text.get(1.0,END))
    #filetext = input("Enter some text I guess: ") //use this if you want to use console window
    file.write(filetext)
    file.close()

window = Tk()
button = Button(text='save',command=saveFile)
button.pack()
text = Text(window)
text.pack()
window.mainloop() """


""" #janela com barra de menu
from tkinter import *

def openFile():
    print("File has been opened!")
def saveFile():
    print("File has been saved!")
def cut():
    print("You cut some text!")
def copy():
    print("You copied some text!")
def paste():
    print("You pasted some text!")

window = Tk()

menubar = Menu(window) #cria um barra de menu para a janela
window.config(menu=menubar) #coloca a barra de menu criada como menu da janela

#para lembrar o que é tearoff, retire ele
fileMenu = Menu(menubar,tearoff=0,font=("MV Boli",15)) #cria um uma nova barra de menu dentro da barra de menu principal
menubar.add_cascade(label="File",menu=fileMenu) #adiciona a menubar um novo menu(fileMenu) que abre como cascata
fileMenu.add_command(label="Open",command=openFile) #adicionando comandos ao submenu de file
fileMenu.add_command(label="Save",command=saveFile)
fileMenu.add_separator() #separador simples
fileMenu.add_command(label="Exit",command=quit)

editMenu = Menu(menubar,tearoff=0,font=("MV Boli",15)) #criando um novo submenu
menubar.add_cascade(label="Edit",menu=editMenu) #adicionando como cascata novamente
editMenu.add_command(label="Cut",command=cut) #adicionando comandos ao submenu de edit
editMenu.add_command(label="Copy",command=copy)
editMenu.add_command(label="Paste",command=paste)

window.mainloop() """


""" #criando novas janela
from tkinter import *

def create_window():
    new_window = Toplevel()       #Toplevel() = new window 'on top' of other windows, linked to a 'bottom' window
    #new_window = Tk()            #Tk() = new independent window
    #old_window.destroy()         #close out of old window, for creating with Tk

old_window = Tk()

Button(old_window,text="create new window",command=create_window).pack()

old_window.mainloop() """


""" #colocando as infos da janela com um comando diferente de place e pack, grid trabalha como uma matriz
from tkinter import *

window = Tk()
                                                        #columnspan faz o elemento ocupar 2 colunas, no caso do exemplo
titleLabel = Label(window,text="Enter your info",font=("Arial",25)).grid(row=0,column=0,columnspan=2)

firstNameLabel = Label(window,text="First name: ").grid(row=1,column=0)
firstNameEntry = Entry(window).grid(row=1,column=1)

lastNameLabel = Label(window,text="Last name: ").grid(row=2,column=0)
lastNameEntry = Entry(window).grid(row=2,column=1)

emailLabel = Label(window,text="email: ").grid(row=3,column=0)
emailEntry = Entry(window).grid(row=3,column=1)

submitButton = Button(window,text="Submit").grid(row=4,column=0,columnspan=2)

window.mainloop() """


""" from tkinter import *
from tkinter.ttk import *
import time

def start():
    GB = 100
    download = 0
    speed = 1
    bar["value"] = 0
    while(download<GB):
        time.sleep(0.05)
        bar['value']+=(speed/GB)*100
        download+=speed
        percent.set(str(int((download/GB)*100))+"%")
        text.set(str(download)+"/"+str(GB)+" GB completed")
        window.update_idletasks()

window = Tk()

percent = StringVar()
text = StringVar()

bar = Progressbar(window,orient=HORIZONTAL,length=300)
bar.pack(pady=10)

percentLabel = Label(window,textvariable=percent).pack()
taskLabel = Label(window,textvariable=text).pack()

button = Button(window,text="download",command=start).pack()

window.mainloop() """