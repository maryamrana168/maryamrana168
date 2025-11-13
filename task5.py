def friendship_network_analysis(network):
    
    users = list(network.keys())
    mutual = {}
    unique = {}
    suggestions = {}
    for i, u in enumerate(users):
        for v in users[i+1:]:
            mutual[(u, v)] = network[u] & network[v]
            unique[(u, v)] = (network[u] ^ network[v])  
    for u in users:
         
        foaf = set()
        for f in network[u]:
            foaf.update(network.get(f, set()))
        foaf -= network[u]
        foaf.discard(u)
        suggestions[u] = foaf
    return mutual, unique, suggestions


def task5_demo():
    net = {
        "Alice": {"Bob", "Cathy"},
        "Bob": {"Alice", "Dan", "Eve"},
        "Cathy": {"Alice", "Eve"},
        "Dan": {"Bob"},
        "Eve": {"Bob", "Cathy"},
    }
    mutual, unique, suggestions = friendship_network_analysis(net)
    print("Task 5 — Friendship Network Analysis")
    print("Mutual friends:")
    print(mutual)
    print("Unique connections:")
    print(unique)
    print("Suggestions:")
    print(suggestions)

task5_demo()
    