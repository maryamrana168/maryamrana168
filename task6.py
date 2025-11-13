def restaurant_billing(items, tax_rate=0.08, tip_percent=0.15):
     
    subtotal = sum(price for _, price in items)
    tax = subtotal * tax_rate
    tip = subtotal * tip_percent
    total = subtotal + tax + tip
    return {"subtotal": subtotal, "tax": tax, "tip": tip, "total": total}


def task6_demo():
    items = [("Pasta", 8.5), ("Salad", 4.0), ("Soda", 1.5)]
    print("Task 6 — Restaurant Billing System")
    bill = restaurant_billing(items, tax_rate=0.07, tip_percent=0.18)
    print(bill)
task6_demo()
