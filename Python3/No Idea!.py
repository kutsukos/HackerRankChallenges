lenlist = input().split() #useless for now
myset = input().split()
likeset = set(input().split())
dislikeset = set(input().split())

happiness=0;
for item in myset:
    happiness+= item in likeset
    happiness-= item in dislikeset
print(happiness)