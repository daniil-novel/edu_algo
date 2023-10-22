from itertools import pairwise

def row_transition_count(row_number_array):
    return sum(1 for px, x in pairwise(row_number_array) if px != x)

def readline(ifo):
    return map(int, next(ifo).split())



ifilename = "alg2-data.txt"

ifo = open(ifilename)

n_btn = int(next(ifo))
print("n_btn =", n_btn)

s_id = readline(ifo)
r_num = readline(ifo)

dict_id_num = dict(zip(s_id, r_num))
print(dict_id_num)

k_sym  = int(next(ifo))
print(k_sym)

char_array = readline(ifo)
#print(list(char_array))

row_number_array = map(dict_id_num.get, char_array)
#print(row_number_array)

print(row_transition_count(row_number_array))

