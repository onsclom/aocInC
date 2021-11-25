from typing import TYPE_CHECKING

class Planet:
    def __init__(self):
        self.name=""
        self.orbitters = []

planetDict = {}

inputData = []
with open('day6-input.txt') as f:
    inputData = f.read().split('\n')

for part in inputData:
    # print(part)
    origin,orbitter = part.split(')')
    # print(origin)
    # print(orbitter)


    if origin in planetDict:
        originPlanet = planetDict[origin]
    else:
        planetDict[origin] = Planet()
        planetDict[origin].name = origin

    if orbitter in planetDict:
        orbitterPlanet = planetDict[orbitter]
    else:
        planetDict[orbitter] = Planet()
        planetDict[orbitter].name = orbitter
    
    # print(f"{planetDict[origin].name} is getting new orbitter")
    # print(f"{planetDict[origin].name} orbitter amount = {len(planetDict[origin].orbitters)}")
    # print(f"")
    planetDict[origin].orbitters.append(planetDict[orbitter])

# ok now we traverse from COM
def orbitCount(node, amount):
    # print(f"orbitCounting {node.name}")
    if len(node.orbitters)==0:
        return amount
    total = amount
    for planet in node.orbitters:
        total += orbitCount(planet, amount+1)
    return total

print( orbitCount( planetDict["COM"], 0 ) )