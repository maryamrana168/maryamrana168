def employee_attendance_system(attendance_records, work_days_count):
     
    percentages = {}
    for emp, days in attendance_records.items():
        percent = (len(days) / work_days_count) * 100
        percentages[emp] = percent
    perfect = [emp for emp, pct in percentages.items() if pct == 100.0]
    most_absent = sorted(percentages.items(), key=lambda x: x[1])[0] if percentages else (None, None)
    return perfect, most_absent, percentages


def task11_demo():
    # sample: days 1..30
    records = {
        "Alice": set(range(1, 31)),
        "Bob": set(range(1, 28)),
        "Cathy": set(range(2, 31)),
        "Dan": set(range(1, 16)),
    }
    print("Task 11 — Employee Attendance System")
    perfect, most_absent, percentages = employee_attendance_system(records, 30)
    print("Perfect attendance:", perfect)
    print("Most absences (lowest %):", most_absent)
    print("Percentages:")
    print(percentages)
     

task11_demo()