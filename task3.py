 
def student_performance_report(students_marks):
     averages = {}
     for student, marks in students_marks.items():
        if marks:
            avg = sum(marks.values()) / len(marks)
        else:
            avg = 0
        averages[student] = avg
        top3 = sorted(averages.items(), key=lambda x: x[1], reverse=True)[:3]
        return averages, top3


def task3_demo():
    students = {
        "Alice": {"Math": 90, "Eng": 85, "Sci": 92},
        "Bob": {"Math": 78, "Eng": 82, "Sci": 74},
        "Cathy": {"Math": 95, "Eng": 88, "Sci": 91},
        "Dan": {"Math": 65, "Eng": 70, "Sci": 68},
    }
    avgs, top3 = student_performance_report(students)
    print("Task 3 — Student Performance Report")
    print("Averages:")
    print(avgs)
    print("Top 3:", top3)
task3_demo()
