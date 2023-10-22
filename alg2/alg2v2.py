def row_transition_count(row_number_array):
    count = 0
    px = None;
    for x in row_number_array:
        if px is not None and px != x:
            count += 1 
        px = x

    return count;

ifilename = "alg2-data.txt"

ifo = open(ifilename)
n_btn  = int(ifo.readline())
print("n_btn =", n_btn)
s_id = map(int, ifo.readline().split())
r_num = map(int, ifo.readline().split()) 

dict_id_num = dict(zip(s_id, r_num))
print(dict_id_num)

k_sym  = int(ifo.readline())
print(k_sym)

char_array = map(int, ifo.readline().split())
#print(list(char_array))

#row_number_array = (dict_id_num[x] for x in char_array)
row_number_array = map(dict_id_num.get, char_array)
#print(row_number_array)


print(row_transition_count(row_number_array))

