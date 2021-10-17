lines = []
with open('annotation_val.json') as f:
    lines = f.readlines()

f = open("annotation.json", "w")

count = 0
for line in lines:
    f.write(line)
    f.write(",")

      