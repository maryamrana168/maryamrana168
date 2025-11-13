def email_data_processor(emails):
     
    valid = []
    invalid = []
    domains=count()
     
    for e in emails:
         
        if e.count('@') == 1:
            local, domain = e.split('@')
            if local and domain and '.' in domain and not domain.startswith('.') and not domain.endswith('.'):
                valid.append(e)
                domain[domain] += 1
            else:
                invalid.append(e)
        else:
            invalid.append(e)
    return valid, invalid, dict(domains)


def task4_demo():
    emails = [
        "alice@example.com", "bob@mail.co", "bademail@", "@nodomain.com",
        "cathy@sub.domain.org", "dave@domain", "eve@example.com"
    ]
    valid, invalid, domain_counts = email_data_processor(emails)
    print("Task 4 — Email Data Processor")
    print("Valid:", valid)
    print("Invalid:", invalid)
    print("Domain counts:", domain_counts)
    print()
task4_demo()
