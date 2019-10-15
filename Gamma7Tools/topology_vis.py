# Requires Python >==3.7

import networkx as nx
import matplotlib.pyplot as plt
import xml.etree.ElementTree as ET 

TOP_FILE = "../Ref/Top/RefTopologyAppAi.xml"
IGNORE_LIST = ["eventLogger", "linuxTime", "textLogger", "chanTlm", "health"]
#IGNORE_LIST = []

tree = ET.parse(TOP_FILE) 

root = tree.getroot() 

#Get Components
components = []
for item in root.findall("instance"):
    if item.tag == "instance" and item.attrib["name"] not in IGNORE_LIST:
        components.append(item.attrib["name"])

#print(components)

#Get Connections
connections = []
for connection in root.findall("connection"):
    group = [connection.find("source").attrib["component"], connection.find("target").attrib["component"]]
    if group[0] not in IGNORE_LIST and group[1] not in IGNORE_LIST:
        connections.append(group)

#print(connections)


#Graph
graph = nx.Graph()

for component in components:
    graph.add_node(component)

for connection in connections:
    graph.add_edge(connection[0], connection[1])


pos = nx.circular_layout(graph)
nx.draw(graph, pos, font_size=16, with_labels=False)
for p in pos:  # raise text positions
    if pos[p][0] > 0:
        pos[p][0] += 0.05
    else: 
        pos[p][0] -= 0.05
    
    if pos[p][1] > 0:
        pos[p][1] += 0.05
    else: 
        pos[p][1] -= 0.05
nx.draw_networkx_labels(graph, pos)
plt.show()
