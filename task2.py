def shopping_cart_system():
    
    cart = {}

    def add_item(name, qty, price):
        if name in cart:
            cart[name]['qty'] += qty
        else:
            cart[name] = {'qty': qty, 'price': price}

    def remove_item(name):
        cart.pop(name, None)

    def update_item(name, qty=None, price=None):
        if name in cart:
            if qty is not None:
                cart[name]['qty'] = qty
            if price is not None:
                cart[name]['price'] = price

    def total_and_most_expensive():
        total = sum(v['qty'] * v['price'] for v in cart.values())
        if not cart:
            return total, None
        most_expensive = max(cart.items(), key=lambda x: x[1]['price'])
        return total, (most_expensive[0], most_expensive[1]['price'])

    return cart, add_item, remove_item, update_item, total_and_most_expensive


def task2_demo():
    cart, add, remove, update, summary = shopping_cart_system()
    add("Apple", 3, 0.5)
    add("Bread", 2, 1.2)
    add("Milk", 1, 0.99)
    update("Apple", price=0.55)
    remove("Milk")
    add("Steak", 1, 10.0)
    total, most_exp = summary()
    print("Task 2 — Shopping Cart Management")
    print("Cart contents:", cart)
    print("Total price:", total)
    print("Most expensive item:", most_exp)
task2_demo()
