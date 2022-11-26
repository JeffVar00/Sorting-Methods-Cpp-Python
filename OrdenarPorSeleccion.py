# from random import randint
# randint(1, 1000)

def sortSel(v):
    i = 0  # 1
    while i < len(v):  # n
        menor = i  # n
        j = i + 1  # n
        while j < len(v):  # n^n
            if v[j] < v[menor]:  # n^n
                menor = j  # n^n
            j += 1  # n^n
        auxiliar = v[i]  # n
        v[i] = v[menor]  # n
        v[menor] = auxiliar  # n
        i += 1  # n
        #  4n^n + 7n + 1  ==  O(n^n)


def sortSelRe(v, posI):
    if posI < len(v):
        posMin = buscarMin(v, posI)  # retorno la posicion del 1, que es 2
        aux = v[posI]  # 20
        v[posI] = v[posMin]  # 1
        v[posMin] = aux   # posMin = 2, el aux contenia al elemento intercambiado, se iguala a 20
        sortSelRe(v, posI + 1)


def buscarMin(v, posI):
    posMin = posI   # 0
    menor = v[posI]   # menor = 20
    j = posI + 1  # 1
    while j < len(v):
        if v[j] < menor:  #    11    1
            menor = v[j]
            posMin = j
        j += 1
    return posMin


def main():
    posI = 0
    v = [20, 11, 1, 3, 2, 6, 4, 8, 4, 0]
    print(v)
    # sortSel(v)
    sortSelRe(v, posI)
    # v.sort()
    # v2 = sorted(v)
    print(v)
    # print(v2)


if __name__ == '__main__':
    main()
