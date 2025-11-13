def online_quiz_evaluator(results, pass_score=50):
    """
    results: dict student -> (score, time_taken_seconds)
    Returns average_score, highest_scorer, passed_students list
    """
    if not results:
        return 0, None, []
    avg = sum(score for score, _ in results.values()) / len(results)
    highest = max(results.items(), key=lambda x: x[1][0])
    passed = [s for s, (score, _) in results.items() if score >= pass_score]
    return avg, highest, passed


def task13_demo():
    results = {
        "Alice": (85, 180),
        "Bob": (45, 200),
        "Cathy": (92, 160),
    }
    print("Task 13 — Online Quiz Evaluator")
    avg, highest, passed = online_quiz_evaluator(results, pass_score=50)
    print("Average:", avg)
    print("Highest scorer:", highest)
    print("Passed students:", passed)
    
task13_demo()