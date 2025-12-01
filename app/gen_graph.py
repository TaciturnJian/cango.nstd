import re
from graphviz import Digraph
import os

def parse_dependencies(text):
    dependencies = {}

    header = ""
    for line in text.split('\n'):
        if line.startswith('['):
            header = line.replace('[', '').replace(']', '').replace('\\', '/').replace('//', '/').strip()
            dependencies[header] = []
            continue
        if line.startswith(' - '):
            dep = line.replace(' - ', '').replace('\\', '/').replace('//', '/').strip()
            dependencies[header].append(dep)
            continue

    return dependencies

def create_dependency_graph(dependencies):
    dot = Digraph(comment='Header File Dependencies', format='svg')
    dot.attr(rankdir='TB', size='8,6')

    all_headers = set(dependencies.keys())
    for deps in dependencies.values():
        all_headers.update(deps)

    for header in all_headers:
        dot.node(header, shape='box', style='filled', fillcolor='lightblue', fontname='Arial')

    for header, deps in dependencies.items():
        for dep in deps:
            dot.edge(header, dep, arrowhead='normal')

    return dot

def main():
    path = input("output.txt>> ")
    with open(path, "r") as file:
        text = file.read()

    dependencies = parse_dependencies(text)

    graph = create_dependency_graph(dependencies)
    graph.render('dependencies', view=True, cleanup=True)
    print("generated 'dependencies.svg'")

if __name__ == "__main__":
    main()
