class Component:
    def __init__(self, vertex):
        self.vertex_list = [vertex]

def merge(cmp1, cmp2):
    if cmp1 == cmp2:
        return cmp1
    
    cmp_dst, cmp_src = (cmp1, cmp2) if len(cmp1.vertex_list) > len(cmp2.vertex_list) else (cmp2, cmp1)
    
    lst_src = cmp_src.vertex_list
    lst_dst = cmp_dst.vertex_list
    lst_dst += lst_src

    set_vertex_list_component(lst_src, cmp_dst)

    return cmp_dst

class Vertex:
    def __init__(self, ii):
        self.index = ii
        self.component = Component(self)

    def __repr__(self):
        return str(self.index) + " | " + str(self.component)
    
def ask(u, v):
    return u.component == v.component

def add_edge(u, v):
    cmpU, cmpV = u.component, v.component
    print(cmpU.vertex_list)
    print(cmpV.vertex_list)
    cmp = merge(cmpU, cmpV)
    print(cmp.vertex_list)
    print("-------------------")

class Command:
    def __init__(self, name, ui, vi):
        self.name = name
        self.ui = int(ui)
        self.vi = int(vi)

    def __repr__(self):
        return self.name + " " + str(self.ui) + " -> " + str(self.vi)

def print_list(lst):
    print(*lst, sep = "\n")

def set_vertex_list_component(lst, cmp):
    for v in lst:
        v.component = cmp

def command_init():
    filename = "data.txt"
    fin = open(filename, 'r')
    n_vertex, m_edge, k_operation = map(int, fin.readline().split())
    print(n_vertex, m_edge, k_operation)
    
    for _ in range(m_edge):
        ui, vi = map(int, fin.readline().split())
    
    commands = []
    for _ in range(k_operation):
        cmd = Command(*fin.readline().split())
        commands.append(cmd)

    fin.close()
    commands.reverse()
    return commands

def vertex_init(n_vertex):
    return [Vertex(vi) for vi in range(n_vertex + 1)]

def execute(reversed_commandlist, vertex_list):
    anslst = []
    for cmd in reversed_commandlist:
        u, v = vertex_list[cmd.ui], vertex_list[cmd.vi]
        if cmd.name == "cut":
            add_edge(u, v)
        else:
            anslst.append("YES\n" if ask(u, v) else "NO\n")
    
    return reversed(anslst)

if __name__ == "__main__":
    reversed_commandlist = command_init()
    print_list(reversed_commandlist)

    vertex_list = vertex_init(reversed_commandlist[0].ui)
    answerlist = execute(reversed_commandlist, vertex_list)
    print_list(answerlist)

