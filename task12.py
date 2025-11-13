def fitness_tracker(data):
     
    totals = {}
    avg_time = {}
    activity_types = set()
    for user, activities in data.items():
        total_cals = sum(a[2] for a in activities)
        totals[user] = total_cals
        avg_time[user] = (sum(a[1] for a in activities) / len(activities)) if activities else 0
        activity_types.update(a[0] for a in activities)
    return totals, avg_time, activity_types


def task12_demo():
    data = {
        "Alice": [("Run", 30, 300), ("Swim", 45, 400)],
        "Bob": [("Bike", 60, 600)],
    }
    print("Task 12 — Fitness Tracker")
    totals, avg_time, types = fitness_tracker(data)
    print("Total calories:", totals)
    print("Average workout time:", avg_time)
    print("Activity types:", types)
     

task12_demo()