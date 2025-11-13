import math
def delivery_path_analyzer(points):
     
    if not points:
        return None 
    start = points[0][0]
    end = points[-1][0]
    total_distance = sum(p[2] for p in points)
    return start, end, total_distance


def task1_demo():
    points = [
        ("Warehouse", "09:00", 0),
        ("Point A", "09:25", 5.5),
        ("Point B", "09:50", 3.2),
        ("Point C", "10:20", 7.1),
    ]
    start,end,total_distance = delivery_path_analyzer(points)
    print("Task 1 — Delivery Path Analyzer")
    print("Start:", start)
    print("End:", end)
    print("Total distance:", total_distance, "km")
task1_demo()

