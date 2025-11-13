def hotel_booking_system(rooms, bookings):
     
    occupied = set(room for room, _, _ in bookings)
    available = [r for r in rooms if r not in occupied]
    costs = []
    for room, start, end in bookings:
        sd = datetime.fromisoformat(start)
        ed = datetime.fromisoformat(end)
        nights = (ed - sd).days
        if nights < 1:
            nights = 1
        cost = nights * rooms.get(room, 0)
        costs.append((room, nights, cost))
    total_cost = sum(c for _, _, c in costs)
    return total_cost, costs, occupied, available


def task14_demo():
    rooms = {"R1": 100, "R2": 80, "R3": 120}
    bookings = [("R1", "2025-10-10", "2025-10-12"), ("R3", "2025-10-11", "2025-10-14")]
    print("Task 14 — Hotel Booking Management")
    total_cost, costs, occupied, available = hotel_booking_system(rooms, bookings)
    print("Total cost for current bookings:", total_cost)
    print("Details:", costs)
    print("Occupied rooms:", occupied)
    print("Available rooms:", available)
    print()

task14_demo()