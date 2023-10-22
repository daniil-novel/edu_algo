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

row_number_array = [dict_id_num[x] for x in char_array]
print(row_number_array)

count = 0
for i in range(1, len(row_number_array)):
    if row_number_array[i - 1] != row_number_array[i]:
        count = count + 1 
        print(f'row_number_array[{i-1}] = {row_number_array[i-1]} | row_number_array[{i}] = {row_number_array[i]} | i = {i} ')

print(count)

