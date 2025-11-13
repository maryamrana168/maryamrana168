def Counter(books):
    for book in books:
        author=0
        author+=1

def library_catalog_system(books):
     
    author_count = Counter(books)
    for book in books:
        title, author, category = book
        author_count[author] += 1
    if author_count:
        top_author = author_count.most_common(1)[0]
    else:
        top_author = None
    return dict(author_count), top_author


def task8_demo():
    books = [
        ("The A", "Author1", "Fiction"),
        ("The B", "Author2", "Sci"),
        ("The C", "Author1", "Fiction"),
        ("The D", "Author3", "History"),
        ("The E", "Author1", "Sci"),
    ]
    print("Task 8 — Library Catalog System")
    author_count, top_author = library_catalog_system(books)
    print("Books per author:", author_count)
    print("Author with most books:", top_author)
    
task8_demo()

