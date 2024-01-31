i = int(input())
while i:
  a,b = [int(j) for j in input().split()]
  if a>b: print(">")
  elif a < b : print("<")
  else: print("=")
  i-=1

class Prof:
    def __init__(self, name, can_teach):
        self.name = name
        self.teaching = ["0"]*(4*4+3)
        self.can_teach = can_teach

    def isDispo(self, n_seance):
        return self.teaching[n_seance] == "0"
        
    def addSeance(self, id, n_seance):
        if(self.isDispo(n_seance)) :
            self.teaching[n_seance] = id
            print("Addition Successful")
            return True
        else :
            print("full")
            return False
    
    def getClasses(self):
        print(f"name : {self.name}")
        for i, id in enumerate(self.teaching):
            if(id=="0") : continue
            print(f"{i} {id}")

    def __str__(self) -> str:
        return self.name

class Section:
    def __init__(self, name, must_study):
        self.name = name
        self.teaching = ["0"]*(4*4+3)
        self.must_study = must_study
        self.still = must_study.copy()

    def isDispo(self, n_seance):
        return self.teaching[n_seance] == "0"
        
    def addSeance(self, id, n_seance):
        if(self.isDispo(n_seance) and id in self.still.keys()) :
            self.teaching[n_seance] = id
            self.still[id]-=1
            if(self.still[id]==0) : self.still.pop(id)
            print("Addition Successful")
            return True
        else :
            print("full")
            return False
    
    def getClasses(self):
        print(f"name : {self.name}")
        for i, id in enumerate(self.teaching):
            if(id=="0") : continue
            print(f"{i} {id}")

    def __str__(self) -> str:
        return self.name

    def getMustStudy(self):
        print("\nMUST STUDY")
        print(self.name)
        for i, j in self.still.items():
            if(j==0) : continue
            print(f"{i}  : {j}")
        return self.still


# prof = Prof("yojos", ["API_12", "API_21"])
# print(prof)
# prof.addSeance("API_12", 1)
# prof.getClasses()
# prof.addSeance("API_21", 2)
# prof.getClasses()

# profs = [
#     ["laarbi", ["API_31","API_32","TOPI"]],
#     ["lmajdooub", ["API_31", "API_33"]]
# ]

# profsIns = [Prof(p[0], p[1]) for p in profs]

# section = Section("S3", {"API_31":2, "API_32":1, "API_33":1})


# while section.getMustStudy():
#     section.getClasses()

#     seance = list(section.getMustStudy().keys())[0]
#     found = False
#     for prof in profsIns:
#         if found : break
#         if( seance in prof.can_teach):
#             for i in range(0, 4*4+3):
#                 if found : break
#                 if(prof.isDispo(i) and section.isDispo(i)):
#                     prof.addSeance(seance , i)
#                     section.addSeance(seance, i)
#                     found= True

# section.getClasses()




"""

    section : 
        2 sopi
        2

"""