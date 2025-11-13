def transport_schedule_tracker(stops):
 
    if len(stops) < 2:
        return None, 0, len(stops)
    # Convert times to minutes
    times = []
    for name, tstr, dist in stops:
        h, m = map(int, tstr.split(":"))
        times.append(h * 60 + m)
    # segments: compute duration and average speed (distance delta / time delta)
    fastest_segment = None
    fastest_speed = -1
    for i in range(1, len(stops)):
        dist_delta = stops[i][2] - stops[i-1][2]
        time_delta = times[i] - times[i-1]
        if time_delta <= 0:
            continue
        speed = dist_delta / (time_delta / 60.0)  # km / hour
        if speed > fastest_speed:
            fastest_speed = speed
            fastest_segment = (stops[i-1][0], stops[i][0], speed)
    total_time = times[-1] - times[0]
    return fastest_segment, total_time, len(stops)


def task7_demo():
    stops = [
        ("Start", "08:00", 0.0),
        ("A", "08:15", 5.0),
        ("B", "08:30", 12.0),
        ("C", "09:00", 20.0),
    ]
    print("Task 7 — Transport Schedule Tracker")
    fastest, total_time, total_stops = transport_schedule_tracker(stops)
    print("Fastest segment (from, to, km/h):", fastest)
    print("Total route time (minutes):", total_time)
    print("Total stops:", total_stops)
task7_demo()   

