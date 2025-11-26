traffic_logs = [
"id:501,zone:A1,vehicle:Car,speed:62,time:08:30,violations:[None],status:Smooth",
"id:502,zone:A1,vehicle:Bike,speed:85,time:09:10,violations:['Helmet'],status:Busy",
"id:503,zone:B2,vehicle:Bus,speed:45,time:17:25,violations:[None],status:Smooth",
"id:504,zone:C3,vehicle:Car,speed:110,time:14:15,violations:['Overspeed'],status:Congested",
"id:505,zone:A1,vehicle:Truck,speed:40,time:18:50,violations:[None],status:Smooth"
]

data =[]
for log in traffic_logs:
    parts=log.split(",")
    entry={}
    for p in parts:
        key,value=p.split(":",1)
        if key=="speed":
           value=int(value)
        if key =="violations":
           value=value.strip("[]")
        entry[key]=value
        data.append(entry)
print (data)

zone_speed = {}

for d in data:
    zone = d["zone"]
    zone_speed.setdefault(zone, []).append(d["speed"])

avg_speed = {}
for z in zone_speed:
    avg_speed[z] = sum(zone_speed[z]) / len(zone_speed[z])

print(avg_speed)

hours = []
for d in data:
    h = d["time"].split(":")[0]
    hours.append(h)

peak_hour = max(set(hours), key=hours.count)
print("Peak Hour:", peak_hour)

fast = []
for d in data:
    if d["speed"] > 80:
        fast.append(d)

print(fast)


violation_count = {}
for d in data:
    for v in d["violations"]:
        violation_count[v] = violation_count.get(v, 0) + 1

print(violation_count)


safety_index = {}
for z in avg_speed:
    safety_index[z] = 100 - avg_speed[z]

print(safety_index)

vehicle_summary = {}
for d in data:
    v = d["vehicle"]
    vehicle_summary.setdefault(v, {"count": 0, "avg_speed": 0})
    vehicle_summary[v]["count"] += 1

for v in vehicle_summary:
    speeds = [d["speed"] for d in data if d["vehicle"] == v]
    vehicle_summary[v]["avg_speed"] = sum(speeds) / len(speeds)

print(vehicle_summary)


high_congestion = []
for d in data:
    if d["status"] == "Congested":
        high_congestion.append(d["zone"])

print(high_congestion)



def classify_time(t):
    h = int(t.split(":")[0])
    if 5 <= h < 12: return "Morning"
    if 12 <= h < 17: return "Afternoon"
    if 17 <= h < 21: return "Evening"
    return "Night"

for d in data:
    d["time_window"] = classify_time(d["time"])

for d in data:
    print(d)

 
zone_report = {}

for d in data:
    z = d["zone"]
    if z not in zone_report:
        zone_report[z] = {"vehicles": 0, "speeds": [], "violations": [], "types": []}
    
    zone_report[z]["vehicles"] += 1
    zone_report[z]["speeds"].append(d["speed"])
    zone_report[z]["violations"].append(d["violations"])
    zone_report[z]["types"].append(d["vehicle"])


# Step 3: Finalize report
final_report = {}

for z in zone_report:
    speeds = zone_report[z]["speeds"]
    types = zone_report[z]["types"]
    
    avg_speed = sum(speeds) / len(speeds)
    common_type = max(set(types), key=types.count)
    safety = "Safe" if avg_speed < 70 else "Unsafe"
    
    final_report[z] = {
        "total_vehicles": zone_report[z]["vehicles"],
        "avg_speed": avg_speed,
        "violations": zone_report[z]["violations"],
        "common_vehicle_type": common_type,
        "safety": safety
    }


for z in final_report:
    print(f"Zone {z}: {final_report[z]}")
