class Program: pass
class Student: pass

   
def init():
    filename = "data.txt"
    f = open(filename)

    prog_empty = Program()
    prog_empty.id = -1

    prog_list = [prog_empty]
    student_list = []
    sorted_student_list = []

    n, k = map(int, f.readline().split())
    print(n, k)

    pi = list(map(int, f.readline().split()))
    for i in range(1, k + 1):
        prog = Program()
        prog.id = i
        prog.place_num = pi[i - 1]
        prog_list.append(prog)

    for i in range(0, n):
        stud = Student()
        stud.id = i
        stud.rank, s, *desired_prog_id_list = map(int, f.readline().split())
        print(desired_prog_id_list)
        stud.desired_prog_list = map(prog_list.__getitem__, desired_prog_id_list)

        student_list.append(stud)

    f.close()
 
 # Здесь лямбда берет х (элемент из списка) и использует его поле rank для сорта
    sorted_student_list = sorted(student_list, key = lambda stud: stud.rank)
    
    return prog_list, student_list, sorted_student_list


def main():
    prog_list, student_list, sorted_student_list = init()

    for stud in sorted_student_list:
        print("Stud id", stud.id, "go to program", end=" ")

        for prog in stud.desired_prog_list:
            if prog.place_num > 0:
                print(prog.id, end=" ")
                stud.admitted_prog = prog
                prog.place_num -= 1
                break
        else:
            stud.admitted_prog = prog_list[0]

        print()

    print()
    print("Admitted students:")
    print(*(stud.admitted_prog.id for stud in student_list))

if __name__ == "__main__":
    main()
