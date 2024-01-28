n_vertex = 0

class Component(list):
    def __init__(self, vertex):
        self.append(vertex)

    def __repr__(self):
        s = ""
        for v in self:
            s += str(v) + " | " + hex(id(v.component)) + ", "
        return s

    @staticmethod
    def merge(cmp1, cmp2):
        if cmp1 is cmp2:
            return cmp1
        
        cmp_dst, cmp_src = (cmp1, cmp2) if len(cmp1) > len(cmp2) else (cmp2, cmp1)
        
        cmp_dst += cmp_src

        Vertex.set_vertex_list_component(cmp_src, cmp_dst)

        return cmp_dst

class Vertex:
    def __init__(self, ii):
        self.index = ii
        self.component = Component(self)

    def __repr__(self):
        return str(self.index)

    @staticmethod
    def add_edge(u, v):
        cmpU, cmpV = u.component, v.component
#        print(cmpU)
#        print(cmpV)
        cmp = Component.merge(cmpU, cmpV)
#        print(cmp)
#        print("-------------------")
    
    @staticmethod
    def ask(u, v):
        return u.component == v.component

    @staticmethod
    def set_vertex_list_component(lst, cmp):
        for v in lst:
            v.component = cmp

class Command:
    def __init__(self, name, ui, vi):
        self.name = name
        self.ui = int(ui)
        self.vi = int(vi)

    def __repr__(self):
        return self.name + " " + str(self.ui) + " -> " + str(self.vi)


def print_list(lst):
    print(*lst, sep = "\n")


def command_init():
    global n_vertex

    filename = "data8.txt"
    fin = open(filename, 'r')
    n_vertex, m_edge, k_operation = map(int, fin.readline().split())
#    print(n_vertex, m_edge, k_operation)
    
    for _ in range(m_edge):
        ui, vi = map(int, fin.readline().split())
    
    commands = []
    for _ in range(k_operation):
        cmd = Command(*fin.readline().split())
        commands.append(cmd)

    fin.close()
    commands.reverse()
    return commands

def vertex_init():
    return [Vertex(vi) for vi in range(n_vertex + 1)]

def execute(reversed_commandlist, vertex_list):
    anslst = []
    for cmd in reversed_commandlist:
        u, v = vertex_list[cmd.ui], vertex_list[cmd.vi]
        if cmd.name == "cut":
            Vertex.add_edge(u, v)
        else:
            anslst.append("YES" if Vertex.ask(u, v) else "NO")
    
    return reversed(anslst)

if __name__ == "__main__":
    reversed_commandlist = command_init()
#    print_list(reversed_commandlist)

    vertex_list = vertex_init()

    answerlist = execute(reversed_commandlist, vertex_list)
    print_list(answerlist)

