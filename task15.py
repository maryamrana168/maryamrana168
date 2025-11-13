def expense_budget_tracker(expenses, budgets):
    totals = dict(float)
    largest = (None, None, 0)  # (date, category, amount)
    for date, cat, amt in expenses:
        totals[cat] += amt
        if amt > largest[2]:
            largest = (date, cat, amt)
    exceeded = {cat: totals.get(cat, 0) > budgets.get(cat, float('inf')) for cat in budgets}
    return dict(totals), exceeded, largest


def task15_demo():
    expenses = [
        ("2025-10-01", "Food", 12.5),
        ("2025-10-02", "Transport", 5.0),
        ("2025-10-02", "Food", 20.0),
    ]
    budgets = {"Food": 30.0, "Transport": 50.0}
    totals, exceeded, largest = expense_budget_tracker(expenses, budgets)
    print("Task 15 — Expense & Budget Tracker")
    print("Totals:", totals)
    print("Exceeded budgets:", exceeded)
    print("Largest expense:", largest)
     
task15_demo()