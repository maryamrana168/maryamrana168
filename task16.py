class SmartBusinessManager:
    def __init__(self):
         
        self.transactions = []

    def add_transaction(self, date, ttype, amount, category, note=""):
        
        if ttype not in ("expense", "income"):
            raise ValueError("ttype must be 'expense' or 'income'")
        self.transactions.append({
            "date": date,
            "type": ttype,
            "amount": float(amount),
            "category": category,
            "note": note
        })

    def total_summary(self):
         
        totals = dict(float)
        for t in self.transactions:
            key = (t['category'], t['type'])
            totals[key] += t['amount']
        return dict(totals)

    def highest_expense(self):
        expenses = [t for t in self.transactions if t['type'] == 'expense']
        if not expenses:
            return None
        highest = max(expenses, key=lambda x: x['amount'])
        return highest

    def generate_report(self):
        totals = self.total_summary()
        highest = self.highest_expense()
    
        lines = []
        lines.append("SMART BUSINESS MANAGER REPORT")
        lines.append(f"Total transactions: {len(self.transactions)}")
        lines.append("Totals by (category, type):")
        for k, v in totals.items():
            lines.append(f"  {k}: {v:.2f}")
        if highest:
            lines.append("Highest expense:")
            lines.append(f"  Date: {highest['date']}, Category: {highest['category']}, Amount: {highest['amount']:.2f}, Note: {highest['note']}")
        else:
            lines.append("No expenses recorded.")
        return "\n".join(lines)

    def export_transactions(self):
         
        return list(self.transactions)


def task16_demo():
    print("Task 16 — Smart Business Manager (Integrated)")
    sb = SmartBusinessManager()
    sb.add_transaction("2025-10-01", "income", 2000, "Sales", "Online")
    sb.add_transaction("2025-10-02", "expense", 150, "Supplies", "Stationery")
    sb.add_transaction("2025-10-03", "expense", 500, "Rent", "Office rent")
    sb.add_transaction("2025-10-04", "income", 800, "Services", "Consulting")
    print(sb.generate_report())
task16_demo()


