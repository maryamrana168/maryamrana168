
def Counter(conditions):
    for weather in conditions:
         conditions=0
         conditions+=1
         return conditions


def weather_data_analyzer(temps_conditions):
 
    if not temps_conditions:
        return 0 
    temps = [t for _, t, _ in temps_conditions]
    avg_temp = sum(temps) / len(temps)
    hottest = max(temps_conditions, key=lambda x: x[1])
    conditions = [c for _, _, c in temps_conditions]
    most_common = Counter(conditions).most_common(1)[0]
    return avg_temp, hottest, most_common


def task10_demo():
    # 30 days sample (use a small sample here for demo)
    sample = [(i+1, random.uniform(20, 40), random.choice(["Sunny","Cloudy","Rain"])) for i in range(30)]
    avg, hottest, most_freq = weather_data_analyzer(sample)
    print("Task 10 — Weather Data Analyzer")
    print(f"Average temp: {avg:.2f}")
    print("Hottest day:", hottest)
    print("Most frequent condition:", most_freq)
    print()

task10_demo()
