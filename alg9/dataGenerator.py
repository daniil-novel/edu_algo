from random import choice, randint, random, shuffle

n_employee_max = 10
n_employee_min = 2

nfile_begin = 3
nfile_end = 9

def DFS(f, n_person):
    person_stack = []
    child_count_stack = []
    free_person = 0

    while stack or free_person == 0:
        if :
            person = person_stack.pop()
            child_count_stack.pop()
        else:
            person_stack.append(free_person)
            person = free_person
            free_person += 1 

            if person != 0:
                child_count_stack[-1] += 1
            child_count_stack.append(0)

        print(person, file = f, end = " ")

        


for f in range(nfile_begin, nfile_end + 1):
    filename = f"data{f}.txt"
    f = open(filename, "w")

    n_employee = randint(n_employee_min, n_employee_max)
    print(n_employee, file = f)

    for _ in range(n_employee):
        print(choice("AB"), file = f, end = " ")
    print(file = f)
    
    n_person = n_employee + 1;
    DFS(f, n_person)

    f.close()
        
